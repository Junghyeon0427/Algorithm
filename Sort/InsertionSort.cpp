#include <stdio.h>
#define MAX_SIZE 1000
void insertionSort(int a[], int n);
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
        insertionSort(a, num);
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

/* Insertion Sort 함수 */
void insertionSort(int a[], int n)
{
    int countCmpOps = 0; // 비교 연산자 실행 횟수
    int countSwaps = 0; // swap 함수 실행 횟수

    for (int i = 1; i < n; i++)
    {
        for (int j = i; j > 0; j--)
        {
            countCmpOps++;
            if (a[j-1] > a[j])
            {
                swap(&a[j], &a[j-1]);
                countSwaps++;
            }
            else
                break;
        }
    }

    printf("%d %d ", countCmpOps, countSwaps);
}

