class MinStack {
public:
stack<long long>st;
long long mini=INT_MAX;
    MinStack() {
        
    }
    
    void push(int val) {
                long long value = val;
        if(st.empty()) {
            mini=value;
            st.push(value);
        }
        else{
            if(value>mini) st.push(value);
            else{
                st.push(2*value - mini);
                mini = val;
            }
        }
    }
    
    void pop() {
        if(st.empty()){
            return;
        }
        else{
            long long x = st.top();
            st.pop();
            if(x<mini){
                mini=2*mini - x;
            }
        }
    }
    
    int top() {
        if(st.empty()){
            return -1;
        }
        else{
            long long x =st.top();
            if(x>mini) return x;
            return mini;
        }
    }
    
    int getMin() {
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