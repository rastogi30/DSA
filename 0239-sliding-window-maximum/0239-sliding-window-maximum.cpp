class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        vector<int>result;
        deque<int> deq;
        int i=0;
        int j=0;
        
        while(j<nums.size()){
            // small element remove kr rahe h
            while(!deq.empty() && nums[j]>=nums[deq.back()]){
                deq.pop_back();
            }

            // add the current index
            deq.push_back(j);
            
            if(j-i+1==k){
                // deq front has the max element so store that
                result.push_back(nums[deq.front()]);
                
                // before i increase remove the element present in deque
                if(!deq.empty() && deq.front()==i){
                    deq.pop_front();
                }
                i++;
            }
            j++;
        }
        return result;
    }
};

// TC: O(n)
// Space: O(k)

// /same GHG First negative in every window of size k
