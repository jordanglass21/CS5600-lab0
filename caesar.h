
/**
 * Encodes text using a Caesar cipher.
 *
 * @param plaintext The input string to encode.
 * @param key The value for the caesar cipher.
 * @return A caesar cipher encoded string.
 */
char* encode(char *plaintext, int key);

/**
 * Decodes text using a Caesar cipher.
 *
 * @param ciphertext The encoded string to decode.
 * @param key The value for the Caesar cipher.
 * @return A Caesar cipher decoded string.
 */
char* decode(char *plaintext, int key);

