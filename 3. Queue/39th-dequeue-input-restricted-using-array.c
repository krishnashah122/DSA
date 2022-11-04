// Double Ended Queue (Dequeue) using Array.
// Input Restricted

#include <stdio.h>
#define MAX 5

typedef struct
{
    int data[MAX];
    int front;
    int rear;
} deQueue;

void init(deQueue *q)
{
    q->front = q->rear = -1;
}

int insert(deQueue *q, int val)
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

int delete (deQueue *q, int *val, int side)
{
    printf("Enter 1 for rear side and 0 for front side deletion: ");
    scanf("%d", &side);
    if (q->rear == -1)
    {
        printf("Queue is Empty.");
        return 1;
    }
    if (q->front == q->rear)
    {
        *val = q->data[q->front];
        q->front = q->rear = -1;
    }
    else
    {
        if (side == 0)
        {
            *val = q->data[q->front];
            q->front++;
        }
        else
        {
            *val = q->data[q->rear];
            q->rear--;
        }
    }
    return 0;
}

void display(deQueue q)
{
    if (q.rear == -1)
    {
        printf("Queue is Empty.");
        return;
    }
    for (int i = q.front; i <= q.rear; i++)
    {
        printf("%d ", q.data[i]);
    }
}

int main()
{
    int n, v, d, side, k1, k2;
    deQueue q1;
    init(&q1);

    k1 = insert(&q1, 10);
    k1 = insert(&q1, 20);
    k1 = insert(&q1, 30);

    k2 = delete(&q1, &d, side);
    printf("The deleted element is: %d\n", d);

    printf("The elements in the queue: ");
    display(q1);

    return 0;
}