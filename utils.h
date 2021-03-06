#include <stdint.h>
#include <stddef.h>

struct HexDigits {
    int d1;
    int d2;
};

/*
 * Fonction permettant de réaliser un shift sur monône
 * - monône : le monôme sur lequel on doit effectuer le shift
 */
uint8_t shift_monome(uint8_t monome);

/*
 * Fonction permettant de réaliser la multiplication a*(P)
 * - polynome : le polynôme sur lequel on doit réaliser la multiplication
 */
uint8_t shift_polynome(uint8_t polynome);

/*
 * Fonction permettant de shift un polynome k fois
 * - k : le nombre de fois qu'on doit shift le polynome
 * - polynome : le polynome sur lequel on doit effectuer le shift
 */
uint8_t shif_n_polynome(int k, uint8_t polynome);

/*
 * Fonction permettant d'appliquer un OU exclusif entre 2 mots de 4 bytes
 * - word1 : le premier mot
 * - word2 : le deuxième mot
 */
uint8_t* xor_words(uint8_t* word1, uint8_t* word2);

/*
 * Fonction permettant de réaliser la multiplication entre deux octets
 * - o1 : le premier octet permettant la multiplication
 * - o2 : le deuxième octet permettant la multiplication
 */
uint8_t multiplication(uint8_t o1, uint8_t o2);

/*
 * Fonction permettant d'extraire les 2 chiffres du bit en représentation héxadécimale
 * - byte : le byte dans lequel on doit extraire les deux chiffres
 */
struct HexDigits get_hex_digits(uint8_t byte);

/*
 * Fonction permettant d'afficher un mot de 4 bytes
 * - word : le mot à afficher
 */
void print_word(uint8_t* word);

/*
 * Fonction permettant de d'afficher un mot de 4 bytes en hexadécimal
 * - word : le mot à afficher
 */
void printWordHex(uint8_t* word);

/*
 * Fonction permettant d'afficher les uint de façon plus graphique
 * - display : les uint à afficher
 */
void print(uint8_t* display);

/*
 * Fonction permettant d'afficher les uint de façon plus graphique
 * - display : les uint à afficher
 */
void print_ver(uint8_t* display);


