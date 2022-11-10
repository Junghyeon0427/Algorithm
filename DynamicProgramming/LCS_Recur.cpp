#include<stdio.h>
#define MAX(a, b) ((a) > (b) ? (a):(b))

int getLength(char *str);
int LCS(char s[], char t[], int m, int n);

int main()
{
    int t;
    scanf("%d", &t);
    for (int i=0; i<t; i++)
    {
        char s[11];
        char t[11];
        scanf("%s %s", s, t);
        int m = getLength(s);
        int n = getLength(t);
        printf("%d ", LCS(s, t, m, n));
        printf("\n");
    }
}

int getLength(char *str)
{
    int length = 0;
    while (*(str+length) != '\0')
    {
        length++;
    }
    return length;
}

int LCS(char s[], char t[], int m, int n)
{
    if (m == 0 or n == 0)
        return 0;
    else if (s[m-1] == t[n-1])
        return 1 + LCS(s, t, m - 1, n - 1);
    else
    {
        int a = LCS(s, t, m-1, n);
        int b = LCS(s, t, m, n-1);
        return MAX(a, b);
    }
}
