// Circular Double Ended Queue (Circular Dequeue) using Linked List
// Input Restricted

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

int insert(cQueue *q, int val){
    struct node *curr = malloc(sizeof(struct node));
    curr->next = NULL;
    if(curr == NULL){
        printf("Queue is Full.");
        return 1;
    }
    if(q->rear == NULL){
        curr->data = val;
        curr->next = curr;
        q->rear = curr;

    }else{
        curr->data = val;
        curr->next = q->rear->next;
        q->rear->next = curr;
        q->rear = curr;
    }
    return 0;
}

int delete(cQueue *q, int *val, int side){
    printf("Enter 1 for rear side and 0 for front side deletion: ");
    scanf("%d", &side);
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
        if(side == 0){
            *val = q->rear->next->data;
            q->rear->next =  ptr->next;
            free(ptr);
        }else{
            *val = q->rear->data;
            while(ptr->next != q->rear){
                ptr = ptr->next;
            }
            ptr->next = q->rear->next;
            free(q->rear);
            q->rear = ptr;
        }
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

    k1 = insert(&q1, 10);
    k1 = insert(&q1, 20);
    k1 = insert(&q1, 30);
    k1 = insert(&q1, 40);
    k1 = insert(&q1, 50);

    k2 = delete(&q1, &d, side);
    printf("The deleted element is: %d\n", d);

    k1 = insert(&q1, 60);

    printf("The elements in the queue: ");
    display(q1);

    return 0;
}