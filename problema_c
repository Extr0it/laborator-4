
#include <stdio.h>  // Biblioteca standard pentru intrare/ieșire
#include <stdlib.h> // Biblioteca standard pentru alocare de memorie, conversii și alte operații
#include <string.h> // Biblioteca pentru manipularea șirurilor de caractere
#include <ctype.h>  // Biblioteca pentru verificarea caracterelor



///////////////////////////////------PROBLEMA 1---------------///////////////////////
/*
int estePutere2(int n) {
    return (n > 0) && ((n & (n - 1)) == 0); //Aici se folosește un truc binar:
//Dacă n este o putere a lui 2, în reprezentarea binară are un singur bit de 1.
//Scăzând 1 din n, toți biții de după acel 1 devin 1, iar acel 1 devine 0.
//Operația n & (n - 1) va da 0 doar dacă n are un singur 1 în reprezentarea binară, adică este o putere a lui 2.
}

void afisare_meniu() {
    printf("\nMeniu:\n");
    printf("1. Afișare propoziție citită\n");
    printf("2. Împărțire propoziție în cuvinte\n");
    printf("3. Salvare lungimi cuvinte\n");
    printf("4. Afișare număr lungimi pare\n");
    printf("5. Afișare număr lungimi puteri ale lui 2\n");
    printf("6. Transformare litere în majuscule\n");
    printf("7. Căutare subsir\n");
    printf("8. Ieșire\n");
}

void citire_propozitie(char propozitie[]) { // functie care asteapta sa primeasca o variabila de tip string pentru a indeplini : 
    printf("Introdu te rog propoziția ta: \n");
    fgets(propozitie, 200, stdin); // citirea unei propozitii date de tastatura(input)
    propozitie[strcspn(propozitie, "\n")] = '\0';
}

int conditie_propozitie(char propozitie[]) {
    int dimensiune = strlen(propozitie); // aflam dimensiunea propozitiei
    return (dimensiune > 0 && propozitie[dimensiune - 1] == '.'); // daca conditiile propozitiei sunt indeplinite atunci functia va returna 1 si va putea fi folosita in int main ca si verificare
}


void afisare_propozitie(char propozitie[]) {
    printf("Propozitia ta este: \n%s\n", propozitie);
}

 // Funcție pentru împărțirea propoziției în cuvinte
int impartePropozitie(char propozitie[], char *cuvinte[], int lungimi[]) {
    int nrCuvinte = 0;  // ne trebuie un contor sa tina evidenta cuvintelor gasite
    char *token = strtok(propozitie, " ,."); // Extrage primul cuvânt

    while (token != NULL) {   // Continuă cât timp există cuvinte
        cuvinte[nrCuvinte] = strdup(token); // creeaza o copie a cuvantului
        lungimi[nrCuvinte] = strlen(token); // salveaza lungimea cuvantului respectiv
        nrCuvinte++;  // incrementam cu 1 ca sa tinem evidenta cuvintelor gasite
        token = strtok(NULL, " ,.");  //  strtok lasa la finalul primului cuvant '\0' (NULL) asa ca trebuie ca urmatoarele cuvinte sa verifice NULL ca sa poate sa le caute pe restul
    }
    return nrCuvinte; 
}

// Funcție pentru afișarea cuvintelor și lungimilor acestora
void afiseaza_lungimi_si_cuvinte(char *cuvinte[], int lungimi[], int nrCuvinte) {
    for (int i = 0; i < nrCuvinte; i++) { // un loop care parcurge toate cuvintele 
        printf("%s (lungime: %d)\n", cuvinte[i], lungimi[i]); // afisam cuvantul si lungimea lui
    }
}
// Funcție pentru numărarea lungimilor pare
int numaraLungimiPare(int lungimi[], int nrCuvinte) {
    int count = 0;
    for (int i = 0; i < nrCuvinte; i++) { // creem o bucla sa parcurga toate cuvintele
        if (lungimi[i] % 2 == 0) { // conditie ca sa fie par este sa se imoparta exact la 2 de asta folosim modul
            count++; // salvam cuvantul incrementand cu 1
        }
    }
    return count;
}
// functie care verifica ca lungimea cuvantului respectiv sa fie o pujtere a lui 2
int numaraPuteri2(int lungimi[], int nrCuvinte) {
    int count = 0;
    for (int i = 0; i < nrCuvinte; i++) {  // creem o bucla sa parcurga toate cuvintele
        if (estePutere2(lungimi[i])) {  // folosesim o functie extra estePutere2 declarata mai sus
            count++;  //incrementam cu 1 ca sa avem salvat faptul ca am gasit un cuvant
        }
    }
    return count;
}

// Funcție pentru transformarea propoziției în litere mari
void transformaMajuscule(char propozitie[]) { 

    for (int i = 0; propozitie[i] != '\0'; i++) { // creem o bucla care va continua atata timp cat ultimul caracter este null
        propozitie[i] = toupper(propozitie[i]); // folosim functia toupper pentru a transforma in majuscule cuvantul
    }
}
// Funcție pentru căutarea unui subsir într-un cuvânt
void cauta_Subsir(char *cuvinte[], int nrCuvinte) { 
    char subsir[50]; // salvam subsirul pe care il vom introduce intr o variabila de tip string
    printf("Introduceti subsirul de cautat: ");
    fgets(subsir, 50, stdin);  //Citim subsirul de la tastatură
    subsir[strcspn(subsir, "\n")] = '\0';
    
    int gasit = 0;
    printf("Cuvinte care conțin subsirul \"%s\":\n", subsir);
    for (int i = 0; i < nrCuvinte; i++) {
        if (strstr(cuvinte[i], subsir) != NULL) {  //caută un subsir într-un șir mai mare. 
        //Dacă găsește subsirul  returnează pointer la prima apariție.
        //Dacă nu găsește returnează NULL.

            printf("%s\n", cuvinte[i]);  // il afiseaza
            gasit = 1; // salveaza daca acesta a fost gasit
        }
    }
    if (!gasit) {
        printf("Nu s-a găsit subsirul în niciun cuvânt.\n");
    }
}

int main() {
    char propozitie[200];
    char *cuvinte[200];
    int lungimi[200];
    int optiune;
    

    citire_propozitie(propozitie);
    if (!conditie_propozitie(propozitie)) {  // daca nu indeplineste conditiile sa dea mesaj de eroare
        printf("Propozitia trebuie sa se termine cu punct!\n");
        return 1;
    }

    char copiePropozitie[200];
    strcpy(copiePropozitie, propozitie);
    int nrCuvinte = impartePropozitie(copiePropozitie, cuvinte, lungimi);
    
    do {  // creem un loop ca sa afiseze constant meniul
        afisare_meniu();
        printf("Alege o optiune: \n");
        if (scanf("%d", &optiune) != 1) {
            printf("Input invalid!\n");
            printf("\n");
            while (getchar() != '\n');
            continue;
        }
        getchar();
        
        switch (optiune) {  // folosim un switch case pentru a ne usura viata in loc de if, sa avem un meniu frumos aranjat
            case 1:
                afisare_propozitie(propozitie);
                break;
            case 2:
            case 3:
                afiseaza_lungimi_si_cuvinte(cuvinte, lungimi, nrCuvinte);
                break;
            case 4:
                printf("Numărul de lungimi pare: %d\n", numaraLungimiPare(lungimi, nrCuvinte));
                break;
            case 5:
                printf("Numărul de lungimi care sunt puteri ale lui 2: %d\n", numaraPuteri2(lungimi, nrCuvinte));
                break;
            case 6:
                transformaMajuscule(propozitie);
                printf("Propoziția în litere mari: %s\n", propozitie);
                break;
            case 7:
                cauta_Subsir(cuvinte, nrCuvinte);
                break;
            case 8:
                printf("Ieșire din program.\n");
                break;
            default:
                printf("Optiune invalida!\n");
        }
    } while (optiune != 8);
    
    for (int i = 0; i < nrCuvinte; i++) {
        free(cuvinte[i]);
    }
    return 0;
}

*/
/////////////////// PROBLEMA 2//////////////////

#include <stdio.h>  // Biblioteca standard pentru intrare/ieșire
#include <stdlib.h> // Biblioteca standard pentru alocare de memorie, conversii și alte operații
#include <string.h> // Biblioteca pentru manipularea șirurilor de caractere
#include <ctype.h>  // Biblioteca pentru verificarea caracterelor


// Definirea structurii pentru o unealtă
typedef struct {
    char nume[50];  // Numele uneltei, max. 50 caractere
    char marca[50]; // Marca uneltei, max. 50 caractere
    int cod;        // Codul uneltei (număr întreg)
    float pret;     // Prețul uneltei (număr real)
} Unealta;

// Funcție pentru validarea numelui uneltei
int validareNume(char *nume) {
    for (int i = 0; nume[i] != '\0'; i++) { // Iterează prin fiecare caracter al numelui
        if (!islower(nume[i]) && !isdigit(nume[i])) { // Verifică dacă nu este literă mică sau cifră
            return 0; // Numele este invalid
        }
    }
    return 1; // Numele este valid
}

// Funcție pentru validarea mărcii uneltei
int validareMarca(char *marca) {
    return strlen(marca) >= 2; // Marca trebuie să aibă cel puțin 2 caractere pentru a fi validă
}

// Funcție pentru validarea prețului
int validarePret(float pret) {
    return pret > 5; // Prețul trebuie să fie mai mare decât 5 pentru a fi valid
}

// Funcție pentru adăugarea unei unelte în lista de unelte
void adaugaUnealta(Unealta *unelte, int *nr) {
    Unealta noua; // Creează o nouă unealtă
    
    // Citirea numelui și validarea acestuia
    do {
        printf("Introduceti numele uneltei (litere mici si cifre): ");
        scanf("%s", noua.nume); // Citește numele uneltei
    } while (!validareNume(noua.nume)); // Se repetă până când numele este valid
    
    // Citirea mărcii și validarea acesteia
    do {
        printf("Introduceti marca uneltei (minim 2 caractere): ");
        scanf("%s", noua.marca); // Citește marca uneltei
    } while (!validareMarca(noua.marca)); // Se repetă până când marca este validă
    
    // Citirea codului uneltei
    printf("Introduceti codul uneltei: ");
    scanf("%d", &noua.cod); // Citește codul uneltei
    
    // Citirea prețului și validarea acestuia
    do {
        printf("Introduceti pretul uneltei (mai mare de 5): ");
        scanf("%f", &noua.pret); // Citește prețul uneltei
    } while (!validarePret(noua.pret)); // Se repetă până când prețul este valid
    
    // Adăugarea uneltei în lista de unelte
    unelte[*nr] = noua; // Salvează noua unealtă în vector
    (*nr)++; // Incrementarea numărului de unelte
}

// Funcție pentru afișarea uneltelor din magazin
void afiseazaUnelte(Unealta *unelte, int nr) {
    if (nr == 0) { // Verifică dacă nu există unelte
        printf("Nu exista unelte in magazin.\n");
        return;
    }
    printf("Lista uneltelor:\n");
    for (int i = 0; i < nr; i++) { // Parcurge toate uneltele
        printf("Nume: %s, Marca: %s, Cod: %d, Pret: %.2f\n",
               unelte[i].nume, unelte[i].marca, unelte[i].cod, unelte[i].pret); // Afișează detaliile fiecărei unelte
    }
}

// Funcție pentru căutarea unei unelte după nume
void cautaUnealta(Unealta *unelte, int nr, char *numeCautat) {
    int gasit = 0; // Variabilă pentru verificarea existenței uneltei
    for (int i = 0; i < nr; i++) { // Parcurge lista de unelte
        if (strcmp(unelte[i].nume, numeCautat) == 0) { // Compară numele uneltei
            printf("Unealta gasita: %s, Marca: %s, Cod: %d, Pret: %.2f\n",
                   unelte[i].nume, unelte[i].marca, unelte[i].cod, unelte[i].pret);
            gasit = 1;
        }
    }
    if (!gasit) { // Dacă unealta nu a fost găsită
        printf("Unealta nu a fost gasita.\n");
    }
}

// Funcție pentru afișarea uneltelor cu un preț mai mic decât un preț dat
void afiseazaUnelteIeftine(Unealta *unelte, int nr, float pretMaxim) {
    int gasit = 0; // Variabilă pentru verificarea existenței uneltelor ieftine
    for (int i = 0; i < nr; i++) { // Parcurge lista de unelte
        if (unelte[i].pret < pretMaxim) { // Verifică dacă prețul este sub prag
            printf("%s - %s - Cod: %d - Pret: %.2f\n",
                   unelte[i].nume, unelte[i].marca, unelte[i].cod, unelte[i].pret);
            gasit = 1;
        }
    }
    if (!gasit) { // Dacă nu există unelte mai ieftine
        printf("Nu exista unelte cu pret mai mic de %.2f\n", pretMaxim);
    }
}

// Funcție de comparare pentru sortare după marcă
int comparaMarca(const void *a, const void *b) {
    return strcmp(((Unealta *)a)->marca, ((Unealta *)b)->marca); // Compară mărci alfabetic
}

// Funcție pentru sortarea și afișarea uneltelor după marcă
void sorteazaSiAfiseaza(Unealta *unelte, int nr) {
    qsort(unelte, nr, sizeof(Unealta), comparaMarca); // Sortează uneltele folosind qsort
    afiseazaUnelte(unelte, nr); // Afișează lista sortată
}

int main() {
    Unealta unelte[100]; // Vector pentru stocarea uneltelor, max. 100 unelte
    int nrUnelte = 0;    // Numărul actual de unelte
    int optiune;         // Variabilă pentru opțiunea utilizatorului
    char numeCautat[50]; // Variabilă pentru căutarea unei unelte după nume
    
    do {
        printf("\nMeniu:\n");
        printf("1. Adauga unealta\n");
        printf("2. Afiseaza uneltele\n");
        printf("3. Cauta unealta dupa nume\n");
        printf("4. Afiseaza uneltele cu pret mai mic decat un anumit pret\n");
        printf("5. Sorteaza si afiseaza uneltele dupa marca\n");
        printf("6. Iesire\n");
        printf("Alegeti o optiune: ");
        scanf("%d", &optiune);
        getchar(); // Consumă newline-ul rămas în buffer

        switch (optiune) {
            case 1:
                adaugaUnealta(unelte, &nrUnelte);
                break;
            case 2:
                afiseazaUnelte(unelte, nrUnelte);
                break;
            case 3:
                printf("Introduceti numele uneltei de cautat: ");
                fgets(numeCautat, sizeof(numeCautat), stdin);
                numeCautat[strcspn(numeCautat, "\n")] = '\0'; // Elimină newline-ul
                cautaUnealta(unelte, nrUnelte, numeCautat);
                break;
            case 4:
                {
                    float pretMaxim;
                    printf("Introduceti pretul maxim: ");
                    scanf("%f", &pretMaxim);
                    afiseazaUnelteIeftine(unelte, nrUnelte, pretMaxim);
                }
                break;
            case 5:
                sorteazaSiAfiseaza(unelte, nrUnelte);
                break;
            case 6:
                printf("Iesire din program.\n");
                break;
            default:
                printf("Optiune invalida!\n");
        }
    } while (optiune != 6);

    return 0; // Termină execuția programului
}




