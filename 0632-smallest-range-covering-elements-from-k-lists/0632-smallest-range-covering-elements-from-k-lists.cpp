class Solution {
public:
   class node{
    public:
     int data;
     int row;
     int col;

     node(int d, int r, int c){
        data=d;
        row=r;
        col=c;
     }
   };

   class comprator{
    public:
    bool operator()(node* a, node*b){
        return a->data > b->data;
    }
   };

    vector<int> smallestRange(vector<vector<int>>& nums) {
        int mini=INT_MAX;
        int maxi=INT_MIN;
        priority_queue<node*, vector<node*>, comprator>q;
        int k=nums.size();

        for(int i=0;i<k;i++){
            int element=nums[i][0];
            mini=min(mini, element);
            maxi=max(maxi, element);
            q.push( new node(element, i, 0));
        }

         vector<int> ans = {mini, maxi};

         while(!q.empty()){
            node *temp=q.top();
            q.pop();

            mini=temp->data;

            if(maxi-mini< ans[1]-ans[0]){
                ans[0]=mini;
                ans[1]=maxi;
            }

            if(temp->col+1< nums[temp->row].size()){
                maxi=max(maxi, nums[temp->row][temp->col+1]);
                q.push(new node(nums[temp->row][temp->col+1], temp->row, temp->col+1));
            }
            else{
                break;
            }
         }
         return ans;
    }
};
// Time : O(n*klogk) n = average length of each list k = number of lists
// Space :O(k)

// class Solution {
// public:
//     vector<int> smallestRange(vector<vector<int>>& nums) {
//         int k = nums.size();
//         // Stores the current index of each list
//         vector<int> indices(k, 0);
//         // To track the smallest range
//         vector<int> range = {0, INT_MAX};

//         while (true) {
//             int curMin = INT_MAX, curMax = INT_MIN, minListIndex = 0;

//             // Find the current minimum and maximum values across the lists
//             for (int i = 0; i < k; i++) {
//                 int currentElement = nums[i][indices[i]];

//                 // Update the current minimum
//                 if (currentElement < curMin) {
//                     curMin = currentElement;
//                     minListIndex = i;
//                 }

//                 // Update the current maximum
//                 if (currentElement > curMax) {
//                     curMax = currentElement;
//                 }
//             }

//             // Update the range if a smaller one is found
//             if (curMax - curMin < range[1] - range[0]) {
//                 range[0] = curMin;
//                 range[1] = curMax;
//             }

//             // Move to the next element in the list that had the minimum value
//             if (++indices[minListIndex] == nums[minListIndex].size()) break;
//         }

//         return range;
//     }
// };
// // Time : O(n*k^2) n = average length of each list k = number of lists
// // Space :O(k)