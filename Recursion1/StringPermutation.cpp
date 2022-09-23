#include <stdio.h>
void swap(char *a, char *b);
int getLength(char *str);
void permuteString(char *str, int begin, int end);
void permute(char* str, int len);

int cnt;

int main()
{
    int numTestCases;
    scanf("%d", &numTestCases);
    for (int i = 0; i < numTestCases; ++i)
    {
        char str[10];
        scanf("%s", str);
        int length = getLength(str);
        permute(str, length);
        printf("%d", cnt);
        cnt = 0;
        printf("\n");
    }
    return 0;
}

void swap(char *a, char *b)
{
    char tmp = *a;
    *a = *b;
    *b = tmp;
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

void permuteString(char *str, int begin, int end)
{
    int i;
    int range = end - begin;
    int length = end;
    int sum = 0;

    if (range == 1)
    {
        for (int i = 0; i < length; i++)
        {
            if (i % 2 ==0)
            {
                sum = sum + (int(str[i]) - int('a'));
            }
            else
            {
                sum = sum - (int(str[i]) - int('a'));
            }
        }
        if (sum > 0)
        {
            cnt++;
        }
    }
    else
    {
        for (int i = 0; i < range; i++)
        {
            swap(&str[begin], &str[begin+i]);
            permuteString(str, begin+1, end);
            swap(&str[begin], &str[begin+i]);
        }
    }
}

void permute(char* str, int len)
{
    permuteString(str, 0, len);
}
