class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        vector<double>p(n+1, 0.0); // this store the probability
        p[0]=1.0;  // p[i] represnt the probability of getting score i

        // store the value and reuse it
        double currProbabilitySum= (k==0) ?0 : 1;

        for(int i=1;i<=n;i++){
            p[i]= currProbabilitySum/maxPts;

            if(i<k){
                currProbabilitySum+=p[i];
            }

            if(i-maxPts>=0 && i-maxPts<k){
                currProbabilitySum-=p[i-maxPts];
            }
        }

        double sum=0.0;
        for(int i=n;i>=k;i--){
            sum+=p[i];
        }
        return sum;
    }
};
// time = O(n)

// class Solution {
// public:
//     double new21Game(int n, int k, int maxPts) {
//         vector<double>p(n+1, 0.0); // this store the probability
//         p[0]=1.0;  // p[i] represnt the probability of getting score i

//         for(int i=1;i<=n;i++){
//             for(int j=1;j<=maxPts; j++){
//                 if((i-j)>=0 && (i-j)<k){
//                     p[i]= p[i]+ p[i-j]/maxPts;
//                 }
//             }
//         }

//         double sum=0.0;
//         for(int i=n;i>=k;i--){
//             sum+=p[i];
//         }
//         return sum;
//     }
// };
// give tle
// Time complexity: O(n·maxPts) (too slow for upper limits, but works for small cases). 