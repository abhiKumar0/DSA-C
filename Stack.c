#include <stdio.h>
#include <stdlib.h>

struct Stack {
  int size;
  int top;
  int * arr;
};

int isEmpty (struct Stack * ptr){
  if (ptr->top == -1) {
    return 1;
  }
  return 0;
}

int isFull(struct Stack *ptr) {
  if (ptr->top == ptr->size-1) {
    return 1;
  }
  return 0;
}

int push(struct Stack * s, int value) {
  if (isFull(s)) {
    printf("Stack Overflow!!");
    return -1;
  }
  s->top++;
  s->arr[s->top] = value;
  return 0;
}

int pop(struct Stack * s) {
  if(isEmpty(s)) {
    printf("Stack Underflow!!");
    return -1;
  }
  int val = s->arr[s->top];
  s->top--;

  return val;
}

int peek(struct Stack * s, int n){

  if (n > s->top + 1 || n < 0) {
    return -1;
  }

  return s->arr[s->top - n + 1];
  
}

int stackTop(struct Stack * s) {
  return s->arr[s->top];
}

int stackBottom(struct Stack * s) {
  return s->arr[0];
}






int main () {

  struct Stack *s;
  s->size = 20;
  s->top = -1;
  s->arr = (int *) malloc (s->size * sizeof(int));


  push(s, 7);
  push(s, 2);
  push(s, 3);
  push(s, 8);

  // int x = pop(s);

  // int peek1 = peek(s, 2);

  int top = stackTop(s);
  int bottom = stackBottom(s);

  for (int i = s->top; i >= 0; i--) {
    printf("Element: %d\n", s->arr[i]);
  }

  // printf("Removed: %d", x);
  // printf("The Element using peek is: %d", peek1);
  printf("The element on top of the stack: %d\n", top);
  printf("The element on bottom of the stack: %d\n", bottom);

  return 0;
}