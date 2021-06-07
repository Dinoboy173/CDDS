#include <iostream>
// TODO: Write your function here
bool isMiniSudoku(int board[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] < 1 || board[i][j] > 9)
            {
                return false;
            }
        }
    }

    int col1 = 0;
    int row1 = 0;

    int col2 = 0;
    int row2 = 0;

    while (col1 < 2)
    {
        if (row2 == 3)
        {
            if (col2 == 2)
            {
                if (row1 == 2)
                {
                    row1 = -1;
                    col1++;
                }

                col2 = -1;
                row1++;
            }

            row2 = 0;
            col2++;
        }

        if (col1 == col2 && row1 == row2)
        {

        }
        else
        {
            if (board[col1][row1] == board[col2][row2])
            {
                return false;
            }
        }

        row2++;
    }
    return true;
}

int Client()
{
    int board1[3][3] = { {1, 3, 2}, {9, 7, 8}, {4, 5, 6} };
    int board2[3][3] = { {8, 9, 2}, {5, 6, 1}, {3, 7, 4} };
    int board3[3][3] = { {1, 1, 3}, {6, 5, 4}, {8, 7, 9} };
    int board4[3][3] = { {0, 1, 2}, {6, 4, 5}, {9, 8, 7} };

    std::cout << std::boolalpha;
    std::cout << isMiniSudoku(board1) << " Expected true" << std::endl;
    std::cout << isMiniSudoku(board2) << " Expected true" << std::endl;
    std::cout << isMiniSudoku(board3) << " Expected false" << std::endl; // The 1 is repeated twice 
    std::cout << isMiniSudoku(board4) << " Expected false" << std::endl; // The 0 is included (outside range)
    return 0;
}
