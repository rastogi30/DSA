class Solution {
public:
    int solve(vector<int>&vec){
        int cnt=0;
        int ans=0;

        for(auto x:vec){
            if(x==0){
                cnt=0;
            }
            else{
                cnt++;
            }

            ans+=cnt;
        }
        return ans;
    }

    int numSubmat(vector<vector<int>>& mat) {
        int n=mat.size();  //no of rows
        int m=mat[0].size(); //no of cols

        int result=0;

        for(int startRow=0; startRow<n; startRow++){
            
            // take a vector to convert in one-d.
            vector<int>vec(m,1);

            for(int endRow=startRow; endRow<n; endRow++){

                for(int col=0; col<m; col++){
                    vec[col]= vec[col] & mat[endRow][col];
                }
                result+= solve(vec);
            }
        }
        return result;
    }
};

// Time : O(n² * m) 
// Space : O(m)