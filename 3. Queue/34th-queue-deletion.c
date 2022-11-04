// Queue Deletion by proper memory utilization

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
        for(int i = q->front+1; i <= q->rear; i++){
            q->data[i-1] = q->data[i];
        }
        q->rear--;
    }
    return 0;
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

    printf("The elements in the queue: ");
    display(q1);

    return 0;
}