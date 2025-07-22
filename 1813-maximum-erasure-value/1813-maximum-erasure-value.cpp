class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int i=0;
        int j=0;
        unordered_set<int>st;
        int sum=0;
        int result=0;

        while(j<nums.size()){
            if(!st.count(nums[j])){
                sum+=nums[j];
                result=max(result,sum);
                st.insert(nums[j]);
                j++;
            }
            else{
                // means set mei vo value present h
                while(i<nums.size() && st.count(nums[j])){
                    sum-=nums[i];
                    st.erase(nums[i]);
                    i++;
                }
            }
        }
        return result;
    }
};

// time :O(N);
// space: O(N)