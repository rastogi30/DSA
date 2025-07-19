class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(),folder.end());

        vector<string>ans;
        ans.push_back(folder[0]); //sort so confirm first wala sub folder nhi hoga kisi ka

        // now check for next one ki previous wala us ka parent to nhi
        // if parent nhi h to means vo subfolder nhi h

        for(int i=1;i<folder.size();i++){
            string currfolder=folder[i];
            string previous=ans.back();

            previous+='/';
            if(currfolder.find(previous)!=0){
                // means subfolder nhi h to push in answer
                ans.push_back(currfolder);
            }
        }
        return ans;
    }
};

// Time: O(n log n + n * L)  n = total number of folder paths in the input 
// space:O(n*L)              L = average length of a folder path (number of characters in a string)