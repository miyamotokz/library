#include<stdio.h>
#include<stdlib.h>
#define ARRAY_SIZE(a) (sizeof(a)/sizeof(a[0]))  /* 配列のサイズ用マクロ */
int center(int, int, int);
void quick_sort(int[],int,int);
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
    quick_sort(a, 0, size);   /* クイックソート */
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

int center(int a,int b,int c){
    int max = a;
    int min = a;
    if(max < b)max = b;
    if(max < c)max = c;
    if(min > b)min = b;
    if(min > c)min = c;
    return a+b+c-min-max;
}
void quick_sort(int a[], int l, int r)
{
    if (l < r) {
        int i = l, j = r;
        int tmp, pivot, c;
        c = l + ((r - l) / 2);
        pivot = center(a[l], a[r], a[c]);
        while (1)
        {
            while (a[i] < pivot) i++; 
            while (pivot < a[j]) j--; 
            if (i >= j) break;
            tmp = a[i];
            a[i] = a[j];
            a[j] = tmp; 
            i++;
            j--;
        }
        quick_sort(a, l, i - 1); 
        quick_sort(a, j + 1, r); 
    }
}