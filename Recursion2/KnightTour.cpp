#include <stdio.h>

#define MARK 1
#define UNMARK 0

typedef struct Point {int x, y;} point;
point direction[8] = {{1, -2}, {2, -1}, {2, 1}, {1, 2}, {-1, 2},
                      {-2, 1}, {-2, -1}, {-1, -2}};

int path[9][9] = {0, };
int board[9][9] = {0, };

int knightTour (int m, int n, point pos, int counter);

int main()
{
    int numTestCase;
    scanf("%d", &numTestCase);
    for (int i = 0; i < numTestCase; i++)
    {
        // m : 행의 개수
        // n : 열의 개수
        // s : 시작 행
        // t : 시작 열
        int m, n, s, t;
        point start;
        scanf("%d %d %d %d", &m, &n, &s, &t);
        start.y = s;
        start.x = t;

        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
            {
                board[i][j] = UNMARK;
                path[i][j] = 0;
            }

        board[start.y][start.x] = MARK;
        path[start.y][start.x] = 1;

        if (knightTour(m, n, start, 1))
        {
            printf("1\n");
            for (int i = 1; i <= m; i++)
            {
                for (int j = 1; j <= n; j++)
                {
                    printf("%d ", path[i][j]);
                }
                printf("\n");
            }
        }
        else
        {
            printf("0\n");
        }
    }
}

int knightTour (int m, int n, point pos, int counter)
{
    point next;

    if (counter == m * n)
        return 1;

    for (int i = 0; i < 8; i++)
    {
        next.x = pos.x + direction[i].x;
        next.y = pos.y + direction[i].y;

        if (next.x > 0 and next.x <= n and next.y > 0 and next.y <= m and board[next.y][next.x] != MARK)
        {
            board[next.y][next.x] = MARK;
            path[next.y][next.x] = counter + 1;

            if (knightTour(m, n, next, counter+1))
                return 1;

            board[next.y][next.x] = UNMARK;
        }
    }
    return 0;
