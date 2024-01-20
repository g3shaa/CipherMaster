#include <stdio.h>
#include <stdlib.h> // For malloc() and free()
#include <string.h> 
#include <ctype.h> // For isalpha() and toupper()

void vigenere_encrypt(char *text, char *key);
void vigenere_decrypt(char *text, char *key);

int main()
{
    char input[100];
    char key[100];
    int choice;
    int validInput;

    do
    {
        printf("\n--- Vigenere Cipher Menu ---\n");
        printf("1. Encrypt a message\n");
        printf("2. Decrypt a message\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");

        // Check if the input is a valid integer
        validInput = scanf("%d", &choice);

        // If the input is not a valid integer, clear the buffer and handle appropriately
        if (validInput != 1)
        {
            printf("Invalid input. Please enter a valid option.\n");

            // Clear the input buffer
            while (getchar() != '\n')
                ;

            // Reset choice to a value that won't match any menu option
            choice = 0;
        }

        switch (choice)
        {
        case 1:
            printf("Enter the message to encrypt: ");
            getchar(); // Consume the newline character left in the buffer
            fgets(input, sizeof(input), stdin);
            printf("Enter the encryption key: ");
            fgets(key, sizeof(key), stdin);

            // Remove newline characters
            strtok(input, "\n");
            strtok(key, "\n");

            // Encrypt the message
            vigenere_encrypt(input, key);

            // Display the encrypted message
            printf("Encrypted message: %s\n", input);
            break;

        case 2:
            // Input the text and key from the user
            printf("Enter the message to decrypt: ");
            getchar(); // Consume the newline character left in the buffer
            fgets(input, sizeof(input), stdin);
            printf("Enter the decryption key: ");
            fgets(key, sizeof(key), stdin);

            // Remove newline characters
            strtok(input, "\n");
            strtok(key, "\n");

            // Decrypt the message
            vigenere_decrypt(input, key);

            // Display the decrypted message
            printf("Decrypted message: %s\n", input);
            break;

        case 3:
            printf("Exiting the program. Goodbye!\n");
            break;

        default:
            if (choice != 0)
            {
                printf("Invalid choice. Please enter a valid option.\n");
            }
        }
    } while (choice != 3);

    return 0;
}

void vigenere_encrypt(char *text, char *key)
{
    if (text == NULL || key == NULL)
    {
        printf("Error: Null pointer detected.\n");
        return;
    }

    int i, j;
    int text_len = strlen(text);
    int key_len = strlen(key);

    if (text_len == 0 || key_len == 0)
    {
        printf("Error: Empty text or key.\n");
        return;
    }

    for (i = 0, j = 0; i < text_len; ++i, ++j)
    {
        if (j == key_len)
        {
            j = 0;
        }

        if (isalpha(text[i]) && isalpha(key[j]))
        {
            text[i] = ((toupper(text[i]) + toupper(key[j]) - 2 * 'A') % 26) + 'A';
        }
        // If the characters are not alphabetic, leave them unchanged.
    }
}

void vigenere_decrypt(char *text, char *key)
{
    if (text == NULL || key == NULL)
    {
        printf("Error: Null pointer detected.\n");
        return;
    }

    int i, j;
    int text_len = strlen(text);
    int key_len = strlen(key);

    if (text_len == 0 || key_len == 0)
    {
        printf("Error: Empty text or key.\n");
        return;
    }

    for (i = 0, j = 0; i < text_len; ++i, ++j)
    {
        if (j == key_len)
        {
            j = 0;
        }

        if (isalpha(text[i]) && isalpha(key[j]))
        {
            text[i] = ((toupper(text[i]) - toupper(key[j]) + 26) % 26) + 'A';
        }
        // If the characters are not alphabetic, leave them unchanged.
    }
}