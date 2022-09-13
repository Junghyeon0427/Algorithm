#include <stdio.h>
#define MAX_SIZE 1000
void ShellSort(int a[], int n);
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
        ShellSort(a, num);
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

/* Shell Sort 함수 */
void ShellSort(int a[], int n)
{
    int countCmpOps = 0; // 비교 연산자 실행 횟수
    int countSwaps = 0; // swap 함수 실행 횟수

    int shrinkRatio = 2;
    int gap = n / shrinkRatio;

    while (gap > 0)
    {
        for (int i = gap; i < n; i++)
        {
            for (int j = i; j >= gap; j -= gap)
            {
                countCmpOps++;
                if (a[j-gap] > a[j])
                {
                    swap(&a[j-gap], &a[j]);
                    countSwaps++;
                }
                else
                    break;
            }
        }
        gap /= shrinkRatio;
    }

    printf("%d %d ", countCmpOps, countSwaps);
}