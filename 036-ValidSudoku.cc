/*


Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

The Sudoku board could be partially filled, where empty cells are filled.
*/
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<int> col_num(9);
        vector<int> grid(9);
        for(int row=0;row<9;row++) {
            int row_num=0;
            for(int col=0;col<9;col++) {
                if(board[row][col]!='.') {
                    int num=1<<(board[row][col]-'1');
                    if(row_num&num || col_num[col]&num || grid[col/3+3*(row/3)]&num)
                        return false;
                    row_num|=num;
                    col_num[col]|=num;
                    grid[col/3+3*(row/3)]|=num;
                }
            }   
        }
        return true;
    }
};
