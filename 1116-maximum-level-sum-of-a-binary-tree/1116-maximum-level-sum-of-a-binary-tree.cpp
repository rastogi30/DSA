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
    int maxLevelSum(TreeNode* root) {
        int ans=0;
        int maxsum=INT_MIN;
        int level=0;
        
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            int sum=0;
            int size=q.size();
            level++;

            // traverse in the q and add sum of the row
            for(int i=0;i<size;i++){
                TreeNode *temp=q.front();
                q.pop();
                sum+=temp->val;

                // store the left and right chil of that node
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }

            // if sum is more update maxsum and index in ans
            if(sum>maxsum){
                maxsum=sum;
                ans=level;
            }
        }
        return ans;
    }
};

// Time: O(n)
// Space: O(w) (tree width)