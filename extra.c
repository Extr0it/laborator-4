#include <stdio.h>


/*  //un program care accepta de la user un sir nelimitat si il afiseaza, pe langa asta ai varianta sa iesi din program

int main(){

    int sir[50];
    int numar;
    int i;


    printf("introduceti numere in sirul dvs / apasati 0 pt a opri");

    while(1){
        printf("numar : \n");
        scanf("%d", &numar);

        if (numar == 0 )
        break;
        
        if(numar == 999)
        break;

       sir[i] = numar;
       i++;
    }
   
   if(numar == 0){
    printf("Programul a fost oprit");
   } else{
   printf("Sirul dvs de numere este: ");

   for(int j = 0; j < i; j++)
    printf("%d ", sir[j]);
   
   printf("\n");
   }
   return 0;
}
*/

//------------------PROBLEMA 2 LAB 4

   int main(){

   int vector[100];
   int i;
   int numar;
   char alegere;
    
    printf("\nBine ati venit la meniul interactiv 3000!\n"
           "Alegeti va rog frumos dintre:\n"
           "a - Citirea unui vector cu n elemente si afișarea vectorului\n"
           "b - Afișarea elementelor de pe pozițiile pare\n"
           "c - Afișarea produsului elementelor impare\n"
           "d - Afișarea elementelor divizibile cu o valoare dată de la tastatură\n"
           "e - Afișarea elementelor prime\n"
           "f - Afișarea maximului din vector\n"
           "g - Afișarea minimului din vector\n"
           "0 - IESIRE\n");
   
         scanf("%c", &alegere);

    //pentru un astfel de meniu pompos, trebuie sa folosim switch pt a ne usura vietile noastre amarate de pamanteni muritori
    
        while(1){
            printf("Introdu te rog valoriile vectorului tau\n");
            scanf("%d", &numar);

            if(numar == 999)
            break;

            if(numar == 0)
            break;

            vector[i] = numar;
            i++;
            
        }

    switch(alegere){

        case 'a': {
        printf("Vectorul dvs este:  ");
        
        for(int j= 0; j < i; j++)
        printf("%d ", vector[j]);
        }
        break;
       
        case 'b': {
            printf("Elementele de pe pozitiile pare a vectorului sunt :   ");

            for(int j = 0; j < i; j +=2)
            printf("%d ", vector[j]);
        }
        break;

        case 'c' :{
            int produs = 1;
            for(int j = 0; j<i; j++)
            if(vector[j] % 2 != 0){
            produs *= vector[j];
            printf("* %d  ", vector[j]);
            }

            printf("\nProdusul elementelor impare este: %d\n", produs);

        }
        break;

        case 'd' :{
            int nr;
            printf("Alege un numar cu care sa se divida elementele vectorului\n");
            scanf("%d", &nr);
            printf("Nr divizibile cu %d sunt : ", nr);
            for(int j = 0; j<i; j++)
            if(vector[j] % nr == 0){
                printf("%d ", vector[j]);
            }
        }
        break;

        case 'e' : {

            printf("Numerele prime din acest vector sunt : ");
            for(int j = 0; j < i; j++){
            int prim = 1;

            if (vector[j] <= 1) {
            continue;  // Numerele <= 1 nu sunt prime
            }

            for (int k = 2; k < vector[j]; k++) //pt cautarea divizorilor (nu putem scrie vector[j] % vector
            if (vector[j] % k == 0) {
                prim = 0;  // Numărul nu este prim
                break;
            }
            

            if (prim == 1) {
            printf("%d ", vector[j]);  // Afișăm numărul prim
            }  
          }
       }
       break;

       case 'f' : {
        int max;

        for(int j = 0; j< i; j++){
            if(vector[j] > vector[j - 1])
            max = vector[j];
        }
        printf("Nr maxim din vector este : %d", max);
       }
       break;

      case 'g' :{
        int min;

        for(int j = 0; j< i; j++){
            if(vector[j] < vector[j + 1])
            min = vector[j];
        }
        printf("Nr minim din vector este : %d", min);
       }
       break;

      case '0':
      printf("Programul a luat sfarsit.");
      break;
    }
      return 0;
   }


   

      
    

     


