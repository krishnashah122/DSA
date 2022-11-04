//Stack Implementation using Array

#include <stdio.h>
#define MAX 10

typedef struct{
    int data[MAX];
    int top;
}stack;

void init(stack *s){
    s->top = -1;
}

int push(stack *s, int val){
    if(s->top == MAX-1){
        printf("Overflow");
        return 1;
    }
    s->top++;
    s->data[s->top] = val;
    return 0;
}

int pop(stack *s, int *val){
    if(s->top == -1){
        printf("Underflow");
        return 1;
    }
    *val = s->data[s->top];
    s->top--;
    return 0;
}

// Checking Stack is Empty or not
int isEmpty(stack s)
{
    if (s.top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// Displaying
void display(stack s){
    if(s.top == -1){
        return;
    }
    printf("%d ", s.data[s.top--]);
    display(s);
}

int main(){
    int num, pushNum, popNum, v;
    stack s1;
    inti(&s1);

    printf("How many element you want to push? ");
    scanf("%d", &pushNum);
    for(int i = 0; i < pushNum; i++){
        printf("Enter number: ");
        scanf("%d", &num);
        push(&s1, num);
    }

    display(s1);

    printf("\nHow many element you want to pop? ");
    scanf("%d", &popNum);
    for(int i = 0; i < popNum; i++){
        pop(&s1, &v);
        printf("Poped element is %d\n", v);
    }

    display(s1);

    if(isEmpty(s1)){
        printf("\nThe stack is Empty.");
    }else{
        printf("The stack is not Empty.");
    }

    return 0;
}