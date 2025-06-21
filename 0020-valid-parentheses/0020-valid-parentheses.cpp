class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                st.push(s[i]);
            }
            else{
                // closing bracket
                if(!st.empty()){
                    char top=st.top();
                    if((s[i]==')' && top=='(') ||
                       (s[i]=='}' && top=='{') || (s[i]==']' && top=='[') ){
                        st.pop();
                    }
                    else{
                        return false;
                    }
                }
                else{
                    // stack empty and closing bracket mil gaya so unbalanced
                    return false;
                }
            }
        }
        // check stack mei kuch bacha to nhi
        if(st.empty()){
            return true;
        }
        else{
            return false;
        }
    }
};

// TC: O(n)
// space: O(n);