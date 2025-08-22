class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        int minRow=n;
        int maxRow=-1;
        int minCol=m;
        int maxCol=-1;

        for(int row=0;row<n;row++){
            for(int col=0; col<m;col++){
                if(grid[row][col]==1){
                    minCol=min(minCol, col);
                    maxCol=max(maxCol, col);
                }
                if(grid[row][col]==1){
                    minRow=min(minRow, row);
                    maxRow=max(maxRow, row);
                }
            }
        }
        int a= (maxRow-minRow)+1;
        int b= (maxCol-minCol)+1;
        return a*b;
    }
};