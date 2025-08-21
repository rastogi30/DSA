class Solution {
public:
    void addSolution(vector<vector<char>>&board, vector<vector<string>>&ans, int n){
        vector<string> temp;
        for (int i=0; i<n; i++) {
            string row = "";
            for (int j=0; j<n; j++) {
                row += board[i][j];
            }
            temp.push_back(row);
        }
        ans.push_back(temp);
    }

    bool isSafe(int row, int col, vector<vector<char>>&board, int n){

        int x=row;
        int y=col;

        // check row
        while(y>=0){
            if(board[x][y]=='Q'){
                return false;
            }
            y--;
        }

        x=row;
        y=col;
        // check diagonal
        while(x>=0 && y>=0){
            if(board[x][y]=='Q'){
                return false;
            }
            x--;
            y--;
        }

        x=row;
        y=col;
        // check diagonal
        while(x<n && y>=0){
            if(board[x][y]=='Q'){
                return false;
            }
            x++;
            y--;
        }

        return true;
    }
    
    void solve(int col,  vector<vector<char>>&board, vector<vector<string>>&ans, int n){
        // base case
        if(col==n){
            addSolution(board, ans, n);
            return;
        }

        for(int row=0; row<n;row++){
            if(isSafe(row, col, board, n)){
                board[row][col]= 'Q';
                solve(col+1, board, ans,n);

                // backtrack
                board[row][col]='.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<char>>board(n, vector<char>(n, '.'));
        vector<vector<string>>ans;

        solve(0, board, ans, n);
        return ans;
    }
};

// time: O(n*n!)
// space:O(n*2);