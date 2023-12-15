#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "caesar.h"
#include "menu.h"

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