#include<stdio.h>       /* printf等 */
#include<stdlib.h>      /* rand()関数 */
#define ARRAY_SIZE(a) (sizeof(a)/sizeof(a[0]))  /* 配列のサイズ用マクロ */

/* プロトタイプ宣言 */
int binary_serche(int[], int, int);
void sort(int[],int);

/* メイン関数 */
int main()
{
    int a[16] = {0, 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    int size, x,i;
    size = ARRAY_SIZE(a);
    sort(a, size);
    x = binary_serche(a, size, 15);
    printf("%d", x);
    return 0;
}

/* バブルソート */
void sort(int array[],int len){
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
/* 二分探索 */
int binary_serche(int array[], int len, int key)
{
    int l = 0;
    int r = len;
    while(l!=r){
        int c = l + (( r -l) / 2);
        if(array[c] == key){
            return c;
        }
        if(array[c] > key){
            r = c;
        }else{
            l = c;
        }
    }
    return -1;
}
