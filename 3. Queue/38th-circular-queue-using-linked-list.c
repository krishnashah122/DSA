// Circular Queue using Linked List

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
    int n, v, d, k1, k2;
    cQueue q1;
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