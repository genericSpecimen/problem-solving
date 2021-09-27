#include <iostream>
#include <cctype>
#include <vector>
#include <stack>
#include <cassert>

using namespace std;

std::ostream& operator<<(std::ostream& os, const std::vector<string> tokens) {
    os << "[";
    for (auto tok : tokens) os << tok << ", ";
    os << "]";
    return os;
}

bool isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

int priority(char op) {
    switch (op) {
        case '(' : return 0; break;
        
        case '+' :
        case '-' : return 1; break;
        
        case '*' :
        case '/' : return 2; break;
        
        default  : throw std::invalid_argument("invalid operator");
    }
}

vector<string> tokenize(const string &s) {
    vector<string> tokens;
    
    int i = 0, sign = 1, num = 0;
    while (i < s.size()) {
        if (isdigit(s[i])) {
            while (isdigit(s[i])) {
                num = num*10 + (s[i] - '0');
                i++;
            }
            i--;
            tokens.push_back(std::to_string(sign * num));
            sign = 1; num = 0;
        } else if ( s[i] == '-' ) {
            int j = i+1;
            while (j < s.size() && isspace(s[j])) j++;
            
            if (j == s.size()) assert(false);
            char next_token_front = s[j];
            //cout << "next_token_front = " << next_token_front << endl;
            
            
            if ( (tokens.empty() || isOperator(tokens.back().back())) && next_token_front != '(' ||
                 !tokens.empty() && tokens.back().front() == '('
            ) {
                sign = -1;
                //cout << "sign = -1" << endl;
            } else {
                tokens.push_back(string(1, s[i]));
            }
        } else if ( isOperator(s[i]) || s[i] == '(' || s[i] == ')') {
            tokens.push_back(string(1, s[i]));
        }
        i++;
    }
    
    return tokens;
}

vector<string> convertToRPN(const vector<string> &infix_tokens) {
    stack<char> st;
    vector<string> rpn_tokens;
    
    for (string tok : infix_tokens) {
        char tok_front = tok.front();
        
        if ( isdigit(tok_front) || tok.size() > 1 && isdigit(tok[1]) ) {
            rpn_tokens.push_back(tok);
        } else if (isOperator(tok_front)) {
            while (!st.empty() && priority(tok_front) <= priority(st.top()) ) {
                rpn_tokens.push_back(string(1, st.top()));
                st.pop();
            }
            st.push(tok_front);
        } else if (tok_front == '(') {
            st.push(tok_front);
        } else if (tok_front == ')') {
            while (!st.empty() && st.top() != '(') {
                rpn_tokens.push_back(string(1, st.top()));
                st.pop();
            }
            if (st.empty()) assert(false);
            st.pop(); // pop (
        } else assert(false);
    }
    
    while (!st.empty()) {
        rpn_tokens.push_back(string(1, st.top()));
        st.pop();
    }
    
    return rpn_tokens;
}

int evalRPN(vector<string>& tokens) {
    stack<int> st;
    for (string tok : tokens) {
        if (isdigit(tok.front()) || tok.size() > 1 && isdigit(tok[1])) {
            // found an integer operand
            //cout << "push operand: " << stoi(tok) << endl;
            st.push(stoi(tok));
        } else {
            // possibly found an operator
            
            if ( tok.front() != '-' && st.size() < 2) {
                throw std::invalid_argument("invalid RPN expression 1 ");
            }
            
            if ( tok.front() == '-' && st.size() == 1) {
                int operand = st.top(); st.pop();
                st.push(-1 * operand);
                continue;
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

int calculate(string s) {
    vector<string> infix_tokens = tokenize(s);
    //cout << "infix_tokens: " << infix_tokens << endl;
    
    vector<string> rpn_tokens = convertToRPN(infix_tokens);    
    //cout << "rpn_tokens: " << rpn_tokens << endl;
    
    return evalRPN(rpn_tokens);
}

int main() {
    vector<string> tests = {
        " -278--134 + -21 ",
        "(1+(4+5+2)-3)+(6+8)",
        " 2-1 + 2 ",
        "1 + 1",
        "12+7*35",
        "(12+7)*35",
        "1*(2+3)",
        "12+-7",
        "-(1)",
        "- (3 + (4 + 5))",
        "-(-1-(-2))"
    };
    
    for (string test : tests) {
        cout << test << " = " << calculate(test) << endl;
    }
}
