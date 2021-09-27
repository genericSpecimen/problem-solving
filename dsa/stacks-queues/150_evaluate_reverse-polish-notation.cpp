class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (string tok : tokens) {
            if (isdigit(tok.front()) || tok.size() > 1 && isdigit(tok[1])) {
                // found an integer operand
                //cout << "push operand: " << stoi(tok) << endl;
                st.push(stoi(tok));
            } else {
                // possibly found an operator
                
                if (st.size() < 2) {
                    throw std::invalid_argument("invalid RPN expression 1 ");
                }
                
                int result = 0;
                int op2 = st.top(); st.pop();
                int op1 = st.top(); st.pop();
                
                switch (tok.front()) {
                    case '+' : result = op1 + op2; break;
                    case '-' : result = op1 - op2; break;
                    case '*' : result = op1 * op2; break;
                    case '/' : result = op1 / op2; break;
                    default: throw std::invalid_argument("invalid RPN expression 2");
                }
                //cout << "push result: " << result << endl;
                st.push(result);
            }
        }
        
        if (st.empty()) {
            throw std::invalid_argument("tokens contains invalid operator");
        }
        return st.top();
    }
};
