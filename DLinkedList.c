#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node * prev;
  struct Node * next;
};

void DLLTraversal(struct Node * ptr) {

  while (ptr != NULL) {
    printf("Element: %d\n", ptr->data);
    if (ptr->next == NULL) {
      break;
    }
    ptr = ptr->next;
  };
  // ptr = ptr->prev;

  printf("************\n");
  while (ptr != NULL) {
    printf("Element: %d\n", ptr->data);
    ptr = ptr->prev;
  }
}

void main() {
//Allocating memory for nodes in the linked list in heap
  struct Node *head = (struct Node *) malloc (sizeof(struct Node));
  struct Node *second = (struct Node *) malloc (sizeof(struct Node));
  struct Node *third = (struct Node *) malloc (sizeof(struct Node));
  struct Node *forth = (struct Node *) malloc (sizeof(struct Node));
  struct Node *fifth = (struct Node *) malloc (sizeof(struct Node));

  //Link first and second nodes
  head->data = 7;
  head->prev = NULL;
  head->next = second;

  //Link first and second nodes
  second->data = 47;
  second-> prev = head;
  second->next = third;

  //Link first and second nodes
  third->data = 73;
  third->prev = second;
  third->next = forth;

  forth->data = 89;
  forth->prev = third;
  forth->next = fifth;

  //Terminate the list at the fifth node
  fifth->data = 119;
  fifth->prev = forth;
  fifth->next = NULL;

  DLLTraversal(head);
}