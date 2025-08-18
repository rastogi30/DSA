class Solution {
public:
    double epsilon=1e-6;

    bool solve(vector<double>&card){
        if(card.size()==1){
            if(abs(card[0]-24.0)<=epsilon){
                return true;
            }
        }

        // take 2 number
        for(int i=0;i<card.size();i++){
            for(int j=0;j<card.size();j++){
                if(i==j){
                    continue;
                }

                vector<double>temp;
                for(int k=0;k<card.size();k++){
                    if(k!=i && k!=j){
                        temp.push_back(card[k]);
                    }
                }

                double a=card[i];
                double b=card[j];

                vector<double>possibilities={a+b, a-b, b-a, a*b};
                if(abs(a)>0){
                    possibilities.push_back(b/a);
                }
                if(abs(b)>0){
                    possibilities.push_back(a/b);
                }

                for(auto val:possibilities){
                    temp.push_back(val);
                    if(solve(temp)==true){
                        return true;
                    }

                    temp.pop_back();
                }
            }
        }
        return false;
    }
    bool judgePoint24(vector<int>& cards) {
        vector<double>card;
        for(auto i:cards){
            card.push_back(double(i));
        }

        return solve(card);
    }
};

// card length is fixed so explore all possibilities
// Theoretical complexity: O(n! · 6ⁿ) for general n. but n=4 is time is O(1)
// Space: O(n²) (constant for n=4).