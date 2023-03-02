#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <assert.h>

#include "../reverse.h"

// The maximum length string we'll be able to store
#define MAX_LENGTH 80

void test_string(char original[], char expected[]) {
    char reversed[MAX_LENGTH + 1];
    char expected_reverse[MAX_LENGTH + 1];

    char original_copy[MAX_LENGTH + 1];

    strcpy(original_copy, original);

    // fill the reversed array with printable characters so there's something
    // there to print if they fail to put in a '\0'
    for(size_t i = 0; i < MAX_LENGTH; i++)
        reversed[i] = '*';

    reversed[MAX_LENGTH] = '\0';

    strcpy(expected_reverse, expected);
    reverse_string(original_copy, reversed);

    if(strcmp(reversed, expected_reverse) != 0) {
        printf("Passed this string to reverse_string():\n%s\n", original);
        printf("Expected the reversed to be:\n%s\n", expected_reverse);
        printf("Instead I got this:\n%s\n", reversed);
        exit(1);
    }

    strcpy(original_copy, original);
    reverse_string_in_place(original_copy);

    if(strcmp(original_copy, expected_reverse) != 0) {
        printf("Passed this string to reverse_string_in_place():\n%s\n",
               original);
        printf("Expected the reversed string to be this:\n%s\n",
               expected_reverse);
        printf("Instead I got this:\n%s\n", original_copy);
        exit(1);
    }
}

int main() {
    FILE* input_file = NULL;
    
    if (access("tests/string-values", F_OK) == 0) {
        input_file = fopen("tests/string-values", "rb");
    }

    assert(input_file);

    for(size_t i = 0; i < 6; i++) {
        size_t len;
        fread(&len, sizeof(len), 1, input_file);
        char original[len];
        char reversed[len];
        fread(original, sizeof(char), len, input_file);
        fread(reversed, sizeof(char), len, input_file);
        original[len] = '\0';
        reversed[len] = '\0';
        test_string(original, reversed);
    }

    fclose(input_file);

    printf("All tests passed!\n");

    return 0;
}
