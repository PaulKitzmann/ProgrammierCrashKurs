#include <stdio.h>
#include <limits.h>


int main(){
    /*
        Syntax While-Schleife:
        
        while (Bedingung) {
            // Tu etwas, solange Bedingung wahr ist
            // Bedingung ist wahr, solange != 0
        }


    */

    int counter1 = 0;
    
    while (counter1 < 1000000){
        printf("%d\n", counter1++);
    }


    long long counter1 = 0;
    long long limit = 10000000;
    printf("Starting to count to %lld\n", limit);
    while (counter1 < limit) {
        counter1++;
    }
    printf("Counted to %lld\n", limit);
    return 0;

    while(1){
        printf("Code is running\n");
    }
}