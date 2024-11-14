#include <stdio.h>
#include <stdlib.h>

struct Node *f = NULL;
struct Node *r = NULL;

struct Node{
  int data;
  struct Node *next;
};

void linkedListTraversal(struct Node *ptr) {
  //Checking if ptr is null or still have another node
  while(ptr != NULL){
    //printing the node
    printf("Element: %d\n", ptr->data);
    //asigning the next node to current ptr
    ptr = ptr->next;
  }
}

void enQueue(int val) {
  struct Node *ptr = (struct Node *) malloc (sizeof(struct Node));

  if (ptr == NULL) {
    printf("Queue full!");
  } else 
  {
      ptr->data = val;
      ptr->next = NULL;
      if (f == NULL) {
        f = r = ptr;
    } else {
        r->next = ptr;
        r = ptr;
    }
    printf("Added %d\n", val);
  }
}

int deQueue () {
  int val = -1;
  struct Node *ptr = f;
  if (f == NULL) {
    printf("Queue empty");
  }
  f = f->next;
  val = ptr->data;
  free(ptr);
  return val;
}

int main () {
  linkedListTraversal(f);
  enQueue(2);
  enQueue(22);
  enQueue(26);
  enQueue(45);
  enQueue(76);
  enQueue(92);
  // deQueue();
  // deQueue();
  linkedListTraversal(f);
  return 0;
}