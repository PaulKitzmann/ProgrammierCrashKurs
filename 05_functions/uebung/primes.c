#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int isPrime(int num){
    if (num < 2){return 0;}
    for(int i = 2; i <= sqrt(num); i++){
        if(num % i == 0){
            return 0;
        }
    }

    return 1;
}

int main(int argc, char** argv){
    int start = 0;
    int end;
    printf("Enter Limit:\n");
    scanf("%d", &end);


    for(int i = start; i <= end; i++){
        if(isPrime(i))
            printf("%d\n", i);
    }

    return 0;
}