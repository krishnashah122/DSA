// Copy Stack

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

// Checking whether Stack is Empty or not
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

// Copying Stack
void copyStack(stack *s1, stack *s2){
    int d;
    stack temp;
    temp.top = -1;

    while(!isEmpty(*s1)){
        pop(s1, &d);
        push(&temp, d);
    }

    while(!isEmpty(temp)){
        pop(&temp, &d);
        push(s2, d);
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
    stack s1, s2;
    inti(&s1);
    inti(&s2);

    printf("How many element you want to push? ");
    scanf("%d", &pushNum);
    for(int i = 0; i < pushNum; i++){
        printf("Enter number: ");
        scanf("%d", &num);
        push(&s1, num);
    }

    copyStack(&s1, &s2);
    display(s2);

    printf("\nHow many element you want to pop? ");
    scanf("%d", &popNum);
    for(int i = 0; i < popNum; i++){
        pop(&s2, &v);
        printf("Poped element is %d\n", v);
    }

    return 0;
}