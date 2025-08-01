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
    TreeNode *solve(vector<int> &inorder, vector<int> &preorder, int &index, int inorderstart, int inorderend, int n, unordered_map<int,int> &mp){
       
      if(index>n || inorderstart> inorderend){
          return NULL;
      }
       
      int element= preorder[index++];
      TreeNode* root=new TreeNode(element);
       
      int position= mp[element];
       
      root->left= solve(inorder, preorder, index, inorderstart, position-1, n, mp);
      root->right= solve(inorder, preorder, index, position+1, inorderend, n, mp);
       
      return root;
       
  }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int index=0;
        int n=inorder.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[inorder[i]]=i;
        }
        TreeNode *ans= solve(inorder, preorder, index, 0, n-1, n,mp);
        return ans;
    }
};

// Time: O(n)
// Space :O(n)