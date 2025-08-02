class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        // it store the extra one
        unordered_map<int,int>mp;
        int minElement= INT_MAX;
        vector<int>vec;

        for(auto i:basket1){
            mp[i]++;
            minElement= min(minElement, i);
        }

        for(auto i:basket2){
            mp[i]--;
            minElement= min(minElement, i);
        }

       for(auto i:mp){
         int cost=i.first;
         int freq=i.second;

         if(freq==0){
            continue;
         }

         if(abs(freq)%2){
            return -1;
         }

         for(int i=0;i<abs(freq)/2;i++){
            // push the part which are for swap
            vec.push_back(cost);
         }
       }

    //sort(vec.begin(), vec.end());
    // due to sort tc is O(nlogn) so full ki need nhi h half tk chahie
    // use nth element  which take approx O(n) so time complexity improve
     nth_element(vec.begin(), vec.begin()+ vec.size()/2, vec.end());

       long long ans=0;
       for(int i=0;i<vec.size()/2;i++){
        // minElement*2 main point it help to find min cost

        ans+= min(vec[i], minElement*2);
       }
       return ans;
    }
};

// time: O(nlogn); use sort for full vec
// if nth then if slightly improve the time complexity