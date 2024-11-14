#include <stdio.h>
#include <stdlib.h>


struct Node{
  int data;
  struct Node *next;
};

struct Queue {
  struct Node *front;
  struct Node *rear;
};

int queueEmpty(struct Queue *q) {
  if (q->front == NULL) {
    return 1;
  }
  return 0;
};

int queueFull() {
  struct Node *ptr = (struct Node *) malloc (sizeof(struct Node));
  if (ptr == NULL) {
    return 1;
  }
  return 0;
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

void enQueue(struct Queue *q, int val) {
  struct Node *ptr = (struct Node *) malloc (sizeof(struct Node));

  if (queueFull()) {
    printf("Queue full!");
  } else {
      ptr->data = val;
      ptr->next = NULL;
      if (q->front == NULL) {
        q->rear = q->front = ptr;
    } else {
        q->rear->next = ptr;
        q->rear = ptr;
    }
    printf("Added %d\n", val);
  }
}

int deQueue (struct Queue *q) {
  int val = -1;
  struct Node *ptr = (struct Node *) malloc (sizeof(struct Node));
  if (queueEmpty(q)) {
    printf("Queue empty");
  }
  ptr = q->front;
  q->front = q->front->next;
  val = ptr->data;
  free(ptr);
  return val;
}

int main() {
  struct Queue q;
  q.front = q.rear = NULL;

  linkedListTraversal(&q.front);

  enQueue(&q, 7);
  enQueue(&q, 22);
  enQueue(&q, 42);
  enQueue(&q, 56);
  enQueue(&q, 34);

  // printf("Dequeued value is %d\n", deQueue(&q));
  linkedListTraversal(&q.front);
  printf("end");

  return 0;
}