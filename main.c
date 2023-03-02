#include <stdio.h>
#include <string.h>

#include "reverse.h"

// The maximum length string we'll be able to store
#define MAX_LENGTH 80

int main() {
    // A string of length MAX_LENGTH will take up MAX_LENGTH + 1 spaces in an
    // array because it has to end with '\0', which is not considered part of
    // the length.
    char string[MAX_LENGTH + 1];

    printf("Enter a word: ");
    scanf("%s", string);

    // strlen() returns the length of the string, not including the '\0', as a
    // size_t
    printf("You entered %s which has a length of %zu\n", string,
           strlen(string));

    // Another array to store the string in reverse
    char reversed[MAX_LENGTH + 1];

    // Uncomment the next two lines to test reverse_string()
    // reverse_string(string, reversed);
    // printf("%s reversed is %s\n", string, reversed);

    // Uncomment the next two lines to test reverse_string_in_place()
    // reverse_string_in_place(string);
    // printf("The original string has now been reversed: %s\n", string);

    return 0;
}
