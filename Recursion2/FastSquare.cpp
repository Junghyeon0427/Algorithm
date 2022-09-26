#include <stdio.h>
#include <cmath>
int computePowers(int a, int n);

int main()
{
    int numTestCases;
    scanf("%d", &numTestCases);
    for (int i = 0; i < numTestCases; ++i)
    {
        int a, n;
        scanf("%d %d", &a, &n);
        printf("%d" ,computePowers(a, n));
        printf("\n");
    }
    return 0;
}

int computePowers(int a, int n)
{
    if (n == 0)
    {
        return 1;
    }

    // odd case
    if (n % 2 == 1)
    {
        int tmp = a * pow(computePowers(a, (n-1) / 2), 2);
        return tmp % 1000;
    }

    // even case
    else
    {
        int tmp2 = pow(computePowers(a, n / 2), 2);
        return tmp2 % 1000;
    }
}
