#include "./head/seqStack.h"

int main(void)
{
    Stack s;
    Stack* ps = &s;
    int e = 0;
    Init(ps);
    if(isEmpty(ps))
        printf("stack is Empty!\n");

    push(ps, 1);
    GetTop(ps, &e);
    printf("Top: %d\n", e);
    push(ps, 2);
    push(ps, 3);
    push(ps, 4);
    push(ps, 5);
    push(ps, 6);
    push(ps, 7);
    push(ps, 8);
    push(ps, 9);
    push(ps, 10);
    push(ps, 11);
    GetTop(ps, &e);
    printf("Top: %d\n", e);
    pop(ps, &e);
    printf("Top: %d\n", e);
    GetTop(ps, &e);
    printf("Top: %d\n", e);

    if(isEmpty(ps))
        printf("stack is Empty!\n");
    else
        printf("stack is NOt Empty!\n");

    return EXIT_SUCCESS;
}