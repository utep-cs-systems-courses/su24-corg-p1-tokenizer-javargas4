#include "history.h"
#include "tokenizer.h"
#include <stdio.h>
#include <stdlib.h>

// compare two strings, returns 0 if equal
int string_compare (const char *str1, const char *str2) {
  while (*str1 && (*str1 == *str2)) {
    str1++;
    str2++;
  }
  return (unsigned char)(*str1) - (unsigned char)(*str2);
}


int main (void) {
  char user_input[256];

  while (1) {
    // print UI symbol for user input
    printf("$ ");

    // get user input
    if (fgets(user_input, sizeof(user_input), stdin) != NULL) {

      // remove newline character at the end it it exists
      for (int i = 0; user_input[i] != '\0'; i++) {
	if (user_input[i] == '\n') {
	  user_input[i] ='\0';
	  break;
	}
      }
      
      // handle 'quit' command
      if (string_compare(user_input, "quit") == 0) {
	break;
      }
    }    
  }
  return 0;
}
















