// Queue using Stack

#include <stdio.h>
#define MAX 5

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

//Inserting
int insert(stack *s1, stack *s2, int val){
    if(s1->top == MAX-1){
        if(isEmpty(*s2)){
            int d;
            while(!isEmpty(*s1)){
                pop(s1, &d);
                push(s2, d);
            }
            push(s1, val);
            return 0;
        }
        printf("Overflow");
        return 1;
    }else{
        push(s1, val);
        return 0;
    }
}

//Deleting
int delete(stack *s1, stack *s2, int *val){
    if(isEmpty(*s1) && isEmpty(*s2)){
        printf("Empty");
        return 1;
    }else{
        if(!isEmpty(*s2)){
            pop(s2, val);
        }else{
            while(!isEmpty(*s1)){
                int d;
                pop(s1, &d);
                push(s2, d);
            }
            pop(s2, val);
        }
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
    int v;
    stack s1, s2;
    init(&s1);
    init(&s2);

    insert(&s1, &s2, 10);
    insert(&s1, &s2, 20);
    insert(&s1, &s2, 30);
    insert(&s1, &s2, 40);
    insert(&s1, &s2, 50);
    insert(&s1, &s2, 60);

    display(s2);
    display(s1);

    delete(&s1, &s2, &v);
    printf("\nThe deleted element is %d.\n", v);

    display(s2);
    display(s1);

    return 0;
}
