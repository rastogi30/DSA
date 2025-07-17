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
     pair<bool,int>isBalancedFast(TreeNode* root){
        if(root==NULL){
            pair<int,int>p={true,0};
            return p;
        }

        pair<bool,int>left=isBalancedFast(root->left);
        pair<bool,int>right=isBalancedFast(root->right);

        bool leftAns=left.first;
        bool rightAns=right.first;

        bool diff = abs(left.second-right.second)<=1;

        pair<bool,int>ans;
        ans.second=max(left.second,right.second)+1;

        if(leftAns && rightAns && diff){
            ans.first=true;
        }
        else{
            ans.first=false;
        }
        return ans;
    }

    bool isBalanced(TreeNode* root) {
        return isBalancedFast(root).first;
    }
};

//TC :O(n);

// 2nd approach its TC:O(n*2);
// class Solution {
// public:
//     int height(TreeNode* node){
//         if(node==NULL) return 0;

//        int left= height(node->left);
//        int right=height(node->right);
//         int ans=max(left,right)+1;
//         return ans;
//     }

//     bool isBalanced(TreeNode* root) {
//         if(root==NULL){
//             return true;
//         }

//         bool left=isBalanced(root->left);
//         bool right=isBalanced(root->right);

//         bool diff=abs(height(root->left)- height(root->right))<=1;

//         if(left && right && diff){
//             return 1;
//         }
//         else{
//             return false;
//         }
//     }
// };