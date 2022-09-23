#include <stdio.h>
void swap(char *a, char *b);
char* reverse(char *str, int left, int right);
int getLength(char *str);

int main()
{
    int numTestCases;
    scanf("%d", &numTestCases);
    for (int i = 0; i < numTestCases; ++i)
    {
        char str[100];
        scanf("%s", str);
        int right = getLength(str)-1;
        int left = 0;
        printf("%s", reverse(str, left, right));
        printf("\n");
    }
    return 0;
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

void swap(char *a, char *b)
{
    char tmp = *a;
    *a = *b;
    *b = tmp;
}

char* reverse(char *str, int left, int right)
{
    if (right <= left)
    {
        return str;
    }
    else
    {
        swap(&str[left], &str[right]);
        reverse(str, left + 1, right - 1);
    }
    return str;
}