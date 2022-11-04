// Double Ended Queue (Dequeue) using Array.
// Output Restricted

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

int insert(deQueue *q, int val, int side)
{
    printf("Enter 1 for rear side and 0 for front side insertion: ");
    scanf("%d", &side);
    if (q->front == -1)
    {
        q->front = q->rear = 0;
        q->data[q->rear] = val;
    }
    else if (side == 0)
    {
        if (q->front == 0)
        {
            return 1;

            //Shifts elements to right side in order to insert element at front end. Time Complexity [O(n)]
            // for(int i = q->rear; i >= q->front; i--){
            //     q->data[i+1] = q->data[i];
            // }
            // q->rear++;
            // q->data[q->front] = val;
        }
        else
        {
            q->front--;
            q->data[q->front] = val;
        }
    }
    else
    {
        if (q->rear == MAX - 1)
        {
            return 1;

            //Shifts elements to left side in order to insert element at rear end. Time Complexity [O(n)]
            // for(int i = q->front; i <= q->rear; i++){
            //     q->data[i-1] = q->data[i];
            // }
            // q->data[q->rear] = val;
            // q->front--;
        }
        else
        {
            q->rear++;
            q->data[q->rear] = val;
        }
    }
    return 0;
}

int delete (deQueue *q, int *val)
{
    if (q->rear == -1)
    {
        printf("Queue is Empty.");
        return 1;
    }
    else if (q->front == q->rear)
    {
        *val = q->data[q->front];
        q->front = q->rear = -1;
    }
    else
    {
        *val = q->data[q->front];
        q->front++;
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

    k1 = insert(&q1, 10, side);
    k1 = insert(&q1, 20, side);
    k1 = insert(&q1, 30, side);
    k1 = insert(&q1, 40, side);
    k1 = insert(&q1, 50, side);

    k2 = delete(&q1, &d);
    printf("The deleted element is: %d\n", d);

    insert(&q1, 60, side);

    printf("The elements in the queue: ");
    display(q1);

    return 0;
}