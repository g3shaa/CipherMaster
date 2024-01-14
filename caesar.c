#include "caesar.h"
#include <ctype.h>

void caesarCipher(char *text, int shift) {
    for (int i = 0; text[i] != '\0'; ++i) {
        if (isalpha(text[i])) {
            char base = isupper(text[i]) ? 'A' : 'a';
            text[i] = (text[i] - base + shift) % 26 + base;
        }
    }
}

void caesarDecipher(char *text, int shift) {
    caesarCipher(text, -shift);
}
