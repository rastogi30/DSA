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

    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();

        // store ham right mei kitna move kr sakte h with that height
        vector<int>next(n);
        next=nextSmaller(heights, n);

        // store left mei kitna move kr sakte h fir that height
        vector<int>prev(n);
        prev=prevSmaller(heights, n);
        
        // for(int i=0;i<n;i++){
        //     cout<<next[i]<< " ";
        // }
        // cout<<endl;
        // for(int i=0;i<n;i++){
        //     cout<<prev[i]<<" ";
        // }
        // cout<<endl;

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
};

// tc: O(n);
// space: O(n);