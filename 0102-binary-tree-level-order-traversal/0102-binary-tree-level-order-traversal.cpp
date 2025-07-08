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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;

        if(root== NULL){
            return ans;
        }

        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);

        int i=0;
        ans.push_back(vector<int>());  // add vector for first level

        while(!q.empty()){
            TreeNode* temp=q.front();
            q.pop();

            if(temp==NULL){
                i++;
                if(!q.empty()){
                    q.push(NULL);
                    ans.push_back(vector<int>());  // add new vector for next level
                }
            }
            else{
                ans[i].push_back(temp->val);
                if(temp->left){
                    q.push(temp->left);
                }

                if(temp->right){
                    q.push(temp->right);
                }
            }

        }
        return ans;
    }
};

// tc:O(n)
// space:O(n)

// class Solution {
// public:
//     vector<vector<int>> levelOrder(TreeNode* root) {
//         vector<vector<int>> ans;
//         if (!root) return ans;

//         queue<TreeNode*> q;
//         q.push(root);

//         while (!q.empty()) {
//             int levelSize = q.size();             // number of nodes in this level
//             vector<int> level;                    // to store values of current level

//             for (int i = 0; i < levelSize; ++i) {
//                 TreeNode* node = q.front();
//                 q.pop();

//                 level.push_back(node->val);

//                 if (node->left)
//                     q.push(node->left);
//                 if (node->right)
//                     q.push(node->right);
//             }

//             ans.push_back(level);   // add the collected level to answer
//         }

//         return ans;
//     }
// };
