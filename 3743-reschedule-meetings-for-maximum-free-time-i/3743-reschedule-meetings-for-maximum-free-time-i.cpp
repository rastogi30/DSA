class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        vector<int>freeTime; //store all free time 
        freeTime.push_back(startTime[0]);
        for(int i=1;i<startTime.size();i++){
            freeTime.push_back(startTime[i]-endTime[i-1]);
        }

        // last mei bhi to free time ho sakta h
        freeTime.push_back(eventTime-endTime[endTime.size()-1]);

        int n=freeTime.size();
        int i=0;
        int j=0;
        int maxSum=0;
        int currSum=0;

        while(j<n){
            currSum+=freeTime[j];

            if(i<n && j-i+1>k+1){
                currSum-=freeTime[i];
                i++;
            }

            maxSum=max(maxSum, currSum);
            j++;
        }
        return maxSum;
    }
};
// Time:O(n);
// space:O(1);

// You simple see on 1 shift 2 free time merge
// so k shift so k+1 ye max free time merge so we use sliding window on the free time and see which window 
// give max free time