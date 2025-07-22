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
    void solve(TreeNode *root, int targetSum, vector<int>path, int &cnt){
        if(root==NULL){
            return;
        }

        path.push_back(root->val);
        solve(root->left, targetSum, path, cnt);
        solve(root->right, targetSum, path, cnt);

        int size=path.size();
        long long sum=0;
        for(int i=size-1;i>=0;i--){
            sum+=path[i];
            if(sum==targetSum){
                cnt++;
            }
        }
        path.pop_back();
    }
    int pathSum(TreeNode* root, int targetSum) {
        vector<int>path;
        int cnt=0;
        solve(root, targetSum, path, cnt);
        return cnt;
    }
};

//Time : O(n²) worst, O(n log n) average ...code recursively visits every node in the tree and for each node
//Space: O(h) where h is tree height O(h) and the recursive call stack (tree height)


//time ans space are same but other way to write...exploring all possible path
// int countPathsFromNode(Node* node, int k, int currentSum) {
//     if (node == nullptr)
//         return 0;
  
//   	int pathCount = 0;

//     // Update the current sum
//     currentSum += node->data;

//     // If current sum equals k, increment path count
//     if (currentSum == k)
//         pathCount++;

//   	// Recur for the left and right subtree
//     pathCount += countPathsFromNode(node->left, k, currentSum);
//     pathCount += countPathsFromNode(node->right, k, currentSum);
  
//   	return pathCount;
// }

// // Function to count all paths that 
// // sum to k in the binary tree
// int countAllPaths(Node* root, int k) {
//     if (root == nullptr)
//         return 0;

//     // Count all paths starting from the current node
//     int res = countPathsFromNode(root, k, 0);

//     // Recur for the left and right subtree
//     res += countAllPaths(root->left, k);
//     res += countAllPaths(root->right, k);
  
//   	return res;
// }