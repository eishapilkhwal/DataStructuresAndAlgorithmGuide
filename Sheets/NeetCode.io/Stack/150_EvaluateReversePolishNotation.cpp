// 150. Evaluate Reverse Polish Notation

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int rightOperand = 0, leftOperand = 0;
        for(auto& token : tokens){
            if (token ==  "+" || token ==  "-" || token ==  "*" || token ==  "/" ){
                rightOperand = st.top();
                st.pop() ;
                leftOperand = st.top();
                st.pop();
                if (token == "+"){
                    st.push(leftOperand + rightOperand);
                }
                else if (token == "-"){
                    st.push(leftOperand - rightOperand);
                }
                else if (token == "*"){
                    st.push(leftOperand * rightOperand);
                }
                else{
                    st.push(leftOperand / rightOperand);
                }
                
            }
            else{
                st.push(stoi(token));
            }
        }
        return st.top();

    }
};

// Time Complexity : O(N)
// Space Complexity : O(N)
