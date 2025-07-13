class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        int n=players.size();
        int m=trainers.size();

        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());

        int ans=0;
        int i=0;
        int j=0;

        while(i<n && j<m){
            if(players[i]<=trainers[j]){
                ans++;
                i++;
                j++;
            }
            else if(players[i]>trainers[j]){
                j++;
            }
        }
        return ans;
    }
};

// Tc:  O(n log n + m log m) 
// space:O(1);