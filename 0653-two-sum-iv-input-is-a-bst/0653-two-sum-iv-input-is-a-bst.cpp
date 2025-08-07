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
   void inorder(TreeNode* root, vector<int>&arr){
        if(root==NULL){
            return;
        }

        inorder(root->left, arr);
        arr.push_back(root->val);
        inorder(root->right, arr);
   }
    bool findTarget(TreeNode* root, int k) {
        vector<int>arr;

        inorder(root, arr);
        int i=0;
        int j=arr.size()-1;
        while(i<j){
            int sum=arr[i]+arr[j];

            if(sum == k){
                return true;
            }
            else if(sum>k){
                j--;
            }
            else{
                i++;
            }
        }
        return false;
    }
};
// time and space:O(n)

//another approach
//time:O(n*2)...since take one node and check (target- node->val) present in tree or not
// class Solution {
// public:
//     // Search in BST for a value, skip the current node to avoid using it twice
//     bool search(TreeNode* root, TreeNode* curr, int target) {
//         if (!root) return false;
        
//         if (root->val == target && root != curr) return true;
//         else if (root->val > target) return search(root->left, curr, target);
//         else return search(root->right, curr, target);
//     }

//     // Inorder traversal, for each node check if (k - node->val) exists in the tree
//     bool dfs(TreeNode* root, TreeNode* curr, int k) {
//         if (!curr) return false;

//         if (search(root, curr, k - curr->val)) return true;

//         return dfs(root, curr->left, k) || dfs(root, curr->right, k);
//     }

//     bool findTarget(TreeNode* root, int k) {
//         return dfs(root, root, k);
//     }
// };
