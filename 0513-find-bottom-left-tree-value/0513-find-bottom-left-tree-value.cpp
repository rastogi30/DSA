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
void solve(TreeNode *root, int &ans, int level, int &levelindex){
        if(root==NULL){
            return;
        }
        
        // if the level is more than previous level then only update the asnwer otherwise no
            if(level>levelindex){
              ans=root->val;
              levelindex=level;
            }

        solve(root->left, ans, level+1, levelindex);
        solve(root->right, ans, level+1, levelindex);
    }

    int findBottomLeftValue(TreeNode* root) {
        int ans;
        int levelindex = -1;
        solve(root, ans,0,levelindex);
        return ans;
    }
};

// time:O(n)
//space:O(H), where H is the height of the tree.