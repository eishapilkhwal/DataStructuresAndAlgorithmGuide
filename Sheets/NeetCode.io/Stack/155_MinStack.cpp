// 155. Min Stack

class MinStack {
private: 
    stack<int> st;
    stack<int> minStack;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        if(minStack.empty() || val <= minStack.top()){
            minStack.push(val);
        }
    }
    
    void pop() {
        if (!minStack.empty() && minStack.top() == st.top()){
            minStack.pop();
        }
        st.pop();
    }
    
    int top() {
        return st.empty() ? -1 : st.top();
    }
    
    int getMin() {
        return minStack.empty() ? -1 : minStack.top();
    }
};

// Time Complexity : O(1)
// Space Complexity : O(N)
