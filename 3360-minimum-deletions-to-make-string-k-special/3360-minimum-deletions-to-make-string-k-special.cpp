class Solution {
public:
    int minimumDeletions(string word, int k) {
        vector<int>arr(26,0);
        int ans=INT_MAX;
        // prev ka count store kr ke chal rahe h
        int prevSum=0;
        for(int i=0;i<word.size();i++){
            // only frequency se matlab h
            arr[word[i]-'a']++;
        }

        sort(arr.begin(), arr.end());
        for(int i=0;i<26;i++){
            int del=prevSum;
            for(int j=25; j>i;j--){
                // agar arr ka last wale se diff less so baki sb se to kam ayega hi since sort kr rakha h
                // isliye break
                if(arr[j]-arr[i]<=k){
                    break;
                }
                del+=arr[j]-arr[i]-k;

            }
            ans=min(ans, del);
            // move so prev ka cnt store kr diya
            prevSum+=arr[i];
        }
        return ans;
    }
};

// TC O(n)
// space O(1)...since constant space of size 26...in both but sorting more optimised

// above one is slightly optimised one..since sort so beeche jana hi nhi...
// in below hame sb pr full check kr na pd raha tha

// int minimumDeletions(string word, int k) {
//         vector<int>arr(26,0);
//         int ans=INT_MAX;
//         for(int i=0;i<word.size();i++){
//             arr[word[i]-'a']++;
//         }

//         for(int i=0; i<26;i++){
//             int freq=arr[i];
//             int deleteCnt=0;
//             for(int j=0;j<26;j++){
//                 if(j==i){
//                     continue;
//                 }
//                 if(arr[j]<freq){
//                     deleteCnt+=arr[j];
//                 }
//                 else if(abs(arr[j]-freq)>k){
//                     deleteCnt+= abs(arr[j]-freq-k);
//                 }
//             }
//             ans=min(ans, deleteCnt);
//         }
//         return ans;
//     }