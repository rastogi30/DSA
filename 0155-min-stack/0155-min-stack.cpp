class MinStack {
public:
    stack<long long>s;
    long long mini;

    MinStack() {
        mini=INT_MAX;
    }
    
    void push(int val) {
        // for first element
        if(s.empty()){
            s.push(val);
            mini=val;
        }
        else{
            // check push value greater than mini
            if(val>=mini){
                s.push(val);
            }
            // /if less than mini then push updated value
            else{
                long long data=2LL*val-mini;
                s.push(data);
                // update mini
                mini=val;
            }
        }
    }
    
    void pop() {
        if(s.empty()){
            return;
        }
        long long curr=s.top();
        s.pop();
        // is pop value is small then calculate the new mini value for rest of the stack
        if(curr<mini){
            mini= 2LL*mini-curr;
        }
    }
    
    int top() {
        if(s.empty()){
            return -1;
        }

        long long curr=s.top();
        // if curr is ledd than mini then return the actual mini value at that point
        if(curr<mini){
            return mini;
        }
        else{
            return curr;
        }
    }
    
    int getMin() {
        if(s.empty()){
            return -1;
        }
        return mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */