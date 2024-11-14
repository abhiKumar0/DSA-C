#include <stdio.h>
#include <stdlib.h>

struct Queue {
  int size;
  int f;
  int r;
  int * arr;
};

void enQueue(struct Queue *q, int val) {
  if ((q->r+1)%q->size == q->f) {
    printf("Queue is full!");
  }

  q->r = (q->r+1)%q->size;
  q->arr[q->r] = val;
}

int deQueue(struct Queue *q) {
  if (q->r == q->f) {
    printf("Queue is empty!");
  }
  q->f = (q->f+1) % q->size;
  int val = q->arr[q->f];
  return val;
}

void show (struct Queue *q) {
  if (q->r == q->f) {
    printf("Queue is empty");
  } 
  else if (q->r >= q->f) {
    for (int i = q->f; i<= q->r; i++) {
      printf("%d\n", q->arr[i]);
    }
  } else {
    for (int i = q->f; i<= q->r; i++) {
      printf("%d\n", q->arr[i]);
    }
    for (int i = 0; i<= q->r; i++) {
      printf("%d\n", q->arr[i]);
    }
  }

}

int main() {
  struct Queue q;
  q.size = 10;
  q.f = q.r = 0;
  q.arr = (int *) malloc (q.size * sizeof(int));

  enQueue(&q, 12);
  enQueue(&q, 14);
  enQueue(&q, 18);
  enQueue(&q, 28);
  enQueue(&q, 8);
  enQueue(&q, 68);
  enQueue(&q, 78);
  enQueue(&q, 7);
  enQueue(&q, 37);
  // deQueue(&q);
  // deQueue(&q);
  // deQueue(&q);
  enQueue(&q, 337);
  
  // show(&q);

  return 0;
}