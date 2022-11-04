// Infix to Postfix using Stack

#include <stdio.h>
#define MAX 5

typedef struct
{
    char data[MAX];
    int top;
} stack;

void init(stack *s){
    s->top = -1;
}

// Push function
int push(stack *s, char val)
{
    if (s->top >= MAX - 1)
    {
        printf("Overflow\n");
        return 1;
    }
    else
    {
        s->top++;
        s->data[s->top] = val;
        return 0;
    }
}

// Pop function
int pop(stack *s, char *val)
{
    if (s->top == -1)
    {
        printf("Underflow\n");
        return 1;
    }
    else
    {
        *val = s->data[s->top];
        s->top--;
        return 0;
    }
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

// Checking is Operand or not
int isOperand(char a)
{
    if ((a >= 'A' && a <= 'Z') || (a >= 'a' && a <= 'z'))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// Checking Precedence of Operator
int precedence(char ch)
{
    int k = 0;
    switch (ch)
    {
    case '+':
    case '-':
        k = 1;
        break;
    case '*':
    case '/':
        k = 2;
        break;
    }
    return k;
}

// Checking is LH case or not
int isLH(char a, char b)
{
    if (precedence(a) < precedence(b))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// Infix to Postfix
void infixToPostfix(stack *s, char *inf, char *out)
{
    int i = 0, j = 0;
    char t;
    while (inf[i] != '\0')
    {
        if (isOperand(inf[i]))
        {
            out[j++] = inf[i];
        }
        else if (inf[i] == '(')
        {
            push(s, inf[i]);
        }
        else if (inf[i] == ')')
        {
            while (1)
            {
                pop(s, &t);
                if (t == '(')
                    break;
                out[j++] = t;
            }
        }
        else // Operator
        {
            if (isEmpty(*s))
            {
                push(s, inf[i]);
            }
            else
            {
                pop(s, &t);
                if (t == '(')
                {
                    push(s, t);
                    push(s, inf[i]);
                }
                else
                {
                    if (isLH(t, inf[i]))
                    {
                        push(s, t);
                        push(s, inf[i]);
                    }
                    else
                    {
                        out[j++] = t;
                        i--;
                    }
                }
            }
        }
        i++;
    }
    while (!isEmpty(*s))
    {
        pop(s, &t);
        out[j++] = t;
    }
    out[j] = '\0';
}

// Displaying
void display(char a[])
{
    for (int i = 0; a[i] != '\0'; i++)
    {
        printf("%c", a[i]);
    }
}

int main()
{
    stack s1;
    init(&s1);
    char infix[100];
    char output[100];

    printf("Enter the infix expression: ");
    scanf("%s", infix);

    infixToPostfix(&s1, infix, output);

    printf("The Postfix expression is ");
    display(output);

    return 0;
}