#include <stdio.h>
#define MAX_SIZE 100

int MIN(int a, int b) { return (a > b) ? b : a; }
void merge(int a[], int low, int mid, int high);
void mergeSort(int arr[], int n);

int count = 0;

int main()
{
    int testCase;
    scanf("%d", &testCase);
    for (int i=0; i<testCase; i++)
    {
        int n;
        scanf("%d", &n);
        int arr[MAX_SIZE];
        for (int j=0; j<n; j++)
        {
            scanf("%d", &arr[j]);
        }
        mergeSort(arr, n);
        printf("%d\n", count);
        count = 0;
    }
}

void mergeSort(int arr[], int n)
{
    int size = 1;

    while (size < n)
    {
        for (int i=0; i<n; i+=2*size)
        {
            int low = i;
            int mid = low + size - 1;
            int high = MIN(i+2*size-1, n-1);
            if (mid >= n-1)
                break;
            merge(arr, low, mid, high);
        }
        size *= 2;
    }
}

void merge(int a[], int low, int mid, int high)
{
    int i, j, k;
    int tmp[MAX_SIZE];

    for (i=low; i<=high; i++)
        tmp[i] = a[i];

    i = k = low;
    j = mid+1;

    while (i<=mid && j<=high)
    {
        count++;
        if (tmp[i] <= tmp[j])
        {
            a[k++] = tmp[i++];
        }
        else
            a[k++] = tmp[j++];
    }
    while (i<=mid)
        a[k++] = tmp[i++];
    while (j<=high)
        a[k++] = tmp[j++];
}
