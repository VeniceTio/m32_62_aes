#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "aes.h"

/*
 * Fonction permettant de générer un mot de 4 bytes à partir du tableau de rCon
 * - i :
 */
uint8_t* get_r_con_word(int i);

/*
 * Fonction permettant de
 * - keyNum :
 * - extKey :
 */

uint8_t* get_key(int keyNum, uint8_t* extKey);

/*
 * Méthode permettant de générer une clef a 16 byte en se basant sur une phrase
 * - text : le texte entré
 * - output : la clef
 */
void str_to_key_byte(char* text, uint8_t output[16]);

/*
 * Algorithme d'extention de clef: génére X+1 clefs pour X Rounds
 * Applique le chiffrement sur le premier mot de la clef. Ensuite, le chiffrement se propage
 * car le Deuxieme mot = (Premier mot) XOR (Deuxieme mot de la clef precedente)
 * ETC jusqu'a NB_CLEFS = NB_ROUNDS + 1
 * - key :
 * - extKeyW :
 */
void key_expansion(uint8_t key[KEY_LENGTH / 8], uint8_t** extKeyW);

/*
 * Fonction permettant de shifter les bytes du mot d'un cran vers la gauche
 * - word : le mot qui contient les bytes qu'on doit shifter
 */
void rot_word(uint8_t* word);

/*
 * Fonction permettant de transformer un string en héxadécimale
 * - text : le texte qu'on doit transformer
 */
char* string_to_hex_str(char* text, char output[256]);

/*
 * Méthode permettant de
 */
void hex_str_to_key(char* hex, uint8_t* key);
