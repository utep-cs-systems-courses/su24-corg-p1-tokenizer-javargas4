#include "history.h"
#include "tokenizer.h"
#include <stdio.h>
#include <stdlib.h>

/* Initialize the linked list to keep the history. */

List* init_history () {
  // allocating memory for list structure
  List *list = (List*)malloc(sizeof(List));
  
  // check if memory allocated
  if (list == NULL) {
    fprintf(stderr, "Failed to allocate memory for history list.\n");
    return NULL;
  }
  // set root to NULL
  list->root = NULL;

  return list;

}

/* Add a history item to the end of the list.
   List* list - the linked list
   char* str - the string to store */

void add_history(List *list, char *str) {
  // calculate length of the string
  int len = 0;

  while (str[len] != '\0') {
    len++;
    
  }

  // allocate memory for a new item
  Item *new_item = (Item *)malloc(sizeof(Item));

  // check if memory allocation successful
  if (new_item == NULL) {
    fprintf(stderr, "Failed to allocate memory for new history item.\n");
    return;
  }

  // copy the string into the new item using copy_str
  new_item->str = copy_str(str, len);
  new_item->next = NULL;

  // if list is empty, this item becomes the new root
  if (list->root == NULL) {
    new_item->id = 1;
    list->root = new_item;

  } else {
    // otherwise, find the last item and append this item to it
    Item *current = list->root;
    int id = 1;

    // traverse the list, increment id
    while (current->next != NULL) {
      current = current->next;
      id++;
      
    }

    // set id number and value of node
    new_item->id = id + 1;
    current->next = new_item;

  }

}


/* Retrieve the string stores in the node where Item->id == id.
   List* list - the linked list
   int id - the id of the Item to find */

char *get_history(List *list, int id) {
  // check list is NULL or empty
  if (list == NULL || list->root == NULL) {
    return NULL;
  }

  // pointer to traverse the list
  Item *current = list->root;

  // traverse the list til the end is reached or a matching id is found
  while (current != NULL) {
    // return Item string if matching id is found
    if (current->id == id) {
      return current->str;
    }

    // proceed to next item in list
    current = current->next;
    
  }

  // return NULL if item is not found
  return NULL;

}

/* Print the entire contents of the list. */

void print_history(List *list) {
  // point to first item
  Item *current = list->root;

  // traverse list til end
  while (current != NULL) {
    // print string contents
    printf("%d. %s\n", current->id, current->str);
    current = current->next;
    
  }

}

/* Free the history list and the strings it references. */

void free_history(List *list) {
  // check is list is NULL
  if (list == NULL) {
    return;
  }

  // pointer to traverse the list
  Item *current = list->root;
  Item *temp;

  // traverse the list and free each item and its string
  while (current != NULL) {
    // save next item
    temp = current->next;

    // free string in current item
    free(current->str);

    // free the current item itself
    free(current);

    // move to the next item
    current = temp;

  }
  
  // free the list structure itself
  free(list);

}
