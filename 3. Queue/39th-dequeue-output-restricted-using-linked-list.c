// Double Ended Queue (Dequeue) using Linked List.
// Output Restricted

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

int insert(deQueue *q, int val, int side){
    printf("Enter 1 for rear side and 0 for front side insertion: ");
    scanf("%d", &side);
    struct node *curr = malloc(sizeof(struct node));
    curr->data = val;
    curr->next = NULL;
    if(curr == NULL){
        printf("Queue is Full.");
        return 1;
    }
    if(q->rear == NULL){
        q->front = q->rear = curr;
    }else{
        if(side == 0){
            curr->next = q->front;
            q->front = curr;
        }else{
            curr->next = q->rear->next;
            q->rear->next = curr;
            q->rear = curr;
        }
    }
    return 0;
}

int delete(deQueue *q, int *val){
    if(q->rear == NULL){
        printf("Queue is Empty.");
        return 1;
    }
    if(q->front == q->rear){
        *val = q->front->data;
        q->front = q->rear = NULL;
    }else{
        *val = q->front->data;
        q->front = q->front->next;
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

    k1 = insert(&q1, 10, side);
    k1 = insert(&q1, 20, side);
    k1 = insert(&q1, 30,side);

    k2 = delete(&q1, &d);
    printf("The deleted element is: %d\n", d);

    printf("The elements in the queue: ");
    display(q1);
    
    return 0;
}