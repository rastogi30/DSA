class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n=fruits.size();
        int ans=0;
        for(int i=0;i<n;i++){
            int cnt=1;
            for(int j=0;j<n;j++){
                if(fruits[i]<=baskets[j]){
                    baskets[j]=0;
                    cnt=0;
                    break;
                }
            }
            ans+=cnt;
        }
        return ans;
    }
};

// tc:O(n*2)