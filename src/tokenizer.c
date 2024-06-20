#include "tokenizer.h"
#include <stdlib.h>
#include <stdio.h>

// returns true if c is a whitespace character
int space_char (char c) {
  // check if ' ' or '\t'
  return c == ' ' || c == '\t';
}

// returns true if c is a non-whitespace character
int non_space_char (char c) {
  // check if ' ' or '\t' or '\0'
  return c != ' ' && c != '\t' && c != '\0';
}

// returns a pointer to the first character of the next
// space-separated token in a zero-terminated string.
// returns a zero pointer if str does not contain any tokens
int *token_start (char *str) {
  // check each character until end of line '\0'
  while (*str != '\0') {
    // check if non-whitespace char, returns first non-whitespace char
    if (non_space_char(*str)) {
      return str;
    }
    // increment memory address to check the next char
    str++;
  }
  return NULL;
  
}
