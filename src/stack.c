#include "stack.h"
#include <assert.h>

void initialize(stack* s){
  s->head = NULL; //Initialize the stack, by making sure it doesn't point to anything.
}

void push(int x, stack* s){
  node *new = (node*) malloc(sizeof(node)); //Allocate memory for a new node somewhere, store pointer to it in new
  new->data = x; //add data to new node
  new->next = s->head; //make sure the new node points to previous top/head of the stack
  s->head = new; //make new the top/head of the stack
}

int pop(stack* s){ //returns the data from the item it removes
  assert(!empty(s)); //Can't pop from an empty stack
  int saved = s->head->data; //Save the data from the top of the stack
  node *copy = s->head; //Copy the location for the current top of the stack
  s->head = s->head->next; //Update the new top of the stack to be one lower in the stack
  free(copy); //Free up the previous top's memory allocation.
  return saved;
}

bool empty(stack* s)
{
  if(s->head == NULL) return true; //If the head has no next node, stack must be empty.
  return false;
}

bool full(stack* s) {
    //The stack can never be full, when using a linked list like this.
    //Unless of course you run out of memory on your pc, but I hope it doesn't go that far.
  return false;
}
