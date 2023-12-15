/* caesar.h: Header file for Caesar Cipher functions */

#ifndef CAESAR_H
#define CAESAR_H

/* Function to perform the Caesar Cipher encryption */
void caesarCipher(char* str, int shift, char* result);

/* Function to perform the Caesar Cipher decryption */
void caesarDecipher(char* str, int shift, char* result);

#endif // CAESAR_H
