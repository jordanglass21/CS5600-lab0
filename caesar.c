#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

/**
 * Retrieves the number of a character in the alphabet corresponding to it's position.
 * For example A is 1, B is 2, and C is 3.
 *
 * @param c The character we want to find it's corresponding index.
 * @return The index of the character or -1 if the character is not found.
 */
int get_index(char c);

/**
 * Converts all characters in a string to uppercase.
 *
 * @param text The string to convert to uppercase.
 * @return A new string in uppercase.
 */
char* to_upper(char *text);

// data structure
static char alphabet[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M',
	'N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

/**
 * Encodes text using a Caesar cipher.
 *
 * @param plaintext The input string to encode.
 * @param key The value for the caesar cipher.
 * @return A caesar cipher encoded string.
 */
char* encode(char *plaintext, int key) {
	char* upper_text = to_upper(plaintext);
	if (upper_text == NULL) {
		return NULL;
	}

	int text_len = strlen(upper_text);

	// Handles cases where key is too big or small
	// now our key is always in this range 0 <= key <= 25
    	key = (key % 26 + 26) % 26;
	
	// Allocate memory for the ciphertext
    	char* cyphertext = (char*)malloc((text_len + 1) * sizeof(char));
	if (cyphertext == NULL) {
		return NULL;
	}
	
	for (int i = 0; i < text_len; i++) {
		int cypher_index = get_index(upper_text[i]);
		if (cypher_index != -1) {
			cypher_index = (cypher_index + key) % 26;
			cyphertext[i] = alphabet[cypher_index];
		} else {
			cyphertext[i] = upper_text[i];
		}
	}

	cyphertext[text_len] = '\0';
	
	// free allocated memory (from the upper_text function)
	free(upper_text);

	return cyphertext;
}

/**
 * Decodes text using a Caesar cipher.
 *
 * @param ciphertext The encoded string to decode.
 * @param key The value for the Caesar cipher.
 * @return A Caesar cipher decoded string.
 */
char* decode(char *ciphertext, int key) {
	
	return encode(ciphertext, -1 * (key % 26));
}

/**
 * Retrieves the number  of a character in the alphabet corresponding to it's position.
 * For example A is 1, B is 2, and C is 3.
 *
 * @param c The character we want to find it's corresponding index.
 * @return The index of the character or -1 if the character is not found.
 */
int get_index(char c) {
	for(int i = 0; i < 26; i++) {
		if (alphabet[i] == c) {
			return i;
		}
	}
	return -1;
}

/**
 * Converts all characters in a string to uppercase.
 *
 * @param text The string to convert to uppercase.
 * @return A new string in uppercase.
 */
char* to_upper(char *text) {

	// Allocate memory for the upper text
	int text_len = strlen(text);
        char* upper_text = (char*)malloc((text_len + 1) * sizeof(char));
        if (upper_text == NULL) {
                return NULL;
        }

	for (int i = 0; i < text_len; i++) {
		upper_text[i] = toupper(text[i]);
	}

	upper_text[text_len] = '\0';
	return upper_text;
}

