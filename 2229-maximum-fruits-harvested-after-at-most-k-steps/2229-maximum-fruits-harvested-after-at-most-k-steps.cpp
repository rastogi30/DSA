class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n=fruits.size();

        vector<int>prefixSum(n);
        vector<int>position(n); //already sorted hoga ye

        for(int i=0;i<n;i++){
            position[i]=fruits[i][0];

            prefixSum[i] = fruits[i][1] + (i>0 ? prefixSum[i-1]: 0);
        }

        int maxSum=0;
        // d left mei move first ya right and upto k/2 beacuse remain k-2d and this is not negative
        for(int d=0; d<=(k/2); d++){
            // move d step in left
            int remain= k-2*d; //(d left jane ka d aane ka)
            int i= startPos-d;
            int j=startPos+ remain;

            int left= lower_bound(position.begin(), position.end(), i)- position.begin(); // sub so that return index
            int right= upper_bound(position.begin(), position.end(), j)- position.begin()-1;

            if(left<=right){
                int total= prefixSum[right]- (left>0 ? prefixSum[left-1] : 0);
                maxSum=max(maxSum, total);
            }

            // case 2 first move d steps in right
            // int remain= k-2*d reamin to same hi rahega
             i= startPos-remain;
             j=startPos+ d;

             left= lower_bound(position.begin(), position.end(), i)- position.begin(); // sub so that return index
             right= upper_bound(position.begin(), position.end(), j)- position.begin()-1;

            if(left<=right){
                int total= prefixSum[right]- (left>0 ? prefixSum[left-1] : 0);
                maxSum=max(maxSum, total);
            }
        }
        return maxSum;
    }
};

// another approach
// Time: O(n + k * log n)
// Space: O(n)