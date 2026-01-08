class Solution {
public:
    bool issafe(int row, int col, vector<vector<char>> &board, char val)
{
    for (int i = 0; i < board.size(); i++)
    {
        // row check
        if (i != col && board[row][i] == val)
        {
            return false;
        }
        // col check
        if (i != row && board[i][col] == val)
        {
            return false;
        }
        // 3*3 matrix check
        int r = 3 * (row / 3) + i / 3;
        int c = 3 * (col / 3) + i % 3;

         if ((r != row || c != col) && board[r][c] == val)
         {
             return false;
         }

    }
            return true;

}
    bool isValidSudoku(vector<vector<char>>& board) {

        for(int row=0;row<9;row++)
        {
            for(int col=0;col<9;col++)
            {
                if (board[row][col] == '.') 
                {
                    continue;
                }
                if(!issafe(row,col,board,board[row][col]))
                {
                    return false;
                }
            }
        }
        return true;
    }
};
