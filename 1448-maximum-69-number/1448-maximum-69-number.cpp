class Solution {
public:
    int maximum69Number (int num) {
        int place = 0;
        int index = -1;
        int temp = num;
        while(temp) {
            int remain = temp%10;
            if(remain == 6){
                index = place;
            }
            
            temp = temp/10;
            place++;
        }
        
        if(index == -1) return num;
        
        return num + 3*pow(10, index);
        
    }
};
//Approach (Without converting to string)
//T.C : O(d) , d = number of dogits in num
//S.C : O(1)


// convert into string then solve
// class Solution {
// public:
//     int maximum69Number (int num) {
//         string s=to_string(num);

//         for(int i=0;i<s.size();i++){
//             if(s[i]=='6'){
//                 s[i]='9';
//                 break;
//             }
//         }

//         int ans=stoi(s);
//         return ans;
//     }
// };

// time: O(d), where d = number of digits.

