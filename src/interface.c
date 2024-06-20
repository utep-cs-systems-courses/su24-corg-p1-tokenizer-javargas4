#include "history.h"
#include "tokenizer.h"
#include <stdio.h>
#include <stdlib.h>

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
    }    
  }
}
















