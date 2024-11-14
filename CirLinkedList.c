#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node * next;
};

void linkedListTraversalCLL(struct Node *head) {
  struct Node *p = head;

  //Checking if ptr is null or still have another node
  do {
    //printing the node
    printf("Element: %d\n", p->data);
    //asigning the next node to current ptr
    p = p->next;
  }while(p != head);
}

struct Node * insertAtFirstInCLL(struct Node * head, int data){
  struct Node * ptr = (struct Node *) malloc (sizeof(struct Node)); // Asking heap for the Allocating memory
  struct Node *p = head;
  ptr->data = data;
  ptr->next = head;

  do {
    p = p->next;
  }while(p->next != head);
  p->next = ptr;

  return ptr;
}


struct Node * insertAtIndexInCLL(struct Node * head, int data, int index){
  struct Node * ptr = (struct Node *) malloc (sizeof(struct Node)); // Asking heap for the Allocating memory
  struct Node *p = head;

  int i = 0;
  do {
    p = p->next;
    if (i == index) {
      break;
    }
    i++;
  }while(i != 0);
  p->next = ptr;

  return ptr;
}



int main() {

  //Allocating memory for nodes in the linked list in heap
  struct Node *head = (struct Node *) malloc (sizeof(struct Node));
  struct Node *second = (struct Node *) malloc (sizeof(struct Node));
  struct Node *third = (struct Node *) malloc (sizeof(struct Node));
  struct Node *forth = (struct Node *) malloc (sizeof(struct Node));
  struct Node *fifth = (struct Node *) malloc (sizeof(struct Node));

  //Link first and second nodes
  head->data = 7;
  head->next = second;

  //Link first and second nodes
  second->data = 47;
  second->next = third;

  //Link first and second nodes
  third->data = 73;
  third->next = forth;

  forth->data = 89;
  forth->next = fifth;

  //Terminate the list at the fifth node
  fifth->data = 119;
  fifth->next = head;

  head = insertAtFirstInCLL(head, 2);

  linkedListTraversalCLL(head);
  

  return 0;
}