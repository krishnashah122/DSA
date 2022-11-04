// Circular Double Ended Queue (Circular Dequeue) using Linked List
// Output Restricted

#include <stdio.h>
#include <stdlib.h>
#define MAX 10

struct node{
    int data;
    struct node *next;
};

typedef struct{
    struct node *rear;
}cQueue;

void init(cQueue *q){
    q->rear = NULL;
}

int insert(cQueue *q, int val, int side){
    printf("Enter 1 for rear side and 0 for front side deletion: ");
    scanf("%d", &side);
    struct node *curr = malloc(sizeof(struct node));
    curr->data = val;
    curr->next = NULL;
    if(curr == NULL){
        printf("Queue is Full.");
        return 1;
    }
    if(q->rear == NULL){
        curr->next = curr;
        q->rear = curr;

    }else{
        if(side == 0){
            curr->next = q->rear->next;
            q->rear->next = curr;
        }else{
            curr->next = q->rear->next;
            q->rear->next = curr;
            q->rear = curr;
        }
    }
    return 0;
}

int delete(cQueue *q, int *val){
    if(q->rear == NULL){
        printf("Queue is Empty.");
        return 1;
    }
    if(q->rear->next == q->rear){
        *val = q->rear->data;
        free(q->rear);
        q->rear = NULL;
    }else{
        struct node *ptr = q->rear->next;
        *val = q->rear->next->data;
        q->rear->next =  ptr->next;
        free(ptr);
    }
    return 0;
}

void display(cQueue q){
    if(q.rear == NULL){
        printf("Queue is Empty.");
        return;
    }
    struct node *ptr = q.rear->next;
    while(ptr != q.rear){
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("%d", ptr->data);
}

int main(){
    int n, v, d, side, k1, k2;
    cQueue q1;
    init(&q1);

    k1 = insert(&q1, 10, side);
    k1 = insert(&q1, 20, side);
    k1 = insert(&q1, 30, side);

    k2 = delete(&q1, &d);
    printf("The deleted element is: %d\n", d);

    printf("The elements in the queue: ");
    display(q1);

    return 0;
}