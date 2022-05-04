#include<stdio.h>
#include<stdlib.h>
typedef int Type;
#define rep(i, n) for (int(i) = 0; (i) < (n); (i)++)
#define STACK_MAX_SIZE 1024

typedef struct stack
{
    int size;
    Type data[STACK_MAX_SIZE];
} Stack;

int pop(Stack *);
int push(Stack *, Type);
void initStack(Stack *);
Type front(Stack *);


void initStack(Stack *s){
    s->size = 0;
}
Type front(Stack *s){
    return s->data[s->size];
}

int pop(Stack *s){
    if(s->size == 0){
        printf("スタックがありません\n");
        return -1;
    }
    s->size--;
    return 0;
}
int push(Stack *s,Type val){
    if(s->size == STACK_MAX_SIZE - 1 ){
        printf("スタックがいっぱいです\n");
        return -1;
    }
    s->size++;
    s->data[s->size] = val;
    return 0;
}
int main(){
    int val;
    Stack stack;
    initStack(&stack);
    rep(i, 100)
    {
        val = rand() % 100;
        push(&stack, val);
        printf("stack= %d\n", front(&stack));
    }
    puts("取り出し");
    rep(i, 100)
    {
        printf("front= %d\n", front(&stack));
        pop(&stack);
    }
}