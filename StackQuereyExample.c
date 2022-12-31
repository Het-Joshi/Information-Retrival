/*
This program demonstrates the implementation of a stack to store user queries
in the form of stacks and perform various operations on them
such as displaying latest searches, adding queires, clearing History,
Searching past searchHistory

Information Retrival Demo by 
- Het Joshi 1MS21CS053
- Hitesh Kumar 1MS21CS054
- Varun Balaji 1MS21CS057
- Malavika Dileep 1MS21CS069
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STACK_SIZE 10

//STACK contains TOP and STRING ELEMENTS
struct Stack {
  int top;
  char *items[STACK_SIZE];
};

//Initialises STACK
struct Stack *createStack() {
  struct Stack *stack = (struct Stack*)malloc(sizeof(struct Stack));
  stack->top = -1;
  return stack;
}

int isEmpty(struct Stack *stack) {
  return stack->top == -1;
}

int isFull(struct Stack *stack) {
  return stack->top == STACK_SIZE - 1;
}

//To push STRING ELEMENTS
void push(struct Stack *stack, char *item) {
  if (isFull(stack)) {
    printf("Stack overflow\n");
    return;
  }

  stack->items[++stack->top] = item;
}

//To pop STRING ELEMENTS
char* pop(struct Stack *stack) {
  if (isEmpty(stack)) {
    printf("Stack underflow\n");
    return NULL;
  }

  return stack->items[stack->top--];
}

//PEEKS top ELEMENT
char* peek(struct Stack *stack) {
  if (isEmpty(stack)) {
    printf("Stack is empty\n");
    return NULL;
  }

  return stack->items[stack->top];
}

//Displays top 3 latest entries to the STACK
void displayTop3(struct Stack *stack) {
  if (stack->top < 2) {
    printf("There are less than 3 items in the stack\n");
    return;
  }

  printf("Top 3 entries in the stack:\n");
  printf("1. %s\n", stack->items[stack->top]);
  printf("2. %s\n", stack->items[stack->top - 1]);
  printf("3. %s\n", stack->items[stack->top - 2]);
}

//Searches Stack for the entered QUEREY
int searchStack(struct Stack *stack, char *item) {
  int i;
  for (i = stack->top; i >= 0; i--) {
    if (strcmp(stack->items[i], item) == 0) {
      return 1;
    }
  }
  return 0;
}

//DRIVER PROGRAM
int main() {
  struct Stack *stack = createStack();

  push(stack, "Item 1");
  push(stack, "Item 2");
  push(stack, "Item 3");
  push(stack, "Item 4");
  push(stack, "Item 5");

  displayTop3(stack);

  char *search_item = "Item 3";
  int found = searchStack(stack, search_item);
  if (found) {
    printf("%s was found in the stack\n", search_item);
  } else {
    printf("%s was not found in the stack\n", search_item);
  }

  return 0;
}