#include "caesar.h"
#include <stdio.h>
#include <stdlib.h>

int main() {


	char text_0[] = "Welcome to the Caesar Cypher Program";
	printf("\n%s\n\n", text_0);

	// first test
	printf("\nTest 1\n");
	char text_1[] = "This is a secret message\n";
	printf("Message: %s\n", text_1);

	printf("Now we encode with a value of 10\n");
	char *encoded_1 = encode(text_1, 10);
	printf("Encoded: %s\n", encoded_1);

	printf("Now we decode with a value of 10\n");
	char *decoded_1 = decode(encoded_1, 10);
        printf("Decoded: %s\n", decoded_1);

	// second test
        printf("\nTest 2\n");
        char text_2[] = "the quick brown fox jumps over the lazy dog\n";
        printf("Message: %s\n", text_2);

        printf("Now we encode with a value of 22\n");
        char *encoded_2 = encode(text_2, 22);
        printf("Encoded: %s\n", encoded_2);

        printf("Now we decode with a value of 22\n");
        char *decoded_2 = decode(encoded_2, 22);
        printf("Decoded: %s\n", decoded_2);

	// third test
        printf("\nTest 3\n");
        char text_3[] = "What piece of work is a man, how noble in reason,\n"
		"how infinite in faculties, in form and moving,\n"
		"how express and admirable in action, how like an angel in apprehension,\n"
		"how like a god!\n";
        printf("Message: %s\n", text_3);

        printf("Now we encode with a value of 35\n");
        char *encoded_3 = encode(text_3, 35);
        printf("Encoded: %s\n", encoded_3);

        printf("Now we decode with a value of 35\n");
        char *decoded_3 = decode(encoded_3, 35);
        printf("Decoded: %s\n", decoded_3);


        // fourth test
        printf("\nTest 4\n");
        char text_4[] = "I have of late—but wherefore\n"
		"I know not—lost all my mirth, forgone all custom of\n"
		"exercises; and indeed it goes so heavily with my\n"
		"disposition that this goodly frame, the earth, seems to\n"
		"me a sterile promontory, this most excellent canopy,\n"
		"the air, look you, this brave o'erhanging firmament,\n"
		"this majestical roof fretted with golden fire, why,\n"
		"it appears no other thing to me than a foul and pestilent\n"
		"congregation of vapors.\n";
        printf("Message: %s\n", text_4);

        printf("Now we encode with a value of -5\n");
        char *encoded_4 = encode(text_4, -5);
        printf("Encoded: %s\n", encoded_4);

        printf("Now we decode with a value of -5\n");
        char *decoded_4 = decode(encoded_4, -5);
        printf("Decoded: %s\n", decoded_4);

	// fifth test
        printf("\nTest 5\n");
        char text_5[] = "This above all: to thine own self be true,\n"
		"And it must follow, as the night the day,\n"
		"Thou canst not then be false to any man.\n";
        printf("Message: %s\n", text_5);

        printf("Now we encode with a value of -100\n");
        char *encoded_5 = encode(text_5, -100);
        printf("Encoded: %s\n", encoded_5);

        printf("Now we decode with a value of -100\n");
        char *decoded_5 = decode(encoded_5, -100);
        printf("Decoded: %s\n", decoded_5);


	// free allocated memory
	free(encoded_1);
	free(decoded_1);
	free(encoded_2);
        free(decoded_2);
	free(encoded_3);
        free(decoded_3);
	free(encoded_4);
        free(decoded_4);
        free(encoded_5);
        free(decoded_5);

	return 0;

}
