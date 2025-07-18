/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
      // map it keep in sorted form in term of horizontal distance
        // int store distance and pair int store level and vector store the list o fthe node
        map<int,map<int,vector<int>>>nodes;
        // in q we require distance and level
        queue<pair<TreeNode*, pair<int,int>>>q;
        vector<vector<int>>ans;
        
        if(root==NULL){
            return ans;
        }
        
        q.push({root,{0,0}}); //o distance and o level
        
        while(!q.empty()){
            pair<TreeNode*, pair<int,int>> temp=q.front();
            q.pop();
            
            TreeNode* firstNode=temp.first;
            int distance=temp.second.first;
            int level=temp.second.second;
            
            nodes[distance][level].push_back(firstNode -> val);
            
            if(firstNode->left){
                q.push({firstNode->left,{distance-1, level+1}});
            }
            if(firstNode->right){
                q.push({firstNode->right,{distance+1, level+1}});
            }
        }
        
        for (auto& i : nodes) {
            vector<int> col;
            for (auto& j : i.second) {
                // sort the valuse of the same row
                sort(j.second.begin(),j.second.end());
                // if do direct then seperate vector so first combine same distance one
                col.insert(col.end(), j.second.begin(), j.second.end());
            }
            ans.push_back(col);
        }
        return ans;
        
    }
};