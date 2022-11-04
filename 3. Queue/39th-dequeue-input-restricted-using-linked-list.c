// Double Ended Queue (Dequeue) using Linked List.
// Input Restricted

#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

typedef struct{
    struct node *front;
    struct node *rear;
}deQueue;

void init(deQueue *q){
    q->front = NULL;
    q->rear = NULL;
}

int insert(deQueue *q, int val){
    struct node *curr = malloc(sizeof(struct node));
    curr->next = NULL;
    curr->data = val;
    if(curr == NULL){
        printf("Queue is Full.");
        return 1;
    }
    if(q->rear == NULL){
        q->front = q->rear = curr;
    }else{
        q->rear->next = curr;
        q->rear = curr;
    }
    return 0;
}

int delete(deQueue *q, int *val, int side){
    printf("Enter 1 for rear side and 0 for front side deletion: ");
    scanf("%d", &side);
    if(q->front == NULL){
        printf("Queue is Empty.");
        return 1;
    }
    if(q->front == q->rear){
        *val = q->front->data;
        q->front = q->rear = NULL;
    }
    else
    {
        struct node *ptr;
        if(side == 0){
            ptr = q->front;
            *val = q->front->data;
            q->front = q->front->next;
            free(ptr);
        }
        else
        {
            ptr =  q->front;
            while(ptr->next != q->rear){
                ptr = ptr->next;
            }
            *val = q->rear->data;
            free(q->rear);
            q->rear = ptr;
            ptr->next = NULL;
        }
    }
    return 0;
}

void display(deQueue q){
    if(q.front == NULL){
        printf("Queue is Empty.");
        return;
    }
    struct node *ptr;
    for(ptr = q.front; ptr != NULL; ptr = ptr->next){
        printf("%d ", ptr->data);
    }
}

int main(){
    int v, d, k1, k2, side;
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