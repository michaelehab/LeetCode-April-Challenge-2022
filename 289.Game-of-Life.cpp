class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int rows = board.size(), cols = board[0].size();
        vector<vector<int>> prevState = board;        
        for(int r = 0; r < rows; r++) {
            for(int c = 0; c < cols; c++) {
                int alive = 0;
                if(r - 1 >= 0 && prevState[r - 1][c]) ++alive;
                if(r + 1 < rows && prevState[r + 1][c]) ++alive;
                if(c - 1 >= 0 && prevState[r][c - 1]) ++alive;
                if(c + 1 < cols && prevState[r][c + 1]) ++alive;
                if(r - 1 >= 0 && c - 1 >= 0 && prevState[r - 1][c - 1]) ++alive;
                if(r - 1 >= 0 && c + 1 < cols && prevState[r - 1][c + 1]) ++alive;
                if(r + 1 < rows && c - 1 >= 0 && prevState[r + 1][c - 1]) ++alive;
                if(r + 1 < rows && c + 1 < cols && prevState[r + 1][c + 1]) ++alive;
                
                if(board[r][c]) {
                    if(alive < 2 || alive > 3) board[r][c] = 0;
                } 
                else board[r][c] = (alive == 3);
            }
        }
    }
};