class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n=nums.size();

        if(k==n){
            return nums;
        }

        vector<int>temp=nums;
        
        nth_element(temp.begin(), temp.begin()+k-1, temp.end(), greater<int>());
        // ex ={5 1 2 7 4 6 9} after this let k=3 {7 9 6 5 4 1 2} place 6 at coreect place
        // average time complexity is O(n);

        int kLargest=temp[k-1];
        int countKLargest=count(temp.begin(), temp.begin()+k, kLargest);

        vector<int>result;

        for(auto num: nums){
            if(num> kLargest){
                result.push_back(num);
            }
            else if(num == kLargest && countKLargest>0){
                result.push_back(num);
                countKLargest--;
            }

            if(result.size()==k){
                break;
            }
        }
        return result;
    }
};

// in this approach we use the nthelement of c++
// see ham ko k element se matlab h to ham sb ko kyu sort kr rahe h

// nth element us ko sahi place pr place kr deta h or use se chote ko phele or fir baad wale
// isliye reverse me kara...