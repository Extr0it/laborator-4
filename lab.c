/*
==========================================================
   Controlul vitezei unui motor de curent continuu (DC)
   folosind un semnal PWM controlat cu 2 butoane.
   Microcontroler: PIC16F18446
   Semnal PWM pe pinul RC5
   Buton CREȘTERE: RA0
   Buton SCĂDERE: RA1
   Pasul de modificare este de 10% (0% - 100%)
   Autor: ChatGPT (GPT-5)
==========================================================
*/

#include <xc.h>

// Frecvența oscilatorului intern a microcontrolerului
#define _XTAL_FREQ 4000000UL   // 4 MHz

// -------------------------------------------------------
//      CONFIGURAREA REGISTRILOR (Configuration Bits)
// -------------------------------------------------------
#pragma config FEXTOSC = OFF    // Nu folosim oscilator extern
#pragma config RSTOSC = HFINT1  // Oscilator intern de mare frecv. la 1 MHz
#pragma config CLKOUTEN = OFF   // Dezactivare ieșire de clock
#pragma config CSWEN = OFF      // Fără posibilitate de schimbare a clock-ului
#pragma config FCMEN = OFF      // Monitorizarea fail clock dezactivată

#pragma config MCLRE = ON       // Pinul MCLR este activ
#pragma config PWRTS = PWRT_OFF // Power-up timer dezactivat
#pragma config WDTE = OFF       // Watchdog Timer dezactivat
#pragma config BOREN = OFF      // Brown-out Reset dezactivat
#pragma config LVP = OFF        // Programare pe tensiune joasă dezactivată

// -------------------------------------------------------
//      DECLARARE FUNCTII
// -------------------------------------------------------
void GPIO_Init(void);       // Inițializare pini (intrări/ieșiri)
void PWM_Init(void);        // Inițializare și configurare PWM
void SetDuty(unsigned char procent);  // Setare procent de semnal PWM

// Variabilă globală care stochează nivelul PWM în procente (0%-100%)
unsigned char pwm_procent = 0;


// -------------------------------------------------------
//      PROGRAM PRINCIPAL
// -------------------------------------------------------
void main(void)
{
    GPIO_Init();     // Setare pini pentru butoane și PWM
    PWM_Init();      // Configurare PWM la ~20 kHz
    SetDuty(pwm_procent);   // Pornire cu 0% PWM (motor oprit)

    while(1)
    {
        // Dacă se apasă butonul UP (RA0) → creștem viteza
        if(RA0 == 0)       // Buton activ pe nivel LOW (0V)
        {
            if(pwm_procent < 100) 
                pwm_procent += 10;  // Creștem cu 10%

            SetDuty(pwm_procent);
            __delay_ms(250);   // Mică pauză să evităm detecții multiple (debounce)
        }

        // Dacă se apasă butonul DOWN (RA1) → scădem viteza
        if(RA1 == 0)
        {
            if(pwm_procent > 0) 
                pwm_procent -= 10;   // Scădem cu 10%

            SetDuty(pwm_procent);
            __delay_ms(250);   // Pauză pentru evitarea bounce-ului
        }
    }
}


// -------------------------------------------------------
//      INIȚIALIZARE PINI (GPIO)
// -------------------------------------------------------
void GPIO_Init(void)
{
    // Butoane → intrări (RA0 și RA1)
    TRISA0 = 1;     // Setăm RA0 ca intrare
    TRISA1 = 1;     // Setăm RA1 ca intrare
    WPUA0 = 1;      // Activăm rezistența de pull-up pe RA0
    WPUA1 = 1;      // Activăm rezistența de pull-up pe RA1
    OPTION_REGbits.nWPUEN = 0; // Permitem weak pull-up-urile global

    // Pinul RC5 → ieșire PWM către driver motor
    TRISC5 = 0;     // Setăm RC5 ca ieșire
}


// -------------------------------------------------------
//      INIȚIALIZARE PWM
// -------------------------------------------------------
void PWM_Init(void)
{
    // Activăm funcția PWM6 pe pinul RC5 (PPS = Peripheral Pin Select)
    PPSLOCK = 0x55; PPSLOCK = 0xAA; // Deblocăm PPS
    RC5PPS = 0x0C;                  // RC5 = ieșire PWM6
    PPSLOCK = 0x55; PPSLOCK = 0xAA; // Blocăm PPS

    // Selectăm Timer2 pentru PWM și setăm frecvența
    T2CLKCON = 0x01;    // Sursa de clock = Fosc/4
    T2CON = 0x04;       // Timer2 activat, prescaler 1:1
    PR2 = 49;           // Valoare PR2 → frecvență PWM ~20kHz

    // Configurare modul PWM (activ high, pornit)
    PWM6CON = 0xC0;     // Enable PWM6, active-high
}


// -------------------------------------------------------
//      SETARE PROCENT PWM (0% - 100%)
// -------------------------------------------------------
void SetDuty(unsigned char procent)
{
    // Convertim procentul (0-100) într-o valoare între 0-400
    unsigned int valoare_pwm = (procent * 4);

    // Registrul PWM este pe 10 biți → împărțim în 2 bucăți (sus și jos)
    PWM6DCH = valoare_pwm >> 2;     // Octetul superior (8 biți)
    PWM6DCL = valoare_pwm << 6;     // Restul de 2 biți în DCL
}