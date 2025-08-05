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
    TreeNode* mapping(TreeNode* root, int start, unordered_map<TreeNode*, TreeNode*> &nodeToParent){
        TreeNode* res=NULL;

        queue<TreeNode*>q;
        q.push(root);
        nodeToParent[root]=NULL;

        while(!q.empty()){
            TreeNode* front=q.front();
            q.pop();

            if(front->val== start){
                res=front;
            }

            if(front->left){
                nodeToParent[front->left]= front;
                q.push(front->left);
            }

            if(front->right){
                nodeToParent[front->right]= front;
                q.push(front->right);
            }
        }
        return res;
    }

    int solve(TreeNode* root, unordered_map<TreeNode*, TreeNode*>&nodeToParent){

        int ans=0;
        queue<TreeNode*>q;
        q.push(root);

        unordered_map<TreeNode*, bool>visited;
        visited[root]=true;

        while(!q.empty()){
            int size =q.size();
            bool flag=false;

            for(int i=0;i<size;i++){
                
                TreeNode* front=q.front();
                q.pop();

                if(front->left && !visited[front->left]){
                    flag=true;
                    q.push(front->left);
                    visited[front->left]=true;
                }

                if(front->right && !visited[front->right]){
                    flag=true;
                    q.push(front->right);
                    visited[front->right]=true;
                }

                if(nodeToParent[front] && !visited[nodeToParent[front]]){
                    flag=true;
                    q.push(nodeToParent[front]);
                    visited[nodeToParent[front]]=true;
                }
            }
            if(flag){
                ans++;
            }
        }
        return ans;
    }
    
    int amountOfTime(TreeNode* root, int start) {
        
        unordered_map<TreeNode*, TreeNode*>nodeToParent;
        TreeNode* target= mapping(root, start, nodeToParent);

        return solve(target, nodeToParent);


    }
};

// Time: O(n)
// Space: O(n)

