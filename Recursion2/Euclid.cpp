#include <stdio.h>
int gcd(int a, int b);

int main()
{
    int numTestCases;
    scanf("%d", &numTestCases);
    for (int i = 0; i < numTestCases; ++i)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        printf("%d", gcd(a, b));
        printf("\n");
    }
    return 0;
}

int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    else
    {
        return gcd(b, a % b);
    }
}
