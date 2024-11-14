#include <stdio.h>
#include <stdlib.h>

struct Stack {
  int data;
  struct Stack * next;
};

struct Stack *top = NULL;

void traversal(struct Stack * ptr) {
  while (ptr != NULL)
  {
    printf("Element: %d\n", ptr->data);
    ptr = ptr->next;
  }
  
}

int isEmpty(struct Stack *top) {
  if (top == NULL) {
    return 1;
  }

  return 0;
}

int isFull(struct Stack *top) {
  struct Stack *p = (struct Stack *) malloc (sizeof(struct Stack));
  if (p == NULL) {
    return 1;
  }

  return 0;
}

struct Stack * push(struct Stack *top, int value) {
  struct Stack * ptr = (struct Stack *) malloc (sizeof(struct Stack));
  // struct Stack *p = top;
  ptr->data = value;

  if (isFull(top)) {
    printf("Stack Overflow\n");
  } else {
    ptr->next = top;
    top = ptr;
    return top;

  }

}

int pop (struct Stack** top) {
  if (isEmpty(top)) {
    printf("Stack Underflow\n");
  } else {
    struct Stack * p = top;
    *top = (*top)->next;
    int n = p->data;
    free(p);
    
    return n;
   }
}

int peek (struct Stack * top, int num) {
  struct Stack * p = top;
  int i = 0;

  while (p != NULL) {
    if (i+1 == num) {
      break;
    }
    p = p->next;
    i++;
  }

  return p->data;
}


int main() {

  top = push(top, 1);
  top = push(top, 4);
  top = push(top, 7);
  top = push(top, 8);
  top = push(top, 11);

  // int element= pop(top);
  // element = pop(top);

  int n = peek(top, 2);
  
  traversal(top);
  printf("Peeked element is: %d\n", n);
  // printf("Popped element is: %d\n", element);

  return 0;
}