#include<stdio.h>
int pop(Stack);
int push(Stack);


typedef struct node
{
    node *next;    /* スタックポインタ */
    int val;
} Node;

typedef struct stack
{
    int *sp;    /* スタックポインタ */
    node node;
} Stack;