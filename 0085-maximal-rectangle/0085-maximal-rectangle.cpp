class Solution {
public:
    vector<int> nextSmaller(vector<int>& heights, int n){
        vector<int>ans(n);

        stack<int>st;
        st.push(-1);

        for(int i=n-1;i>=0;i--){
            int curr=heights[i];
            while(st.top()!=-1 && heights[st.top()]>=curr){
                st.pop();
            }
            ans[i]=st.top();
            st.push(i);
        }

        return ans;
    }

    vector<int> prevSmaller(vector<int>& heights, int n){
        vector<int>ans(n);

        stack<int>st;
        st.push(-1);

        for(int i=0;i<n;i++){
            int curr=heights[i];
            while(st.top()!=-1 && heights[st.top()]>=curr){
                st.pop();
            }
            ans[i]=st.top();
            st.push(i);
        }

        return ans;
    }

    int largestRectangleArea(vector<int>& heights, int n) {

        // store ham right mei kitna move kr sakte h with that height
        vector<int>next(n);
        next=nextSmaller(heights, n);

        // store left mei kitna move kr sakte h fir that height
        vector<int>prev(n);
        prev=prevSmaller(heights, n);
        
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            int length=heights[i];

            if(next[i]==-1){
                // means end tk pauch gaya h next..
                next[i]=n;
            }

            // by seeing right and left we get the width of the rectangle
            int breadth=next[i]-prev[i]-1;

            int area= length*breadth;
            ans=max(ans,area);
            //cout<<length<<" "<<breadth<<" "<<ans<<endl;
        }
        return ans;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
         int n=matrix.size();
        int m=matrix[0].size();

        vector<int> heights(m, 0);
        int maxArea = 0;

        for (int i = 0; i < n; i++) {
            // build histogram row-wise from char matrix
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == '1') {
                    heights[j] += 1;
                } else {
                    heights[j] = 0;
                }
            }
            maxArea = max(maxArea, largestRectangleArea(heights, m));
        }

        return maxArea;

        // if we convert char to int matrix then more extra space
        // vector<vector<int>> intMatrix(matrix.size(), vector<int>(matrix[0].size()));
        // for (int i = 0; i < matrix.size(); ++i) {
        //     for (int j = 0; j < matrix[0].size(); ++j) {
        //         intMatrix[i][j] = matrix[i][j] - '0';
        //     }
        // }
        // int area= largestRectangleArea(intMatrix[0],m);
        
        // for(int i=1;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         if(intMatrix[i][j]!=0){
        //             intMatrix[i][j]= intMatrix[i][j]+ intMatrix[i-1][j];
        //         }
        //         else{
        //             intMatrix[i][j]=0;
        //         }
        //     }
            
        //     area=max(area, largestRectangleArea(intMatrix[i],m));
        // }
        // return area;
    }
};

// more otimial DP

// break in the largest rectangle in histogram..then solve this
// one by one make all rows as the base and add the add elements to it previous one
// TC O(m*n)
// space o(m);