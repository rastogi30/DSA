class Solution {
public:
    int MOD=1e9+7;
    vector<vector<int>>dp;

    int solve(int n, int num, int x){
        if(n==0){
            return 1;
        }

        if(n<0){
            return 0;
        }

        int currPower=pow(num,x);
        if(currPower>n){
            return 0;
        }

        if (dp[n][num] != -1) return dp[n][num]; // already computed

        int take=solve(n-currPower, num+1, x);
        int skip= solve(n, num+1, x);

        return dp[n][num]=(take+skip)%MOD;
    }
    int numberOfWays(int n, int x) {
        // The assign() function resizes the vector and fills it with the given value.
        // Here:
        // rows = n + 1 → We want n + 1 rows (indexing from 0 to n).
        // value = vector<int>(n + 1, -1) → Each row is itself a vector of size n + 1, filled with -1.
        // dp.assign(n + 1, vector<int>(n + 1, -1));

        dp=vector<vector<int>>(301, vector<int>(301,-1));
        int num=1;
        return solve(n, num,x);
    }
};

// Time: O(N²)
// Space: O(N²)

