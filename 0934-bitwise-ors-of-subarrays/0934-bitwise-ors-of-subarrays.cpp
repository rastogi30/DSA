class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int>result;
        unordered_set<int>prev;
        unordered_set<int>curr;

        for(int i=0;i<arr.size();i++){
            // max size of prev is 32
            // max 32 bit set ho sakti h and OR h is;iye ek baar set to set hi rahegi
            for(auto x:prev){
                curr.insert(x|arr[i]);
                result.insert(x|arr[i]);
            }

            curr.insert(arr[i]);
            result.insert(arr[i]);

            prev=curr;
            curr.clear();
        }
        return result.size();
    }
};

// tc:O(n)
// space:O(n)


//brute force approach
// int subarrayBitwiseORs(vector<int>& arr) {
//         set<int>st;

//         for(int i=0;i<arr.size();i++){
//             int ans=0;
//             for(int j=i;j<arr.size();j++){
//                 ans= ans|arr[j];
//                 st.insert(ans);
//             }
//         }
//         return st.size();
//     }