class Solution {
public:
    int kthGrammar(int n, int k) {
        if(n==1 && k==1){
            return 0;
        }

        int length=pow(2, n-1);
        int mid=length/2;

        if(k<=mid){
            // see mid tk same above isliye n-1 and k pass
            // see expample written in last
            return kthGrammar(n-1, k);
        }
        else{
            // is k>min see flip ka isliye k-mid and at time or retur we flip 
           return 1- kthGrammar(n-1, k-mid);
        }
    }
};

// time: O(n);
// space: O(n) memory recursive call


// example:
// 1:0
// 2:0 1
// 3:0 1 1 0
// 4:0 1 1 0 1 0 0 1
// 5:0 1 1 0 1 0 0 1 1 0 0 1 0 1 1 0
