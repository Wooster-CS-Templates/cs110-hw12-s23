#ifndef REVERSE_H
#define REVERSE_H

/**
 * Create the reverse of a string inside another array.
 *
 * Parameters:
 *   original - the original string, which will remain unchanged
 *   reversed - another character array which will store the reversed string
 *   
 * Return value
 *   Nothing, because the reversed string is stored in the provided array
 */
void reverse_string(const char original[], char reversed[]);

/**
 * Reverse a string in place.
 *
 * Parameters:
 *   string - the string to reverse
 *   
 * Return value
 *   Nothing, because the string itself is changed
 */
void reverse_string_in_place(char string[]);

#endif
