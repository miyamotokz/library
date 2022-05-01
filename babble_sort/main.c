#include<stdio.h>       /* printf等 */
#include<stdlib.h>      /* rand()関数 */
#define ARRAY_SIZE(a) (sizeof(a)/sizeof(a[0]))  /* 配列のサイズ用マクロ */

/* プロトタイプ宣言 */
void babble_sort(int[],int);
void dump(int[],int);

int main()
{
    int a[100] = {0};
    int size, i;
    for (i = 0; i < 100;i++){
        a[i] = rand()%100;
    }
    size = ARRAY_SIZE(a);
    dump(a, size);          /* ソート前 */
    babble_sort(a, size);   /* バブルソート */
    dump(a, size);          /* ソート後 */
    return 0;
}

/* 表示用 */
void dump(int array[],int size){
    int i = 0;
    printf("dump - ");
    for (i = 0; i < size; i++)
    {
        printf("%d,", array[i]);
    }
    printf("\n");
}
/* バブルソート */
void babble_sort(int array[],int len){
    int t;
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = i + 1; j < len;j++){
            if(array[i] > array[j]){
                t = array[i];
                array[i] = array[j];
                array[j] = t;
            }
        }
    }
}