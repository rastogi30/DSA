class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int n=events.size();
        sort(events.begin(), events.end());

        // hame last day se matlab h isliye min heap mei store kon phele khatam ho raha h
        priority_queue<int, vector<int>, greater<int>>pq;

        int day=events[0][0];
        int cnt=0;
        int i=0;

        while(!pq.empty() || i<n){

            while(i<n && events[i][0]== day){
                pq.push(events[i][1]);
                i++;
            }

            if(!pq.empty()){
                pq.pop();
                cnt++;
            }

            day++;
            
            // skip events jingi end date nikal gai h
            while(!pq.empty() && pq.top()<day){
                pq.pop();
            }
        }
        return cnt;
    }
};

// TC: O(nlogn)
// space: O(n)
