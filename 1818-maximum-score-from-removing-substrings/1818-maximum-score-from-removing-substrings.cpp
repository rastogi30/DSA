class Solution {
    private:
    // remove ab or ba without using the stack
    string solve(string s, string str,int value,int &ans){
         int j = 0; //for written purpose only

        for (int i = 0; i < s.size(); i++) { 
            s[j++] = s[i];

            if (j > 1 &&
                s[j - 2] == str[0] &&
                s[j - 1] == str[1]) {
                j -= 2;
                ans+=value;
            }
        }

        s.erase(s.begin() + j, s.end());

        return s;
    }
public:
    int maximumGain(string s, int x, int y) {
        int ans=0;
        // call for ba;
        if(x<y){
          s=solve(s,"ba",y,ans);
          s=solve(s,"ab",x,ans);
        }
        //call for ab
        else{
          s=solve(s,"ab",x,ans);
          s=solve(s,"ba",y,ans);
        }
        return ans;
    }
};

// Time Complexity: O(n)
// Space Complexity: O(1)