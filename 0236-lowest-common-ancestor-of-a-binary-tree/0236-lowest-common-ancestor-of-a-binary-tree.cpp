/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // base case
        if(root==NULL){
            return NULL;
        }

        if(root->val==p->val || root->val==q->val){
            return root;
        }

        TreeNode* leftAns=lowestCommonAncestor(root->left, p,q);
        TreeNode* rightAns=lowestCommonAncestor(root->right, p,q);

        // left right done se means ye hi h LCA
        if(leftAns!=NULL && rightAns!=NULL){
            return root;
        }

        else if(leftAns!= NULL && rightAns==NULL){
            return leftAns;
        }
        else if(leftAns==NULL && rightAns!=NULL){
            return rightAns;
        }
        else{
            return NULL;
        }
    }
};

// Time: O(n)
// Space: O(h), where h = height of the tree