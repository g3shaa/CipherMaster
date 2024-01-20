# Vigenere Cipher Program

## Overview

This program implements the Vigenere cipher, allowing users to encrypt and decrypt messages using a provided key. The Vigenere cipher is a method of encrypting alphabetic text by using a simple form of polyalphabetic substitution.

## Usage

1. **Encrypt a Message**
    - Enter the message to encrypt when prompted.
    - Enter the encryption key when prompted.
    - The program will display the encrypted message.

2. **Decrypt a Message**
    - Enter the message to decrypt when prompted.
    - Enter the decryption key when prompted.
    - The program will display the decrypted message.

3. **Exit**
    - Choose option 3 to exit the program.

## Input Constraints

- The input message and key should not be empty.
- Non-alphabetic characters in the input message are left unchanged.
- The program supports both uppercase and lowercase alphabetic characters.

## Code Structure

- `vigenere_encrypt`: Function to encrypt a given text with the Vigenere cipher.
- `vigenere_decrypt`: Function to decrypt a given text with the Vigenere cipher.
- `main`: The main program that takes user input, performs encryption and decryption, and displays results.

## Error Handling

- The program checks for null pointers and empty strings in both the text and key.
- Invalid input (non-integer) is handled by clearing the input buffer.

## Build and Run

- Compile the program using a C compiler (e.g., GCC).
    ```bash
    gcc main.c -o VigenereCipher.exe
    ```

- Run the compiled program.
    ```bash
    ./VigenereCipher.exe
    ```

## Example

```plaintext
Enter the message: HELLOWORLD
Enter the key: KEY
Encrypted message: RIJVSPBLI
Decrypted message: HELLOWORLD
