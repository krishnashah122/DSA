// Priority Queue using Linked List
// Priority wise Insertion & Normal Deletion (Recommended)

#include <stdio.h>
#include <stdlib.h>
#define MAX 5

struct node
{
    int data;
    int pri;
    struct node *next;
};

typedef struct
{
    struct node *front;
    struct node *rear;
} pQueue;

void init(pQueue *q)
{
    q->front = q->rear = NULL;
}

int insert(pQueue *q, int val, int p)
{
    struct node *curr = malloc(sizeof(struct node));
    curr->data = val;
    curr->pri = p;
    curr->next = NULL;
    if (curr == NULL)
    {
        printf("Queue is Full.");
        return 1;
    }
    if (q->rear == NULL)
    {
        q->front = q->rear = curr;
    }
    else
    {
        struct node *ptr;
        if (q->front->pri > p)
        {
            curr->next = q->front;
            q->front = curr;
        }
        else if (q->rear->pri < p)
        {
            q->rear->next = curr;
            q->rear = curr;
        }
        else
        {
            for (ptr = q->front; ptr != NULL; ptr = ptr->next)
            {
                if(ptr->next->pri > p){
                    curr->next = ptr->next;
                    ptr->next = curr;
                    break;
                }
            }
        }
    }
    return 0;
}

int delete (pQueue *q, int *val)
{
    if (q->rear == NULL)
    {
        printf("Queue is Empty.");
        return 1;
    }
    if (q->front == q->rear)
    {
        *val = q->front->data;
        q->front = q->rear = NULL;
    }
    else
    {
        *val = q->front->data;
        q->front = q->front->next;
    }
    return 0;
}

void display(pQueue q)
{
    struct node *ptr;
    if (q.front == NULL)
    {
        printf("Queue is Empty.");
        return;
    }
    for (ptr = q.front; ptr != NULL; ptr = ptr->next)
    {
        printf("%d ", ptr->data);
    }
}

int main()
{
    int n, v, d, k1, k2;
    struct node *ptr;
    pQueue q1;
    init(&q1);

    k1 = insert(&q1, 10, 1);
    k1 = insert(&q1, 20, 2);
    k1 = insert(&q1, 30, 3);
    k1 = insert(&q1, 40, 4);

    k2 = delete (&q1, &d);
    printf("The deleted element is: %d\n", d);

    printf("The elements in the queue: ");
    display(q1);

    return 0;
}