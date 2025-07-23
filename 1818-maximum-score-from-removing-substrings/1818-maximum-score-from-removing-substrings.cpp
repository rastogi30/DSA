class Solution {
    private:
    string solve(string s, string str,int value,int &ans){
        stack<char>st;
        for(int i=0;i<s.size();i++){
            if(!st.empty() && s[i]==str[1] && st.top()==str[0]){
                st.pop();
                ans+=value;
            }
            else{
                st.push(s[i]);
            }
        }
        string left="";
        while(!st.empty()){
            left+=st.top();
            st.pop();
        }
        reverse(left.begin(),left.end());
        return left;
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