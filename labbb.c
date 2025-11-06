#include <xc.h>

#define _XTAL_FREQ 4000000UL   // Internal oscillator frequency (4MHz)

// ---------------- CONFIGURATION BITS ----------------
#pragma config FEXTOSC = OFF    // No external oscillator
#pragma config RSTOSC = HFINT1  // High Frequency Internal Oscillator (1 MHz)
#pragma config CLKOUTEN = OFF   // CLKOUT function disabled
#pragma config CSWEN = OFF      // Clock switching disabled
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor disabled

#pragma config MCLRE = ON       // MCLR pin enabled
#pragma config PWRTS = PWRT_OFF // Power-up timer disabled
#pragma config WDTE = OFF       // Watchdog Timer disabled
#pragma config BOREN = OFF      // Brown-out Reset disabled
#pragma config LVP = OFF        // Low-voltage programming disabled

// ---------------- FUNCTION PROTOTYPES ----------------
void GPIO_Init(void);
void PWM_Init(void);
void SetPWM(unsigned char percent);

// Global variable for PWM duty cycle (0 to 100%)
unsigned char pwm_percent = 0;


// ---------------- MAIN PROGRAM ----------------
void main(void)
{
    GPIO_Init();
    PWM_Init();
    SetPWM(pwm_percent);   // Start with 0% PWM (motor off)

    while(1)
    {
        // If UP button is pressed -> increase duty by 10%
        if(RA0 == 0)         // Button pressed (active LOW)
        {
            if(pwm_percent < 100)
                pwm_percent += 10;

            SetPWM(pwm_percent);
            __delay_ms(250);  // Debounce delay
        }

        // If DOWN button is pressed -> decrease duty by 10%
        if(RA1 == 0)         // Button pressed (active LOW)
        {
            if(pwm_percent > 0)
                pwm_percent -= 10;

            SetPWM(pwm_percent);
            __delay_ms(250);  // Debounce delay
        }
    }
}


// ---------------- INITIALIZE GPIO ----------------
void GPIO_Init(void)
{
    // RA0 and RA1 as button inputs
    TRISA0 = 1;     // Set RA0 as input
    TRISA1 = 1;     // Set RA1 as input
    WPUA0 = 1;      // Weak pull-up ON
    WPUA1 = 1;      // Weak pull-up ON
    OPTION_REGbits.nWPUEN = 0; // Enable pull-ups globally

    // RC5 as PWM output
    TRISC5 = 0;     // RC5 as output
}


// ---------------- INITIALIZE PWM ----------------
void PWM_Init(void)
{
    // Configure PWM6 output on RC5 using PPS
    PPSLOCK = 0x55; PPSLOCK = 0xAA;  // Unlock PPS
    RC5PPS = 0x0C;                  // Assign PWM6 to RC5
    PPSLOCK = 0x55; PPSLOCK = 0xAA;  // Lock PPS

    // Timer2 configuration for ~20kHz PWM frequency
    T2CLKCON = 0x01;    // Timer2 clock = Fosc / 4
    T2CON = 0x04;       // Prescaler 1:1, Timer2 ON
    PR2 = 49;           // PWM period setting

    // Enable PWM6 module, active-high
    PWM6CON = 0xC0;     // Enable PWM and set output polarity
}


// ---------------- SET PWM DUTY CYCLE (0% - 100%) ----------------
void SetPWM(unsigned char percent)
{
    // Convert percent (0-100) to a 10-bit duty cycle (0-400)
    unsigned int duty_value = (percent * 4);

    // Split duty value into high and low register parts
    PWM6DCH = duty_value >> 2;     // Upper 8 bits
    PWM6DCL = duty_value << 6;     // Lower 2 bits
}