class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int N=nums.size();
        int n=N/3;

        long long result=LLONG_MAX;
        vector<long long>leftMin(N,0);
        vector<long long>rightMax(N,0);

        priority_queue<int>maxHeap;
        long long leftSum=0;
        for(int i=0;i<2*n;i++){
            maxHeap.push(nums[i]);
            leftSum+=nums[i];
            if(maxHeap.size()>n){
                leftSum-=maxHeap.top();
                maxHeap.pop();
            }

            leftMin[i]= leftSum;
        }

        priority_queue<int,vector<int>, greater<int>>minHeap;
        long long rightSum=0;
        for(int i=N-1;i>n-1;i--){
            minHeap.push(nums[i]);
            rightSum+=nums[i];
            if(minHeap.size()>n){
                rightSum-=minHeap.top();
                minHeap.pop();
            }
            rightMax[i]= rightSum;
        }

        for(int j=n-1;j<=2*n-1;j++){
            result=min(result, leftMin[j]-rightMax[j+1]);
        }
        return result;
    }
};

// TC: \U0001d442(\U0001d45blog\U0001d45b)  push and pop in heap takes O(log n)
// Space: O(N) where N=3n