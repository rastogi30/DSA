class Solution {
public:
    string makeFancyString(string s) {
       string ans="";
       int cnt=0;

       ans.push_back(s[0]);
       cnt++;

       for(int i=1;i<s.size();i++){
            if(s[i]==ans.back()){
                cnt++;
                if(cnt<3){
                    ans.push_back(s[i]);
                }
            }else{
                ans.push_back(s[i]);
                cnt=1;
            }
       }
       return ans;
    }
};

// Time:O(n);