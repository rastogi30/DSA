class Solution {
public:
    int solve(int i, int j,int n, int m, vector<vector<int>>& matrix, vector<vector<int>>&t){
        if(i>=n ||j>=m){
            return 0;
        }

        if(matrix[i][j]==0){
            return 0;
        }

        if(t[i][j] != -1){
            return t[i][j];
        }

        int right= solve(i, j+1,n,m, matrix,t);
        int dia=solve(i+1,j+1,n,m, matrix,t);
        int down=solve(i+1,j,n,m,matrix,t);

        return t[i][j]= 1+ min(right, min(dia,down));
    }
    int countSquares(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();

        int result=0;
        vector<vector<int>>t(n+1, vector<int>(m+1,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                result+= solve(i,j,n,m ,matrix,t);
            }
        }
        return result;
    }
};

//Approach - 1 (simple Recursion Memoization)
//T.C : O(m*n)
//S.C : O(m*n)

//Approach - 2 (simple Bottom Up)
//T.C : O(m*n)
//S.C : O(m*n)
// class Solution {
// public:
//     int countSquares(vector<vector<int>>& matrix) {
//         if(matrix.size() == 0)
//             return 0;
//         int m = matrix.size();
//         int n = matrix[0].size();
        
//         vector<vector<int>> t(m, vector<int>(n, 0));
//         int result = 0;

//         for(int i = 0; i < m; i++) {
//             for(int j = 0; j < n; j++) {
//                 if(i == 0 || j == 0) {
//                     t[i][j] = matrix[i][j];
//                 } else {
//                     if(matrix[i][j] == 1) {
//                         // Because, if you have any 0, then you cannot expand side of square
//                         t[i][j] = 1 + min({t[i-1][j], t[i][j-1], t[i-1][j-1]});
//                     }
//                 }
//                 result += t[i][j];
//             }
//         }
        
//         return result;
//     }
// };