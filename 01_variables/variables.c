#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(){
    /*
        Most important datatypes in C
        Most important format specifier
    */

    // char: 8 bits
    char varChar1 = 'a';
    char varChar2 = 100;
    char varChar3 = 150;
    unsigned char varChar4 = 150;

    // printf("Char: %c, Zahl: %d\n", varChar1, varChar1);
    // printf("Char: %c, Zahl: %d\n", varChar2, varChar2);
    // https://www.torsten-horn.de/techdocs/ascii.htm

    //printf("Char: %c, Zahl: %d\n", varChar3, varChar3);
    //printf("Char: %c, Zahl: %d\n", varChar4, varChar4);

    //printf("(Signed) Char:\nMin Value: %lld, Max Value: %lld\n", SCHAR_MIN, SCHAR_MAX);



    printf("%20s%20s%20s%20s\n", "Data Type", "Min Value", "Max Value", "Format Specifier");
    printf("%20s%20lld%20lld%20s\n", "(signed) char", (long long)SCHAR_MIN, (long long)SCHAR_MAX, "%c");
    printf("%20s%20u%20u%20s\n", "unsigned char", 0u, (unsigned int)UCHAR_MAX, "%c");
    printf("%20s%20lld%20lld%20s\n", "(signed) short", (long long)SHRT_MIN, (long long)SHRT_MAX, "%hi or %hd");
    printf("%20s%20u%20u%20s\n", "unsigned short", 0u, (unsigned int)USHRT_MAX, "%hu");
    printf("%20s%20lld%20lld%20s\n", "(signed) int", (long long)INT_MIN, (long long)INT_MAX, "%i or %d");
    printf("%20s%20u%20u%20s\n", "unsigned int", 0u, UINT_MAX, "%u");
    
    printf("\n");
    printf("%20s%20.3e%20.3e%20s\n", "float", FLT_MIN, FLT_MAX, "e.g. %f or %F");
    printf("%20s%20.3e%20.3e%20s\n", "double", DBL_MIN, DBL_MAX, "e.g. %lf or %lF");


}