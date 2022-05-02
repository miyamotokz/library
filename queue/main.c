#include<stdio.h>
#include<stdlib.h>
typedef int Type;
#define rep(i, n) for (int(i) = 0; (i) < (n); (i)++)
#define QUEUE_MAX_SIZE 1025
/* キュー */
typedef struct QUEUE {
    /* データの最後尾 */
    int tail;
    /* データの先頭 */
    int head;
    /* データの数 */
    int size;
    Type data[QUEUE_MAX_SIZE]; /* データ */
} Queue;

/* 初期化 */
void initQueue(Queue*);
int push(Queue *, Type);
int pop(Queue *);
Type front(Queue *);

int main(){
    Queue q;
    int val;
    initQueue(&q);
    rep(i, 10)
    {
        val = rand() % 100;
        push(&q, val);
        printf("push -> %d  size=%d\n", val,q.size);
    }
    rep(i,10){
        printf("front -> %d  size=%d\n", front(&q),q.size);
        pop(&q);
    }
}

void initQueue(Queue* q){
    q->head = 0;
    q->tail = -1;
    q->size = 0;
}

int push(Queue* q ,Type val){
    if(q->size >= QUEUE_MAX_SIZE){
        puts("Queueが満杯");
        return -1;
    }
    q->data[(q->tail + 1) % QUEUE_MAX_SIZE] = val;
    q->tail = (q->tail + 1) % QUEUE_MAX_SIZE;
    q->size++;
    return 0;
}
int pop(Queue* q ){
    if(q->size == 0){
        puts("データがありません");
        return -1;
    }
    q->head = (q->head + 1) % QUEUE_MAX_SIZE;
    q->size--;
    return 0;
}
Type front(Queue* q ){
    if(q->size == 0){
        puts("データがありません");
        return -1;
    }
    return q->data[q->head];
}