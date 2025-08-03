class Solution {
public:
    int step(vector<vector<int>>& fruits, int startPos, int left, int right){
        int leftPos= fruits[left][0];
        int rightPos= fruits[right][0];

        // sab left mei h..left of startPos
        if(rightPos<=startPos){
            return startPos-leftPos;
        }
        
        // sb right mei h
        if(leftPos>=startPos){
            return rightPos-startPos;
        }

        // first move from left to right then back and vice versa and clculate the minimum value
        int leftToRight= (startPos-leftPos)+ (rightPos-leftPos);
        int rightToLeft= (rightPos-startPos)+ (rightPos-leftPos);

        return min(leftToRight, rightToLeft);
    }

    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n=fruits.size();
        int s=0;
        int e=0;
        int sum=0;
        int ans=0;

        while(e<n){
            sum+=fruits[e][1];

            // if steps increase..decrease the window size
            while(s<=e && step(fruits, startPos, s,e)>k){
                sum-=fruits[s][1];
                s++;
            }

            ans=max(ans, sum);
            e++;
        }
        return ans;
    }
};
 
//Time= O(n)  (two-pointer / sliding window)
//Space = O(1)

