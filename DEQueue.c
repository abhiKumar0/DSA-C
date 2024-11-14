#include <stdio.h>
#include <stdlib.h>

struct Queue {
  int size;
  int f;
  int r;
  int *arr;
};

int isEmpty(struct Queue *q) {
  if (q->f == q->r) {
    return 1;
  }
  return 0;
};

int isFull(struct Queue *q) {
  if (q->f == -1 && q->r == q->size - 1) {
    return 1;
  }
  return 0;
};

void enqueueFront(struct Queue *q, int val){
  if (q->f == -1) {
    printf("No space left!\n");
  } else 
  {
    q->arr[q->f] = val;
    q->f--;
  };

  }

void enqueueRear(struct Queue *q, int val){
  if (q->r == q->size - 1) {
    printf("No space left!\n");
  } else 
  {
    q->r++;
    q->arr[q->r] = val;
  }
};

int dequeueFront(struct Queue *q) {
  int val  = -1;
  if (isEmpty(q)) {
    printf("Queue is empty!\n");
  } else {
    val = q->arr[q->f];
    q->f++;
  }
  return val;
}

int dequeueRear(struct Queue *q) {
  int val  = -1;
  if (isEmpty(q)) {
    printf("Queue is empty!\n");
  } else {
    val = q->arr[q->r];
    q->r--;
  }
  return val;
}

void printDEQueue(struct Queue *q) {
  if (isEmpty(q)) {
    printf("Queue is empty!\n");
  }
  for (int i = q->f + 1; i<=q->r; i++) {
    printf("Element: %d\n", q->arr[i]);
  }
}

int main() {
  struct Queue q;
  q.r = q.f = -1;
  q.size = 100;
  q.arr = (int *) malloc (q.size * sizeof(int));
  printDEQueue(&q);
  enqueueRear(&q, 32);
  enqueueRear(&q, 2);
  enqueueRear(&q, 21);
  enqueueRear(&q, 9);
  enqueueRear(&q, 3);
  dequeueFront(&q);
  dequeueFront(&q);
  enqueueFront(&q, 1);
  printDEQueue(&q);
  return 0;
}