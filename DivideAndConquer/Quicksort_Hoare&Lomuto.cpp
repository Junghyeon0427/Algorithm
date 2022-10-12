#include <stdio.h>
#define MAX_SIZE 1000

int countCmpOps = 0; // 비교 연산자 실행 횟수
int countSwaps = 0; // swap 함수 실행 횟수
int countCmpOps2 = 0; // 비교 연산자 실행 횟수
int countSwaps2 = 0; // swap 함수 실행 횟수

// l은 pivot보다 큰 경우, h는 pivot보다 작은 경우 stop
void Hoare(int arr[], int l, int h);
int partitionHoare(int arr[], int l, int h);

void Lomuto(int arr[], int l, int h);
int partitionLomuto(int arr[], int l, int h);

void swap(int* a, int* b);
void copyArray(int a[], int b[], int n);

int main()
{
    int testCase;
    scanf("%d", &testCase);
    for (int i=0; i<testCase; i++)
    {
        int n;
        int arr[MAX_SIZE];
        int arr2[MAX_SIZE];
        scanf("%d", &n);
        for (int j=0; j<n; j++)
        {
            //9 4 7 3 9 2 5 8 1 6
            scanf("%d", &arr2[j]);
        }

        copyArray(arr, arr2, n);
        Hoare(arr, 0, n-1);

        copyArray(arr, arr2, n);
        Lomuto(arr, 0, n-1);

        printf("%d %d %d %d\n", countSwaps, countSwaps2, countCmpOps, countCmpOps2);
        countSwaps = 0;
        countCmpOps = 0;
        countSwaps2 = 0;
        countCmpOps2 = 0;
    }
    return 0;
}

void Hoare(int arr[], int l, int h)
{
    if (l >= h)
        return;

    int p = partitionHoare(arr, l, h);
    Hoare(arr, l, p);
    Hoare(arr, p+1, h);
}

int partitionHoare(int arr[], int l, int h)
{
    int pivot, i, j;

    pivot = arr[l];
    i = l-1;
    j = h+1;
    // i은 pivot보다 크거나 같을 경우, j는 pivot보다 작거나 같을 경우 stop
    while (1)
    {
        do
        {
            i += 1;
            countCmpOps++;
        } while (arr[i] < pivot);
        do
        {
            j -= 1;
            countCmpOps++;
        } while (arr[j] > pivot);

        if (i < j)
        {
            countSwaps++;
            swap(&arr[i], &arr[j]);
        }
        else
        {
            return j;
        }
    }
}

void Lomuto(int arr[], int l, int h)
{
    if (l >= h)
        return;

    int p = partitionLomuto(arr, l, h);
    Lomuto(arr, l, p-1);
    Lomuto(arr, p+1, h);
}

int partitionLomuto(int arr[], int l, int h)
{
    int i, j;
    int pivot, pivotPos;

    pivot = arr[l];
    j = l;

    for (i=l+1; i<=h; i++)
    {
        countCmpOps2++;
        if(arr[i] < pivot)
        {
            j++;
            countSwaps2++;
            swap(&arr[i], &arr[j]);
        }
    }
    pivotPos = j;
    swap(&arr[pivotPos], &arr[l]);
    countSwaps2++;

    return pivotPos;
}

void swap(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void copyArray(int a[], int b[], int n)
{
    for (int i=0; i<n; i++)
        a[i] = b[i];
}
