class Solution {
public:
    int MOD= 1e9+7;
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int>powers;
        vector<int>product;

        for(int i=0; i<32; i++){
            if((n&(1<<i)) != 0){
                // means bit set h to power add 2^i;
                // 2^i==1<<i
                powers.push_back(1<<i);
            }
        }

        for(auto query:queries){
            int start=query[0];
            int end=query[1];
            long long pro=1;
            // max 32 bit set so this loop run O(32)
            for(int j=start; j<=end;j++){
                pro= (pro*powers[j])%MOD;
            }

            product.push_back(pro);
        }
        return product;
    }
};

// Time Complexity: O(m)
// Space Complexity: O(m)