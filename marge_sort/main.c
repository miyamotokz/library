#include<stdio.h>       /* printf等 */
#include<stdlib.h>      /* rand()関数 */
#define ARRAY_SIZE(a) (sizeof(a)/sizeof(a[0]))  /* 配列のサイズ用マクロ */

/* プロトタイプ宣言 */
void merge_sort(int[],int[],int,int);
void dump(int[],int);

int main()
{
    int a[20] = {0};
    int b[20] = {0};
    int size, i;
    for (i = 0; i < 100;i++){
        a[i] = rand()%100;
    }
    size = ARRAY_SIZE(a);
    dump(a, size);          /* ソート前 */
    merge_sort(a,b,0, size);   /* マージソート */
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

void merge_sort(int A[],int B[], int l,int r){
    int cnt = 0;
    int c = (l + r) / 2;
    int i = l, j = c, k = 0;    /* i,j,kはカウンタ */

    if (r - l == 1)
        return;
    /* 配列を二つに分割 */
    merge_sort(A, B, l, c);
    merge_sort(A, B, c, r);

    while(i < c && j < r){
        if(A[i] <= A[j]) B[k++] = A[i++];
            else B[k++] = A[j++];
    }
    if(i == c)while(j<r) B[k++] = A[j++];
    else if (j == r)while(i<c) B[k++] = A[i++];
    for (int m = 0; m < k; m++) {
        A[l + m] = B[m];
    }

}