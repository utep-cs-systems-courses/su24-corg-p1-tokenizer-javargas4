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

// checks if the character is a digit
int is_digit (char c) {
  return c >= '0' && c <= '9';
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
	
      // handle 'history' command
      } else if (string_compare(user_input, "history") == 0) {
	// do something

      // handle '!x' recall command
      } else if (user_input[0] == '!' && is_digit(user_input[1])) {
	// do something

      // handle user token string input
      } else {
	// echos user input
        printf("%s\n", &user_input);
      }
    }    
  }
  return 0;
}
















