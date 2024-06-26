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

// Returns a pointer terminator char following *token
char *token_terminator (char *token) {
  // move to next character as long as null terminator not hit and
  // the current character is not a whitespace
  while (*token != '\0' && !space_char(*token)) {
    token++;
  }
  // return the pointer for the current character, either whitespace or '\0'
  return token;

}

// Counts the number of tokens in the string argument. 
int count_tokens (char *str) {
  int count = 0;
  char *start = NULL;
  char *end = NULL;

  // iterate thru string till end of string
  while (*str != '\0') {
    // get start of token
    start = token_start(str);

    // break loop if start is NULL, end of string reached
    if (start == NULL) {
      break;
    }

    // get end of this token
    end = token_terminator(start);

    // increment counted tokens
    count++;

    /* move to end of current token for next iteration if end
       doesn't point to '\0'*/
    str = *end ? end + 1 : end;

  }

  // return token count
  return count;

}

/* Returns a fresly allocated new zero-terminated string 
   containing <len> chars from <inStr> */
char *copy_str (char *inStr, short len) {
  // memory allocation for length of characters and null terminator
  char *newStr = malloc(len + 1);
  
  // checks if memory allocation was successful
  if (newStr == NULL) {
    return NULL;
  }
  
  // copy len characters from inStr to newStr
  for (int i = 0; i < len; i++) {
    newStr[i] = inStr[i];
  }

  // null-terminate the new string
  newStr[len] = '\0';

  return newStr;

}

/* Returns a freshly allocated zero-terminated vector of freshly allocated 
   space-separated tokens from zero-terminated str.

   For example, tokenize("hello world string") would result in:
     tokens[0] = "hello"
     tokens[1] = "world"
     tokens[2] = "string" 
     tokens[3] = 0
*/
char **tokenize (char* str) {
  // count num of tokens in string
  int num_tokens = count_tokens(str);

  // create array to store tokens and NULL terminator, allocate memory
  char **tokens = malloc(sizeof(char*) * (num_tokens + 1));

  // check if memory allocation successful
  if (tokens == NULL) {
    return NULL;
  }

  // variables to keep track of tokens
  char *start = NULL;
  char *end = NULL;
  int i = 0;

  // iterate thru the string until end of string
  while (*str != '\0') {
    // get start of token
    start = token_start(str);

    // break if no tokens remain
    if (start == NULL) {
      break;
    }

    // get end of token
    end = token_terminator(start);

    // get end of token
    end = token_terminator(start);

    // calculate token length, subtract memory addresses
    int token_length = end - start;

    // copy token over to the token array
    tokens[i] = copy_str(start, token_length);
    i++;

    // advance str to next character after end if not end of string
    str = *end ? end + 1 : end;

  }

  // NULL-terminating the array
  tokens[num_tokens] = 0;

  return tokens;

}

/* Prints all tokens. */
void print_tokens (char **tokens) {
  /* handling the case tokenize might return NULL
     due to failed memory allocation */
  if (tokens == NULL) {
    printf("No tokens to print.\n");
    return;
  }

  // print each token
  for (int i = 0; tokens[i] != NULL; i++) {
    printf("%s\n", tokens[i]);
  }

}

/* Frees all tokens and the vector containing them. */
void free_tokens(char **tokens) {
  // nothing to free if tokens array is NULL
  if (tokens == NULL) {
    return;
  }

  // free each token in the array
  for (int i = 0; tokens[i] != NULL; i++) {
    free(tokens[i]);
  }

  // free the array after freeing individual tokens
  free(tokens);

}
