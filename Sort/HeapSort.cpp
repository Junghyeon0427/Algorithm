#include <iostream>

using namespace std;

void swap(int* a, int* b);
void heapify(int arr[], int n, int i);
void heapSort(int arr[], int n);

int cnt = 0;

int main()
{
    int t;
    cin >> t;
    for (int x=0; x<t; x++)
    {
        int num;
        cin >> num;
        int* arr = new int[num];
        for (int i=0; i<num; i++)
        {
            int tmp;
            cin >> tmp;
            arr[i] = tmp;
        }
        heapSort(arr, num);
        cout << cnt << endl;
        cnt = 0;
    }
}

void heapify(int* arr, int n, int i)
{
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    
    // left child
    if (l < n)
    {
        cnt++;
        if (arr[l] > arr[largest])
            largest = l;
    }
    // right child
    if (r < n)
    {
        cnt++;
        if (arr[r] > arr[largest])
            largest = r;
    }
    if (largest != i)
    {
        // cnt++;
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int* arr, int n)
{
    for (int i=n/2-1; i>=0; i--)
        heapify(arr, n, i);

    for (int i=n-1; i>=0; i--)
    {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

void swap(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
