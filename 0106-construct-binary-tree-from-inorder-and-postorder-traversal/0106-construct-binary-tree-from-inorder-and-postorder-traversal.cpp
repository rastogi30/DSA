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
    TreeNode* solve(vector<int> &inorder, vector<int> &postorder, int &index, int inorderstart, int inorderend, int n, unordered_map<int,int> &mp){
       
      if(index < 0 || inorderstart> inorderend){
          return NULL;
      }
       
      int element= postorder[index--];
      TreeNode* root=new TreeNode(element);
       
      int position= mp[element];
       
      root->right= solve(inorder, postorder, index, position+1, inorderend, n, mp);
      root->left= solve(inorder, postorder, index, inorderstart, position-1, n, mp);
       
      return root;
       
  }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

        int n=inorder.size();
        int index=n-1;
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[inorder[i]]=i;
        }
        TreeNode *ans= solve(inorder, postorder, index, 0, n-1, n,mp);
        return ans;
    }
};

// Time: O(n)
// Space :O(n)