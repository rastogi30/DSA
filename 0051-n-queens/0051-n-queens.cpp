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

    void solve(int col,  vector<vector<char>>&board, vector<vector<string>>&ans, int n, unordered_map<int, bool>& left,
               unordered_map<int, bool>& lowerDiag,
               unordered_map<int, bool>& upperDiag){
        // base case
        if(col==n){
            addSolution(board, ans, n);
            return;
        }

        for(int row=0; row<n;row++){
            if (!left[row] && !lowerDiag[row+col] && !upperDiag[n-1 + col-row]) {
                board[row][col]= 'Q';
                left[row] = true;
                lowerDiag[row+col] = true;
                upperDiag[n-1 + col-row] = true;
                solve(col+1, board, ans,n, left, lowerDiag, upperDiag);

                // backtrack
                board[row][col]='.';
                left[row] = false;
                lowerDiag[row+col] = false;
                upperDiag[n-1 + col-row] = false;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<char>>board(n, vector<char>(n, '.'));
        vector<vector<string>>ans;

        unordered_map<int,bool> left,lowerDiag, upperDiag;

        solve(0, board, ans, n, left, lowerDiag, upperDiag);
        return ans;
    }
};
// more fast..use map instead of isSafe....in map search time taken to search is O(1)
// lowerdiagonal:row+col  make grid then see this pattern
// upper: n-1+col-row

// time: O(n*)
// space:O(n*2);