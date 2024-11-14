#include <stdio.h>
#include <stdlib.h>

struct Queue {
  int size;
  int r;
  int f;
  int * arr;
};

int isFull (struct Queue *q) {
  if (q->r == q->size - 1) {
    return 1;
  }
  return 0;
}

int isEmpty (struct Queue *q) {
  if (q->r == q->f) {
    return 1;
  }
  return 0;
}

void show (struct Queue *q) {
  for (int i = q->f+1; i<=q->r; i++) {
    printf("%d\n", q->arr[i]);
  }
  printf("\n");
}

void enqueue (struct Queue *q, int value) {
  if (isFull(q)) {
    printf("Queue overflow!");
  }
  q->r++;
  q->arr[q->r] = value;
}

int dequeue(struct Queue *q) {
  if (isEmpty(q)) {
    printf("No element in queue!");
  }
  q->f++;
  int val = q->arr[q->f];
  return val;
}

int main() {
  struct Queue q;
  q.r = q.f = -1;
  q.size = 100;
  q.arr = (int *) malloc (q.size * sizeof(int));

  enqueue(&q, 23);
  enqueue(&q, 43);
  enqueue(&q, 3);
  enqueue(&q, 123);
  // dequeue(&q);
  // dequeue(&q);
  show(&q);

  return 0;
}