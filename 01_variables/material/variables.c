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

    //printf("Char: %c, Zahl: %d\n", varChar3, varChar3);
    //printf("Char: %c, Zahl: %d\n", varChar4, varChar4);

    //printf("(Signed) Char:\nMin Value: %lld, Max Value: %lld\n", SCHAR_MIN, SCHAR_MAX);



    // // https://en.wikipedia.org/wiki/C_data_types
    // printf("%20s%12s%20s%20s%20s\n", "Data Type", "Size", "Min Value", "Max Value", "Format Specifier");
    // printf("%20s%12s%20lld%20lld%20s\n", "(signed) char", "8 Bits", (long long)SCHAR_MIN, (long long)SCHAR_MAX, "%c");
    // printf("%20s%12s%20u%20u%20s\n", "unsigned char", "8 Bits", 0u, (unsigned int)UCHAR_MAX, "%c");
    // printf("%20s%12s%20lld%20lld%20s\n", "(signed) short", "16 Bits", (long long)SHRT_MIN, (long long)SHRT_MAX, "%hi or %hd");
    // printf("%20s%12s%20u%20u%20s\n", "unsigned short", "16 Bits", 0u, (unsigned int)USHRT_MAX, "%hu");
    // printf("%20s%12s%20lld%20lld%20s\n", "(signed) int","32 Bits", (long long)INT_MIN, (long long)INT_MAX, "%i or %d");
    // printf("%20s%12s%20u%20u%20s\n", "unsigned int","32 Bits" , 0u, UINT_MAX, "%u");
    
    // printf("\n");
    // printf("%20s%12s%20.3e%20.3e%20s\n", "float", "32 Bits", FLT_MIN, FLT_MAX, "e.g. %f or %F");
    // printf("%20s%12s%20.3e%20.3e%20s\n", "double", "64 Bits", DBL_MIN, DBL_MAX, "e.g. %lf or %lF");


}