#include <stdio.h>


int main(){
    /*
        Syntax For-Schleife:
        
        for (Initialisierung; Bedingung; Aktualisierung) {
            // Tu etwas, solange Bedingung wahr ist
            // Bedingung ist wahr, solange != 0
        }


    */

    //Beispiele
    for(int i=0; i<100; i++){
        printf("%d\n", i);
    }


    for(int j=100; j>=0; j-=5){
        printf("%d\n", j);
    }


    for(int y = 0; y < 10; y++){
        for(int x = 0; x < 20; x++){
            printf("%4d", 0);
        }
        printf("\n");
    }

    for(int y = 0; y < 10; y++){
        for(int x = 0; x < 20; x++){
            printf("%4c", y*20 + x);
        }
        printf("\n");
    }

    for(int y = 0; y < 10; y++){
        for(int x = 0; x < 20; x++){
            printf("%4d", 0);
        }
        printf("\n");
    }

    return 0;
}