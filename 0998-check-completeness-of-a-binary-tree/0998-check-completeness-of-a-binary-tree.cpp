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
    int countNode(TreeNode* root){
        int cnt=0;

        if(root==NULL){
            return 0;
        }

        cnt= 1+ countNode(root->left)+ countNode(root->right);
        return cnt;
    }
    bool solve(TreeNode*root, int i, int totalCnt){

        if(root==NULL){
            return true;
        }

        if(i>=totalCnt){
            return false;
        }
        else{
            bool left=solve(root->left, 2*i+1, totalCnt);  //o based indexing
            bool right= solve(root->right, 2*i+2,totalCnt);

            return (left && right);
        } 
    }

    bool isCompleteTree(TreeNode* root) {
        int totalCnt=countNode(root);
        int index=0;
        return solve(root, index, totalCnt);
    }
};

// Time: O(n)
// Space: O(h) = O(log n) best case, O(n) worst case.