class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int,int>>vec;
        for(int i=0;i<nums.size();i++){
            vec.push_back({i,nums[i]});
        }

        auto lambda = [](auto &p1, auto &p2){
            return p1.second > p2.second; // sort in descending order
        };
        sort(vec.begin(), vec.end(), lambda);

        // sort first k element according to the index
        sort(vec.begin(), vec.begin()+k);

        vector<int>result;
        // store top k elemnts onlt
        for(int i=0; i<k;i++){
            result.push_back(vec[i].second);
        }
        return result;
    }
};

// tc O(nlogn);