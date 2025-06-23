class Solution {
public:
    bool isPalindrome(string s){
        int l=0;
        int r=s.size()-1;

        while(l<=r){
            if(s[l]!=s[r]){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }

    string convertToBaseK(long long num, int k){
        if(num==0){
            return "0";
        }

        string ans="";
        while(num>0){
            ans+=to_string(num%k);
            num=num/k;
        }
        return ans;
    }

    long long kMirror(int k, int n) {
        long long sum=0;
        int l=1; // palindrone of length l

        while(n>0){
            int half=(l+1)/2;
            long long num_min=pow(10,half-1);
            long long num_max=pow(10,half)-1;

            for(long long num=num_min; num<=num_max;num++){
                string first=to_string(num);
                string second=first;

                reverse(second.begin(), second.end());
                string palindroneStr="";

                if(l&1){
                    // odd length
                    palindroneStr = first+ second.substr(1);
                }
                else{
                     palindroneStr = first+ second;
                }

                long long palindroneNum= stoll(palindroneStr);

                string baseK= convertToBaseK(palindroneNum, k);

                if(isPalindrome(baseK)){
                    sum+=palindroneNum; // found one so decrease n
                    n--;
                    if(n==0){
                        break;
                    }
                }
            }
            l++;
        }
        return sum;
    }
};

//T.C : ~O((10 ^ D) * D), where D = number of digits in k-mirror number
//S.C : O(D), where D = number of digits in k-mirror number