class Solution {
public:
    int solve(vector<vector<int>>& events, int n, int i, int k, vector<vector<int>> &dp, vector<int>& starts){
        if(i>=n || k==0){
            // base case
            return 0;
        }

        if(dp[i][k] !=-1){
            return dp[i][k];
        }

        int start=events[i][0];
        int end=events[i][1];
        int value=events[i][2];

        int skip= solve(events, n, i+1, k, dp, starts);

        // take
        // use stl of binary search use upper bound give greater than given one

        // give TLE since for seach vector of vector become messy
        // // events 3 value so 3 deni hogi baki two INT_MAX kr do
        // vector<int>temp={end, INT_MAX, INT_MAX};  

        int j=upper_bound(starts.begin(), starts.end(), events[i][1]) - starts.begin();
        // Algorithms like upper_bound return iterators.
        // You can get the index by subtracting begin() from the iterator and we want index j

        int take= value+ solve(events, n, j, k-1, dp, starts);

        return dp[i][k]=max(skip,take);
    }

    int maxValue(vector<vector<int>>& events, int k) {
        int n= events.size();
        sort(events.begin(), events.end());

         // Build starts vector for binary search
        vector<int> starts;
        for (auto& e : events) {
            starts.push_back(e[0]);
        }

        vector<vector<int>> dp(n, vector<int>(k+1,-1));
        return solve(events, n, 0, k, dp, starts);
    }
};
// recursive + memoization+ binary search
// tc: O(n*k*logn)
// space: O(n*k)

// recursive + memoization
// O(n) for linear search
// tc: O(n*k*n)
// space: O(n*k)
// class Solution {
// public:
//     int solve(vector<vector<int>>& events, int n, int i, int k, vector<vector<int>> &dp){
//         if(i>=n || k==0){
//             return 0;
//         }

//         if(dp[i][k] !=-1){
//             return dp[i][k];
//         }

//         int start=events[i][0];
//         int end=events[i][1];
//         int value=events[i][2];

//         int skip= solve(events, n, i+1, k, dp);

//         // take
//         int j=i+1;
//         // linear search
//         for(;j<n;j++){
//             if(events[j][0]>events[i][1]){
//                 break;
//             }
//         }

//         int take= value+ solve(events, n, j, k-1, dp);

//         return dp[i][k]=max(skip,take);
//     }

//     int maxValue(vector<vector<int>>& events, int k) {
//         int n= events.size();
//         sort(events.begin(), events.end());
//         vector<vector<int>> dp(n, vector<int>(k+1,-1));
//         return solve(events, n, 0, k, dp);
//     }
// };


// only recursion
// tc:O(2^n)
// space: O(n)
// class Solution {
// public:
//     int solve(vector<vector<int>>& events, int n, int i, int k){
//         if(i>=n || k==0){
//             return 0;
//         }

//         int start=events[i][0];
//         int end=events[i][1];
//         int value=events[i][2];

//         int skip= solve(events, n, i+1, k);

//         // take
//         int j=i+1;
//         for(;j<n;j++){
//             if(events[j][0]>events[i][1]){
//                 break;
//             }
//         }

//         int take= value+ solve(events, n, j, k-1);

//         return max(skip,take);
//     }

//     int maxValue(vector<vector<int>>& events, int k) {
//         int n= events.size();
//         sort(events.begin(), events.end());
//         return solve(events, n, 0, k);
//     }
// };