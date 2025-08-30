#include <stdio.h>

// Extended Euclidean Algorithm
long long euklidExtended(long long a, long long b, long long *x, long long *y) {
    if (b == 0) {
        *x = 1;
        *y = 0;
        return a;
    }
    long long x1, y1;
    long long gcd = euklidExtended(b, a % b, &x1, &y1);
    *x = y1;
    *y = x1 - (a / b) * y1;
    return gcd;
}

// Fast modular exponentiation
long long modexp(long long base, long long exp, long long mod) {
    long long result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1)
            result = (result * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return result;
}

void encrypt(long long *out, char *msg, int length, long long N, long long e) {
    for (int i = 0; i < length; i++) {
        out[i] = modexp((unsigned char)msg[i], e, N);
    }
}

void decrypt(char *out, long long *cipher, int length, long long N, long long d) {
    for (int i = 0; i < length; i++) {
        out[i] = (char)modexp(cipher[i], d, N);
    }
    out[length] = '\0'; // null-terminate string
}

int main() {
    unsigned int prime1 = 11;
    unsigned int prime2 = 13;

    long long N = prime1 * prime2; // modulus
    long long e = 23;              // public exponent

    long long phi = (prime1 - 1) * (prime2 - 1);
    long long x, y;
    euklidExtended(e, phi, &x, &y);

    long long d = x;
    if (d < 0) d += phi;  // normalize private key

    char text[200];
    printf("Enter Message:\n");
    fgets(text, sizeof(text), stdin);

    int len = 0;
    while (text[len] != '\0' && text[len] != '\n') len++;

    long long cipher[200];
    encrypt(cipher, text, len, N, e);

    printf("Encrypted Msg: ");
    for (int i = 0; i < len; i++) {
        printf("%c", (char) cipher[i]);
    }
    printf("\n");

    printf("Encrypted Msg: (numbers)\n");
    for (int i = 0; i < len; i++) {
        printf("%lld ", cipher[i]);
    }
    printf("\n");

    char decrypted[200];
    decrypt(decrypted, cipher, len, N, d);

    printf("Decrypted Message: %s\n", decrypted);

    return 0;
}
