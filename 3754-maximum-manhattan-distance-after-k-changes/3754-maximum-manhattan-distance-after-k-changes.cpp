class Solution {
public:
    int maxDistance(string s, int k) {
        int maxi=0;
        int n=0;
        int so=0;
        int e=0;
        int w=0;

        for(int i=0;i<s.size();i++){
            
            if(s[i]=='N'){
                n++;
            }
            else if(s[i]=='S'){
                so++;
            }
            else if(s[i]=='E'){
                e++;
            }
            else if(s[i]=='W'){
                w++;
            }

            // cal curr distance
            int curr =abs(n-so)+ abs(e-w);
            int step=i+1;

            // step se kam means...back aya h...jaise move to east to west aya h..so east west jane se cancel bhi hua
            int wasted= step-curr;

            int extra=0;
            if(wasted!=0){
                // means best case nhi h
                // ek change hua us ka distance and ek ko cancel kara us kr so increment by 2
                extra=min(2*k, wasted);
            }

            int finalCurr= curr+extra;
            // in each step calculate the distance 
            maxi=max(maxi, finalCurr);
        }
        return maxi;
    }
};

// tc o(n);