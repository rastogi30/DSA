class FindSumPairs {
public:
    vector<int>vec1;
    vector<int>vec2;
    unordered_map<int,int>mp;

    // O(m+n) nums1 and nums2 copy 
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        vec1=nums1;
        vec2=nums2;

        // see size of nums1 is less so ham nums2 ko map mei dal dete h
        // since nums1 ko dala so jitni baar count call iterate on nums2 and whose size is mor
        for(auto &x:nums2){
            mp[x]++;
        }
        
    }

    // O(1) since old ka count kam kara value add kari then 
    // us new value ka cnt increase kara map mei
    void add(int index, int val) {
        mp[vec2[index]]--;
        vec2[index]+=val;

        mp[vec2[index]]++;
    }
    
    // o(m)
    int count(int tot) {
        int cnt=0;
        for(auto &i:vec1){ // size of vec1 is less
            cnt+=mp[tot-i];
        }
        return cnt;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */