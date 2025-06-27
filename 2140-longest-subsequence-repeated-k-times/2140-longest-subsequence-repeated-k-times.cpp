class Solution {
public:
    // check subsequence h ya nhi
    bool isSubsequence(string &s, string &sub, int k){
       int i=0;
       int j=0;
       int l=sub.length();
       int n=s.length();

       while(i<n && j<k*l){
        // string k time create nhi kari size se mode kr ke check kr rahe...
        // pr condition k*l length ki
        if(s[i]==sub[j%l]){
            j++;
        }
        i++;
       }
       // id j==k*l means j reached end so subsequence h..return true;  
       return j==k*l;
    }

    bool backtracking(string& s, string& curr, vector<bool>& canUse, vector<int>& freqReq, int k,
    int maxLen, string& result){
        if(curr.length()==maxLen){
            if(isSubsequence(s,curr,k)){
                result=curr;
                return true;
            }
            return false;
        }

        for(int i=25;i>=0;i--){
            if(canUse[i] == false || freqReq[i]==0){
                continue;
            }

            char ch=i+'a';
            curr.push_back(ch);
            freqReq[i]--;

            if(backtracking(s, curr, canUse, freqReq, k, maxLen, result)==true){
                return true;
            }

            curr.pop_back();
            freqReq[i]++;
        }
        return false;
    }

    string longestSubsequenceRepeatedK(string s, int k) {
        int n=s.length();
        string result;

        // maxLength of the sequence
        int maxLen=n/k;

        int freq[26]={};
        for(int i=0;i<n;i++){
            freq[s[i]-'a']++;
        }

        vector<bool>canUse(26,false);
        vector<int>freqReq(26,0);
        for(int i=0;i<26;i++){
            if(freq[i]>=k){
                canUse[i]=true;
                freqReq[i]=freq[i]/k; // atmost this can be used in one sequence
            }
        }

        string curr;
        for(int len=maxLen; len>=0 ;len--){
            vector<int> tempFreqReq= freqReq;
            if(backtracking(s, curr, canUse, tempFreqReq, k, len, result) == true){
                return result;
            }
        }

        return result;
    }
};

// TC: O(n* (n/k)!)
// space O(n/k) at most hold strings of size O(n/k) -> very small.
