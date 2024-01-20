# ClassicCryptos

ClassicCryptos is a GitHub repository that showcases implementations of historical cryptographic methods. The current focus is on two classic ciphers - the Caesar Cipher and the Vigenere Cipher. These ciphers provide a glimpse into the historical methods used for encrypting and decrypting messages.

## Table of Contents

- [Overview](#overview)
- [Implemented Ciphers](#implemented-ciphers)
- [Input Constraints](#input-constraints)
- [Code Structure](#code-structure)
- [Error Handling](#error-handling)
- [License](#license)

## Overview

This repository serves as a learning resource for understanding and implementing classic cryptographic algorithms. It provides simple and clear implementations of the Caesar Cipher and the Vigenere Cipher in the C programming language.

## Implemented Ciphers

1. **Caesar Cipher**
    - A substitution cipher where each letter in the plaintext is shifted a certain number of places down or up the alphabet.

2. **Vigenere Cipher**
    - A method of encrypting alphabetic text by using a simple form of polyalphabetic substitution.


## Input Constraints

- The input message and key should not be empty.
- Non-alphabetic characters in the input message are left unchanged.
- The program supports both uppercase and lowercase alphabetic characters.

## Code Structure

- `caesar_cipher.c`: Implementation of the Caesar Cipher.
- `vigenere_cipher.c`: Implementation of the Vigenere Cipher.
- `main.c`: Main program that provides a user interface and invokes cipher functions.

## Error Handling

- The program checks for null pointers and empty strings in both the text and key.
- Invalid input (non-integer) is handled by clearing the input buffer.

## License
This README.md provides a comprehensive overview of your GitHub repository, including information about the implemented ciphers, how to use the program, code structure, error handling, and more. You can copy and paste this Markdown code into your repository's README.md file.

