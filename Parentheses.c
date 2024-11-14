#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack {
  int size;
  int top;
  char * str;
};

int push(struct Stack *s, char x) {
  if (s->top == s->size - 1) {
    return 0;
  }
  s->top++;
  s->str[s->top] = x;
  return 1;
};

int pop(struct Stack *s) {
  if (s->top == -1) {
    return 0;
  }
  s->top--;
  return 1;
};

int match(char a, char b){
  if (a == '(' && b == ')') {
    return 1;
  }
  if (a == '{' && b == '}') {
    return 1;
  }
  if (a == '[' && b == ']') {
    return 1;
  }
  return 0;
}

int parantheses(char *s) {
  struct Stack *sp;
  sp->size = 100;
  sp->top = -1;
  sp->str = (char *) malloc (sp->size * sizeof(char));

  for (int i = 0; s[i] != '\0'; i++) {
    if ( s[i] == '(') {
      push(sp, '(');
    } else if (s[i] == ')'){
      if (sp->top == -1) {
        return 0;
      }
      pop(sp);
    }
  }

  if (sp->top == -1) return 1;
  return 0;
}

int multiParantheses(char *s) {
  struct Stack *sp;
  sp->size = 100;
  sp->top = -1;
  sp->str = (char *) malloc (sp->size * sizeof(char));

  char popped_ch;

  for (int i = 0; s[i] != '\0'; i++) 
  {
    if ( s[i] == '(' || s[i] == '{' || s[i] == '[') {
      push(sp, s[i]);
    } 
    else if (s[i] == ')' || s[i] == '}' || s[i] == ']'){
      if (sp->top == -1) {
        return 0;
      }
      popped_ch = pop(sp);
      if (!match(popped_ch, s[i])) {
        return 0;
      }
    }
  }

  if (sp->top == -1) return 1;
  return 0;
}


int main() {

  char * strLine = "(3+2*(54/9)-6)";

  if (multiParantheses(strLine)) {
    printf("Parantheses are matching!.\n");
  } else {
    printf("Parantheses are not matching!.\n");
  }

  return 0;
}