class Solution {
public:
    bool isSafe(int row, int col, vector<vector<char>>& board, char ch){
        for(int i=0;i<9;i++){

            // row check
            if(board[row][i]==ch){
                return false;
            }
            // col check
            if(board[i][col]==ch){
                return false;
            }

            // 3*3 check
            if(board[3*(row/3)+i/3][3*(col/3)+i%3]==ch){
                return false;
            }
        }
        return true;
    }
    bool solve(vector<vector<char>>& board){
        int n=board.size();

        for(int row=0;row<n;row++){
            for(int col=0; col<n;col++){
                
                if(board[row][col]=='.'){
                    for(int val=1;val<=9;val++){
                        char ch=val+'0';
                        if(isSafe(row,col, board,ch)){
                            board[row][col]=ch;
                            bool next=solve(board);
                            if(next){
                                return true;
                            }
                            else{
                                // backtrach
                                board[row][col]='.';
                            }
                         }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};

// time:O(9^m)
// Worst-case time complexity: \U0001d442(9^81)