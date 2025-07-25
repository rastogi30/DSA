class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_set<int> st;
        int ans = INT_MIN;

        for (int num : nums) {
            ans = max(ans, num);
            if (num > 0) {
                // in set store the positive answer only
                st.insert(num);
            }
        }

        // gar positive element h to un ka sum kr lo
        if (!st.empty()) {
            int sum = 0;
            for (int num : st) {
                sum += num;
            }
            return sum;
        }

        // in nums all negative so return max of the nums
        return ans; // all non-positive elements
    }
};

// time: O(n)
// space O(n)