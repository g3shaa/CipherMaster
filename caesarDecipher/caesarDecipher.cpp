#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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

/* Function to display the menu options to the user. */
void printMenu() {
    printf("1. Caesar Cipher\n");
    printf("2. Caesar Decipher\n");
    printf("3. Exit\n");
    printf("Select an option: ");
}

/* The main function of the program. */
int main() {
    int choice; // Variable to store the user's menu choice
    char text[256]; // Buffer for input text, assuming max length 255
    int shift; // Variable for the shift value
    char result[256]; // Buffer to hold the result of encryption/decryption

    /* Infinite loop to keep the program running until the user chooses to exit. */
    while (1) {
        printMenu();
        scanf_s("%d", &choice); // Read the user's choice
        getchar(); // Consume the newline character after the number

        /* Check if the user chose to exit the program. */
        if (choice == 3) {
            printf("Exiting the program.\n");
            break; // Break out of the loop to exit the program
        }

        printf("Enter a text: ");
        fgets(text, sizeof(text), stdin); // Read the text to be encrypted/decrypted
        text[strcspn(text, "\n")] = 0; // Remove newline character from the input

        printf("Enter shift: ");
        scanf_s("%d", &shift); // Read the shift value for the cipher
        getchar(); // Consume the newline character after the number

        /* Perform action based on the user's choice. */
        switch (choice) {
        case 1:
            caesarCipher(text, shift, result); // Encrypt the text
            printf("Encrypted text: %s\n", result); // Display encrypted text
            break;
        case 2:
            caesarDecipher(text, shift, result); // Decrypt the text
            printf("Deciphered text: %s\n", result); // Display decrypted text
            break;
        default:
            printf("Invalid option!\n"); // Handle invalid menu choice
            break;
        }
    }

    return 0; // End of program
}
