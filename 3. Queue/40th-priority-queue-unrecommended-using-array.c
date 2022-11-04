// Priority Queue using Array
// Normal Insertion & Priority wise Deletion (Unrecommended)

#include <stdio.h>
#define MAX 5

struct priData{
    int val;
    int pri;
};

typedef struct
{
    struct priData data[MAX];
    int front;
    int rear;
} pQueue;

void init(pQueue *q)
{
    q->front = q->rear = -1;
}

int insert(pQueue *q, int v, int p)
{
    if (q->rear == MAX - 1)
    { // Queue Full
        printf("Queue is full.");
        return 1;
    }
    else if (q->rear == -1)
    { // Queue Empty
        q->front = q->rear = 0;
        q->data[q->rear].val = v;
        q->data[q->rear].pri = p;
    }
    else
    {
        q->rear++;
        q->data[q->rear].val = v;
        q->data[q->rear].pri = p;
    }
    return 0;
}

int delete(pQueue *q, int *v){
    if(q->rear == -1){
        printf("Queue is Empty.");
        return 1;
    }else if(q->front == q->rear){
        *v = q->data[q->front].val;
        q->front = q->rear = -1;
    }else{
        int min = q->front;
        int i, j;
        for(i = q->front+1; i <= q->rear; i++){
            if(q->data[min].pri > q->data[i].pri){
                min = i;
            }
        }
        *v = q->data[min].val;
        q->data[min].val = q->data[q->rear].val;
        q->rear--;
    }
    return 0;
}

void display(pQueue q)
{
    if (q.rear == -1)
    { // Queue Empty
        printf("Queue is empty.");
        return;
    }
    for (int i = q.front; i <= q.rear; i++)
    {
        printf("%d ", q.data[i].val);
    }
}

int main()
{
    int n, d, k1, k2;
    pQueue q1;
    init(&q1);

    k1 = insert(&q1, 10, 1);
    k1 = insert(&q1, 20, 2);
    k1 = insert(&q1, 30, 3);
    k1 = insert(&q1, 40, 4);

    k2 = delete(&q1, &d);
    printf("The deleted element is: %d\n", d);

    printf("The elements in the queue: ");
    display(q1);

    return 0;
}