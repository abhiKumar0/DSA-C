#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node * next;
};
// *********** INSERTION IN LINKED LIST ****************
/*
  1. Inserting at first 
  2. Inserting at a given index
  3. Inserting at the end
  4. Inserting after the first node with given value
*/

void linkedListTraversal(struct Node *ptr) {
  
  //Checking if ptr is null or still have another node
  while(ptr != NULL){
    //printing the node
    printf("Element: %d\n", ptr->data);
    //asigning the next node to current ptr
    ptr = ptr->next;
  }
}

struct Node * insertAtFirst(struct Node * head, int data){
  struct Node * ptr = (struct Node *) malloc (sizeof(struct Node)); // Asking heap for the Allocating memory
  ptr->next = head;
  ptr->data = data;
  return ptr;
}

struct Node * insertAtIndex(struct Node * head, int data, int index) {
  struct Node *ptr = (struct Node *) malloc (sizeof(struct Node));
  struct Node *p = head;
  int i = 0;

  while (i != index - 1) {
    p = p->next;
    i++;
  }

  ptr->data = data;
  ptr->next = p->next;
  p->next = ptr;

  return head;

}

struct Node * insertAtEnd(struct Node *head, int data) {
  struct Node *ptr = (struct Node *) malloc (sizeof(struct Node));

  struct Node *p = head;

  while (p->next != NULL) {
    p = p->next;
  }
  ptr->data = data;
  p->next = ptr;
  ptr->next = NULL;

  return head;
}

struct Node * insertAfterNode(struct Node *head, struct Node *prevNode, int data) {
  struct Node *ptr = (struct Node *) malloc (sizeof(struct Node));

  ptr->data = data;
  ptr->next = prevNode->next;
  prevNode->next = ptr;
  return head;
}

//***************** DELETION IN LINKED LIST ****************
/*
  1. Deleting the first node
  2. Deleting the node at the index
  3. Deleting the last Node
  4. Deleting the first node with given value
*/

//Deleting the first node
struct Node * deletingFirst(struct Node *head) {
  struct Node *p = head;
  head = head->next;
  free(p);

  return head;
}

//Deleting the node at the index
struct Node * deleteAtIndex(struct Node *head, int index) {
  struct Node *p = head;
  struct Node *q;
  int i = 0;
  while (i != index - 1) {
    p = p->next;
    i++;
  }
  q = p->next;
  p->next = q->next;
  free(q);
  return head;
}

//Deleting the last Node
struct Node * deletingLast(struct Node *head) {
  struct Node *p = head;
  struct Node *q;
  while (p->next->next != NULL) {
    p = p->next;
  }
  q = p->next;
  p->next = NULL;
  free(q);
  return head;
}

//Deleting the first node with given value
struct Node * deleteAccValue(struct Node *head, int value) {
  struct Node *p = head;
  struct Node *q;
  int i = 0;
  while (p->next->data != value) {
    p = p->next;
    i++;
  }
  q = p->next;
  if (q->next != NULL) {
    p->next = q->next;
  } else {
    p->next = NULL;
  }

  free(q);
  return head;
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
  fifth->next = NULL;

  printf("Linked list before insertion\n");
  linkedListTraversal(head);

  printf("\nLinked list after insertion\n");
  //******* INSERTION ********
  // head = insertAtFirst(head, 3);
  // head = insertAtIndex(head, 3, 2);
  // head = insertAtEnd(head, 1003);
  // head = insertAfterNode(head, head, 1003);


  //******* DELETION ********
  // head = deletingFirst(head);
  // head = deleteAtIndex(head, 3);
  // head = deletingLast(head);
  head = deleteAccValue(head, 119);

  linkedListTraversal(head);

  return 0;
}