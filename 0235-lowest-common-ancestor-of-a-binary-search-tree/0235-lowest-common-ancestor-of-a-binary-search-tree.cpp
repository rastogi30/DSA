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
        
        while(root!=NULL){
            if(root->val > p->val && root->val > q->val){
                    root=root->left;
                }
            else if(root->val < p->val && root->val < q->val){
                    root=root->right;
                }
            else{
                return root;
            }
        }
        return root;
    }
};
// iterative approach
// Time:O(h)
// space:O(1)

// recursive approach
// time:O(h)	
// space:O(h)
// class Solution {
// public:
//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//         if(root==NULL){
//             return NULL;
//         }

//         if(root->val > p->val && root->val > q->val){
//             return lowestCommonAncestor(root->left, p,q);
//         }

//         if(root->val < p->val && root->val < q->val){
//             return lowestCommonAncestor(root->right, p,q);
//         }

//         return root;
//     }
// };