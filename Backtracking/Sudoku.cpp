/// 4x4 Sudoku
#include <iostream>
#define N 4

using namespace std;

bool Search(int **matrix, int row, int col);
bool Check(int **matrix, int row, int col, int num);

int main()
{
    int t;
    cin >> t;
    for (int x=0; x<t; x++)
    {

        int **matrix = new int*[4];
        for(int i=0; i<4; i++)
        {
            matrix[i] = new int[4];
            for(int j=0; j<4; j++)
            {
                int num;
                cin >> num;
                matrix[i][j] = num;
            }
        }

        Search(matrix, 0, 0);

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
                cout << matrix[i][j] << " ";
            cout << endl;
        }
    }

    return 0;
}

bool Search(int  **matrix, int row, int col)
{

    if (row == N - 1 && col == N)
        return true;

    if (col == N)
    {
        row++;
        col = 0;
    }

    if (matrix[row][col] > 0)
        return Search(matrix, row, col + 1);

    for (int num=1; num<=N; num++)
    {
        if (Check(matrix, row, col, num))
        {
            matrix[row][col] = num;
            if (Search(matrix, row, col + 1))
                return true;
        }
        matrix[row][col] = 0;
    }
    return false;
}

bool Check(int **matrix, int row, int col, int num)
{

    for (int x = 0; x<=3; x++)
        if (matrix[row][x] == num)
            return false;

    for (int x = 0; x<=3; x++)
        if (matrix[x][col] == num)
            return false;

    int row2 = row - row%2;
    int col2 = col - col%2;

    for (int i = row2; i<row2+2; i++)
        for (int j = col2; j<col2+2; j++)
            if (matrix[i][j] == num)
                return false;

    return true;
}
