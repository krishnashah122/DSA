//Stack Implementation using Linked List

#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

typedef struct{
    struct node *top;
}stack;

void init(stack *s){
    s->top = NULL;
}

int push(stack *s, int val){
    struct node *curr = malloc(sizeof(struct node));
    if(curr == NULL){
        printf("Overflow");
        return 1;
    }
    curr->data = val;
    curr->next = s->top;
    s->top = curr;
    return 0;
}

int pop(stack *s, struct node **p){
    if(s->top == NULL){
        printf("Underflow");
        return 1;
    }
    struct node *ptr1;
    ptr1 = s->top;
    s->top = s->top->next;
    *p = ptr1;
    return 0;
}

// Checking Stack is Empty or not
int isEmpty(stack s)
{
    if (s.top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// Displaying
void display(stack *s){
    struct node *ptr;
    if(!isEmpty(*s)){
        pop(s, &ptr);
        display(s);
        printf("%d ", ptr->data);
        push(s, ptr->data);
    }
}

int main(){
    int num, pushNum, popNum, v;
    stack s1;
    init(&s1);
    struct node *ptr;

    printf("How many element you want to push? ");
    scanf("%d", &pushNum);
    for(int i = 0; i < pushNum; i++){
        printf("Enter number: ");
        scanf("%d", &num);
        push(&s1, num);
    }

    display(&s1);

    printf("\nHow many element you want to pop? ");
    scanf("%d", &popNum);
    for(int i = 0; i < popNum; i++){
        pop(&s1, &ptr);
        printf("Poped element is %d\n", ptr->data);
    }

    display(&s1);

    if(isEmpty(s1)){
        printf("\nThe stack is Empty.");
    }else{
        printf("The stack is not Empty.");
    }

    return 0;
}