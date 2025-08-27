#include <stdio.h>
#include <stdlib.h>

void fibb(int iterations){
    int current = 1;
    int last = 0;

    for(int i = 0; i < iterations; i++){
        //TO DO
        int temp = current + last;
        printf("%d \n", temp);
        last = current;
        current = temp;
    }
}

int main(int argc, char** argv){
    int iterations = 10;
    if (argc == 2){
        iterations = atoi(argv[1]);
    }
    fibb(iterations);
    return 0;
}