// Circular Double Ended Queue (Circular Dequeue) using Array
// Output Restricted

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

int insert(cQueue *q, int val, int side){
    printf("Enter 1 for rear side and 0 for front side insertion: ");
    scanf("%d", &side);
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
        if(side == 0){
            q->front = (q->front + MAX -1)%MAX;
            q->data[q->front] = val;
        }else{
            q->rear = (q->rear + 1)%MAX;
            q->data[q->rear] = val;
        }
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
    int n, v, d, k1, k2, side;
    cQueue q1;
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