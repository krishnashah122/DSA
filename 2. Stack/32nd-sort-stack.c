// Sort Stack using Recursion

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

// Insert in Sorted way
void insort(stack *s, int v){
    if(isEmpty(*s)){
        push(s, v);
    }else{
        int d;
        pop(s, &d);
        if(d > v){
            insort(s, v);
            push(s, d);
        }else{
            push(s, d);
            push(s, v);
        }
    }
}

// Sorting
void sort(stack *s){
    if(!isEmpty(*s)){
        int d;
        pop(s, &d);
        sort(s);
        insort(s, d);
    }
}

// Displaying
void display(stack s){
    if(s.top == -1){
        return;
    }
    // printf("%d ", s.data[s.top--]);
    int x;
    pop(&s,&x);
    printf("%d ",x);
    display(s);
    push(&s,x);
 }

int main(){
    int num, pushNum, popNum, v;
    stack s1, s2;
    init(&s1);
    init(&s2);

    printf("How many element you want to push? ");
    scanf("%d", &pushNum);
    for(int i = 0; i < pushNum; i++){
        printf("Enter number: ");
        scanf("%d", &num);
        push(&s1, num);
    }

    display(s1);
    sort(&s1);
    printf("\nAfter Sorting: ");
    display(s1);

    return 0;
}