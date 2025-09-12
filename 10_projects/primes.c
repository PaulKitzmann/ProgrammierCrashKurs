#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>

bool* getPrimes(long limit) {
    bool* numbers = malloc((limit - 1) * sizeof(bool));
    if (numbers == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    for (long i = 0; i < limit - 1; i++) {
        numbers[i] = true;
    }

    for (long currentNumber = 2; currentNumber <= sqrt(limit); currentNumber++) {
        long currentPosition = currentNumber - 2;
        if (!numbers[currentPosition]) continue;

        while (currentPosition + currentNumber < limit - 1) {
            currentPosition += currentNumber;
            numbers[currentPosition] = false;
        }
    }

    return numbers;
}

int main() {
    long limit, start;
    printf("Gib die obere Schranke ein:\n");
    scanf("%ld", &limit);

    printf("Gib die untere Schranke ein:\n");
    scanf("%ld", &start);

    clock_t startComputing = clock();
    bool* numbers = getPrimes(limit);
    clock_t endComputing = clock();

    clock_t startPrint = clock();
    for (long i = start; i < limit; i++) {
        if (numbers[i - 2]) {
            printf("%ld\n", i);
        }
    }
    clock_t endPrint = clock();

    double durationComputing = (double)(endComputing - startComputing) / CLOCKS_PER_SEC;
    double durationPrint = (double)(endPrint - startPrint) / CLOCKS_PER_SEC;

    printf("Computation Time: %.5f seconds\n", durationComputing);
    printf("Printing    Time: %.5f seconds\n", durationPrint);

    free(numbers);
    return 0;
}