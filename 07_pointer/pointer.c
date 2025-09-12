#include <stdio.h>


int main(){
    int value = 0;

    printf("Value Wert: %d, Value Speicherzelle %x\n", value, &value);

    int * pointer = &value;

    printf("In der Speicherzelle %x befindet sich folgender Wert: %d\n", pointer, *pointer);

    return 0;
}