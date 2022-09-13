#include <stdio.h>
#define MAX_SIZE 1000

void combSort(int a[], int n);
int main()
{
    int numTestCases;
    scanf("%d", &numTestCases);
    for (int i = 0; i < numTestCases; ++i)
    {
        int num;
        int a[MAX_SIZE];
        scanf("%d", &num);
        for (int j = 0; j < num; j++)
            scanf("%d", &a[j]);
        combSort(a, num);
        printf("\n");
    }
    return 0;
}
void swap(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

/* comb sort 함수 */
void combSort(int a[], int n)
{
    int countCmpOps = 0; // 비교 연산자 실행 횟수
    int countSwaps = 0; // swap 함수 실행 횟수
    int gap = n;

    double shrink = 1.3;
    bool sorted = false;

    while (sorted == false)
    {
        int i = 0;
        gap = gap / shrink;

        /* while loop 탈출 조건*/
        if (gap <= 1)
        {
            gap = 1;
            sorted = true;
        }
        while (i+gap < n)
        {
            countCmpOps++;
            if (a[i] > a[i+gap])
            {
                swap(&a[i], &a[i+gap]);
                countSwaps++;
                sorted = false;
            }
            i++;
        }
    }

    printf("%d %d", countCmpOps, countSwaps);
}