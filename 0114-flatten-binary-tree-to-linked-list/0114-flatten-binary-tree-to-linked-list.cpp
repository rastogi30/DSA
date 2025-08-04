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
    void flatten(TreeNode* root) {
        TreeNode* curr=root;

        while(curr){
            if(curr->left){
                TreeNode* prev= curr->left;
                while(prev->right){
                    prev=prev->right;
                }

                prev->right=curr->right;
                curr->right=curr->left;
                curr->left=NULL;
            }
             curr=curr->right;
        }
    }
};

// Morish Traversal
// TC:O(n)
// space:O(1)  in other traversal space is o(n)


// Time: O(n)

// Space: O(h) (due to recursion stack)
// class Solution {
// public:
//     TreeNode* prev = nullptr;

//     void flatten(TreeNode* root) {
//         if (!root) return;

//         flatten(root->right);
//         flatten(root->left);

//         root->right = prev;
//         root->left = nullptr;
//         prev = root;
//     }
// };
