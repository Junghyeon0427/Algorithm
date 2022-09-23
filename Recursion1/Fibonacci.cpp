#include <stdio.h>
int fibonacci(int n);
int main()
{
    int numTestCases;
    scanf("%d", &numTestCases);
    for (int i = 0; i < numTestCases; ++i)
    {
        int num;
        scanf("%d", &num);
        printf("%d", fibonacci(num));
        printf("\n");
    }
    return 0;
}

int fibonacci(int n)
{
    if (n == 1)
    {
        return 1;
    }

    if (n == 0)
    {
        return 0;
    }

    else
    {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}
