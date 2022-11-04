// Circular Queue using Array

#include <stdio.h>
#define MAX 5

typedef struct{
    int data[MAX];
    int front;
    int rear;
}cQueue;

void init(cQueue *q){
    q->front = q->rear = -1;
}

int insert(cQueue *q, int val){
    if(q->front == (q->rear+1)%MAX)
    {
        printf("Queue is Full.");
        return 1;
    }
    else if(q->rear == -1)
    {
        q->front++;
        q->rear++;
        q->data[q->rear] = val;
    }
    else
    {
        q->rear = (q->rear + 1)%MAX;
        q->data[q->rear] = val;
    }
    return 0;
}

int delete(cQueue *q, int *val){
    if(q->rear == -1){
        printf("Queue is Empty.");
        return 1;
    }
    else if(q->front == q->rear)
    {
        *val = q->data[q->front];
        q->front = q->rear = -1;
    }
    else
    {
        *val = q->data[q->front];
        q->front = (q->front + 1)%MAX;
    }
}

void display(cQueue q)
{
    if (q.rear == -1)
    { // cQueue Empty
        printf("Queue is empty.");
        return;
    }
    int i;
    for (i = q.front; i != q.rear; i = (i+1)%MAX)
    {
        printf("%d ", q.data[i]);
    }
    printf("%d", q.data[i]);
}

int main(){
    int n, v, d, k1, k2;
    cQueue q1;
    init(&q1);
    printf("How many element you want to enter in queue? ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter element: ");
        scanf("%d", &v);
        k1 = insert(&q1, v);
    }

    k2 = delete(&q1, &d);
    printf("The deleted element is: %d\n", d);
    insert(&q1, 6);

    printf("The elements in the queue: ");
    display(q1);
 

    return 0;
}