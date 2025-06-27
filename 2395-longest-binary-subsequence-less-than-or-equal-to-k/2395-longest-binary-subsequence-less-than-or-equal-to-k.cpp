class Solution {
public:
    int longestSubsequence(string s, int k) {
        int n=s.length();
        int power=1; //2^0;
        int cnt=0;

        for(int i=n-1; i>=0;i--){
            if(s[i]=='0'){
                cnt++;
            }
            else if(power<=k){
                k=k-power;
                cnt++;
            }

            if(power<=k){
                power= power<<1;  //left shift or write as power<<=1 or power=power*2
            }
        }
        return cnt;
    }
};

// TC O(n)