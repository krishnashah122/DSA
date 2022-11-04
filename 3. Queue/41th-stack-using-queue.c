// Stack using Queue

#include <stdio.h>
#define MAX 5

typedef struct
{
    int data[MAX];
    int front;
    int rear;
} queue;

void init(queue *q)
{
    q->front = q->rear = -1;
}

int insert(queue *q, int val)
{
    if (q->rear == MAX - 1)
    { // Queue Full
        printf("Queue is full.");
        return 1;
    }
    else if (q->rear == -1)
    { // Queue Empty
        q->front = q->rear = 0;
        q->data[q->rear] = val;
    }
    else
    {
        q->rear++;
        q->data[q->rear] = val;
    }
    return 0;
}

int delete(queue *q, int *val){
    if(q->rear == -1){
        printf("Queue is Empty.");
        return 1;
    }else if(q->front == q->rear){
        *val = q->data[q->front];
        q->front = q->rear = -1;
    }else{
        *val = q->data[q->front];
        q->front++;
    }
    return 0;
}

int isEmpty(queue q){
    if(q.rear == -1){
        return 1;
    }else{
        return 0;
    }
}

int push(queue *q1, queue *q2, int val){
    if(q1->rear == MAX-1){
        printf("Queue Full.");
        return 1;
    }
    insert(q1, val);
    return 0;
}

int pop(queue *q1, queue *q2, int *val){
    if(q1->rear == -1){
        printf("Queue is Empty.");
        return 1;
    }
    if(q1->front == q1->rear){
        *val = q1->data[q1->front];
        q1->front = q1->rear = -1;
    }else{
        int d;
        while(q1->front != q1->rear){
            delete(q1, &d);
            insert(q2, d);
        }
        *val = q1->data[q1->front];
        q1->front = q1->rear = -1;
        while(!isEmpty(*q2)){
            delete(q2, &d);
            insert(q1, d);
        }
    }
}

void display(queue q)
{
    if (q.rear == -1)
    { // Queue Empty
        printf("Queue is empty.");
        return;
    }
    for (int i = q.front; i <= q.rear; i++)
    {
        printf("%d ", q.data[i]);
    }
}

int main()
{
    int n, v, d, k1, k2;
    queue q1;
    queue q2;
    init(&q1);
    init(&q2);

    k1 = push(&q1, &q2, 10);
    k1 = push(&q1, &q2, 20);
    k1 = push(&q1, &q2, 30);
    k1 = push(&q1, &q2, 40);
    k1 = push(&q1, &q2, 50);

    k2 = pop(&q1, &q2, &d);
    printf("The deleted element is: %d\n", d);

    printf("The elements: ");
    display(q1);

    return 0;
}