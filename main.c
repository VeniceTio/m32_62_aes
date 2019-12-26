#include "aes.h"
#include "utils.h"
#include "keyExtention.h"

#include <stdio.h>

int main(int argc, char* argv[]) {
    // Test print matrice
    uint8_t tab[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

    print(tab);
    printf("\n\n\n");

	// Test Shift Rows
    uint8_t* tab_shift = shiftRows(tab);

    print(tab_shift);
    printf("\n\n\n");

	// Test Sub Bytes
    uint8_t* tab_sub = subBytes(tab_shift);

    print(tab_sub);
    printf("\n\n\n");

	// Test Inv Sub Bytes
    uint8_t* tab_inv_sub = invSubBytes(tab_sub);

    print(tab_inv_sub);
    printf("\n\n\n");

	// Test Hexadecimal
    char hex[256];

    char* phrase = "Thank you";

    stringToHexStr(phrase, &hex);

    printf("Keygen Phrase: %s\n", phrase);
    printf("Text In Hex %s.\n", hex);
    printf("Length of Hex String %i.\n", strlen(hex));

    long num = strtol(hex, NULL, 16);
    printf("Hex in numerical: %ld \n", num);

    struct HexDigits digits;
    digits = getHexDigits(183);
    printf("Digit 1: %i\n", digits.d1);
    printf("Digit 2: %i\n", digits.d2);

    //***********************************
	// Test Extention Clefs

	// Creer la clef en bits a partir de la phrase
    uint8_t key[(KEY_LENGTH / 8)];
    strToKeyByte(phrase, &key);

    // Afficher les bytes de la clef
    printf("Key Bytes:");
    for(int i = 0; i < (KEY_LENGTH / 8); ++i) {
        printf("%i ", key[i]);
    }

    // Allocation memoire de 4 Mots Binaires de 4 uint8_t (byte) chacun
    uint8_t extKey[4][4];

    uint8_t testKey[16] = { 0x2b, 0x7e, 0x15, 0x16, 0x28, 0xae, 0xd2, 0xa6, 0xab, 0xf7, 0x15, 0x88, 0x09, 0xcf, 0x4f, 0x3c };

    // Etendre la clef en (NbRound + 1) clefs
    keyExtention(testKey, (uint8_t**)extKey);

    for(int i = 0; i < (KEY_LENGTH / 32) * (NB_ROUNDS+1); ++i) {
        if(i % 4 == 0)
            printf("\n Key:\n");
        //printWord(&extKey[i]);
        printWordHex(&extKey[i]);
    }

  return 0;
}

