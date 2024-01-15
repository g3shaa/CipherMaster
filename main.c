#include "utils.h"
#include "caesar.h"

int main()
{
    char input[MAX_LENGTH];
    int shift;
    int choice;
    printf("    ___ _       _                                  _            \n");
    printf("   / __(_)_ __ | |__   ___ _ __   /\\/\\   __ _ ___| |_ ___ _ __ \n");
    printf("  / /  | | '_ \\| '_ \\ / _ \\ '__| /    \\ / _` / __| __/ _ \\ '__|\n");
    printf(" / /___| | |_) | | | |  __/ |   / /\\/\\ \\ (_| \\__ \\ ||  __/ |   \n");
    printf(" \\____/|_| .__/|_| |_|\\___|_|   \\/    \\/\\__,_|___/\\__\\___|_|   \n");
    printf("        |_|                                                  \n");

    do
    {
        printf("\nCaesar Cipher and Decipher Menu:\n");
        printf("1. Caesar Cipher\n");
        printf("2. Caesar Decipher\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid option. Please enter a valid integer.\n");
            clearBuffer(); // Clear the input buffer to avoid an infinite loop
            continue;
        }

        switch (choice)
        {
        case 1:
            printf("Enter text: ");
            scanf(" %[^\n]s", input);

            printf("Enter shift value: ");
            scanf("%d", &shift);
            caesarCipher(input, shift);
            printf("Caesar Ciphered Text: %s\n", input);
            break;

        case 2:
            printf("Enter text: ");
            scanf(" %[^\n]s", input);

            printf("Enter shift value: ");
            scanf("%d", &shift);
            caesarDecipher(input, shift);
            printf("Caesar Deciphered Text: %s\n", input);
            break;
        case 3:
            printf("Exiting program. Goodbye!\n");
            break;

        default:
            printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 3);

    return 0;
}
