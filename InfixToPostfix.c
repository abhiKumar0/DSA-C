#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack {
  int top;
  int size;
  char *arr;
};

int push(struct Stack *s, char x) {
  if (s->top == s->size - 1) {
    return 0;
  }
  s->top++;
  s->arr[s->top] = x;
  return 1;
};

int pop(struct Stack *s) {
  if (s->top == -1) {
    return 0;
  }
  s->top--;
  return 1;
};

int isEmpty (struct Stack * ptr){
  if (ptr->top == -1) {
    return 1;
  }
  return 0;
}

int stackTop(struct Stack * s) {
  return s->arr[s->top];
}

int prec(char ch) {
  if (ch == '*' || ch == '/')
    return 3;
  else if (ch == '+' || ch == '-')
    return 2;
  else
    return 0;
}

int isOperator (char ch){
  if (ch == '+' || ch == '-' || ch == '*' || ch == '/') 
    return 1;
  return 0;
}


char * intoPo (char * infix) {
  struct Stack *sp = (struct Stack *) malloc (sizeof(struct Stack));
  sp->size = 100;
  sp->top = -1;
  sp->arr = (char *) malloc (sp->size * sizeof(char));

  char * postfix = (char *) malloc (strlen(infix + 1) * sizeof(char));
  int i = 0;
  int j = 0;
  while (infix[i] != '\0') {
    if (!isOperator(infix[i])) {
      postfix[j] = infix[i];
      i++; j++;
    } else {
      if (prec(infix[i]) > prec(stackTop(sp))) {
        push(sp, infix[i]);
        i++;
      } else {
        postfix[j] = pop(sp);
        j++;
      }
    }

  }

  while(!isEmpty(sp)) {
    postfix[j] = pop(sp);
    j++;
  }
  postfix[j] = '\0';
  return postfix;

}


int main() {

  char * ch = "a+b-c/d";
  printf("Postfic is %s", intoPo(ch));

  return 0;
}