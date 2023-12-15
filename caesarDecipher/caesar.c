#include "caesar.h"
#include <ctype.h>
#include <string.h>

/* Function to perform the Caesar Cipher encryption.
   Parameters:
     str: The input string to be encrypted.
     shift: The shift value for the Caesar cipher.
     result: A buffer to store the encrypted result. */
void caesarCipher(char* str, int shift, char* result) {
    /* Define the alphabet used for the Caesar cipher.
       This is a constant string of uppercase alphabets. */
    const char* alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    /* Get the length of the input string to iterate over it. */
    int len = strlen(str);

    /* Iterate over each character of the input string. */
    for (int i = 0; i < len; ++i) {
        char ch = str[i]; // Current character from the string

        /* Check if the current character is an alphabet.
           If it is, we perform the shift operation. */
        if (isalpha(ch)) {
            char upperCh = toupper(ch); // Convert character to uppercase
            int isUpperCase = isupper(ch); // Check if original char was uppercase

            /* Find the position of the character in the alphabet string. */
            const char* posPtr = strchr(alphabet, upperCh);
            if (posPtr) {
                int pos = posPtr - alphabet; // Position of the character in the alphabet
                int newIndex = (pos + shift) % 26; // Calculate new position after shift

                /* Add the shifted character to the result.
                   If original character was lowercase, convert to lowercase. */
                result[i] = isUpperCase ? alphabet[newIndex] : tolower(alphabet[newIndex]);
            }
        }
        else {
            /* If character is not an alphabet, just add it to the result as is. */
            result[i] = ch;
        }
    }
    result[len] = '\0'; // Null-terminate the result string
}

void caesarDecipher(char* str, int shift, char* result) {
    /* Decryption is just the reverse of encryption.
       We use the encryption function with (26 - shift). */
    caesarCipher(str, 26 - shift, result);
}