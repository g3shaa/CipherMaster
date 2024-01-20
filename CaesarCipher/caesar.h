#ifndef CAESAR_H
#define CAESAR_H

void caesarCipher(char *text, int shift);
void caesarDecipher(char *text, int shift);
void clearBuffer();
void encryptFile(char *filename, int shift);
void decryptFile(char *filename, int shift);

#endif 
