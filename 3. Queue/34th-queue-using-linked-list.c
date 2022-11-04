// Queue using Linked List

#include <stdio.h>
#include <stdlib.h>
#define MAX 5

struct node{
    int data;
    struct node *next;
};

typedef struct{
    struct node *front;
    struct node *rear;
}queue;

void init(queue *q){
    q->front = q->rear = NULL;
}

int insert(queue *q, int val){
    struct node *curr = malloc(sizeof(struct node));
    curr->next = NULL;
    if(curr == NULL){
        printf("Queue is Full.");
        return 1;
    }
    if(q->rear == NULL){
        curr->data = val;
        q->front = q->rear = curr;
    }else{
        curr->data = val;
        q->rear->next = curr;
        q->rear = curr;
    }
    return 0;
}

int delete(queue *q, struct node **ptr1){
    if(q->rear == NULL){
        printf("Queue is Empty.");
        return 1;
    }
    if(q->front == q->rear){
        *ptr1 = q->front;
        q->front = q->rear = NULL;
    }else{
        *ptr1 = q->front;
        q->front = q->front->next;
    }
    return 0;
}

void display(queue q){
    struct node *ptr;
    if(q.front == NULL){
        printf("Queue is Empty.");
        return;
    }
    for(ptr = q.front; ptr != NULL; ptr = ptr->next){
        printf("%d ", ptr->data);
    }
}

int main(){
    int n, v, k1, k2;
    struct node *ptr;
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

    k2 = delete(&q1, &ptr);
    printf("The deleted element is: %d\n", ptr->data);

    printf("The elements in the queue: ");
    display(q1);

    return 0;
}