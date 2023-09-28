#include <stdio.h>
#define Max_size 8
int top = -1;
int stack[Max_size];

int isempty()
{
    if (top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull()
{
    if (top == Max_size)
    {
        return 1;
    }
    return 0;
}

int peek()
{
    return stack[top];
}
int pop()
{
    int data;
    if (!isempty())
    {
        data = stack[top];
        top = top - 1;
        return data;
    }
    printf("Could not retrieve data, Stack is empty.\n");
    return -1;
}

void push(int data)
{
    if (!isFull())
    {
        top++;
        stack[top] = data;
        printf("%d inserted successfully!\n", data);
        return;
    }
    printf("Could not insert data, Stack is full.\n");
}
int main()
{

    push(44);
    push(10);
    push(62);
    push(123);
    push(15);
    printf("Element at top of the stack: %d\n", peek());
    printf("Elements: \n");

    // print stack data
    while (!isempty())
    {
        int data = pop();
        printf("%d\n", data);
    }
    printf("Stack full: %s\n", isFull() ? "true" : "false");
    printf("Stack empty: %s\n", isempty() ? "true" : "false");

    return 0;
}