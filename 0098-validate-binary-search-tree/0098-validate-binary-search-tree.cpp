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
   bool isBST(TreeNode* root, long long min, long long max){
    if(root==NULL){
        return true;
    }

    if(root->val>min && root->val<max){
        bool left= isBST(root->left, min, root->val);
        bool right= isBST(root->right,root->val, max);

        return left && right;
    }
    else{
        return false;
    }
   }
    bool isValidBST(TreeNode* root) {
        return isBST(root, LLONG_MIN, LLONG_MAX);
    }
};

// approach 1:
// time ans space is O(n)
// class Solution {
// public:
//     void inorder(TreeNode* root, vector<int>&value){
//         if(root==NULL){
//             return;
//         }

//         inorder(root->left, value);
//         value.push_back(root->val);
//         inorder(root->right, value);
//     }

//     bool isValidBST(TreeNode* root) {
//         vector<int>value;

//         inorder(root, value);

//         for(int i=1;i<value.size();i++){
//             if(value[i]<value[i-1]){
//                 return false;
//             }
//         }
//         return true;
//     }
// };