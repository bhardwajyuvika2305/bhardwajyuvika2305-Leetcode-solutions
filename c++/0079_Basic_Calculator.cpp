/* Given a string s representing a valid expression,
 implement a basic calculator to evaluate it, 
 and return the result of the evaluation. */

 // Solution :- 

#include <string>
#include <stack>

class Solution {
public:
    int calculate(std::string s) {
        std::stack<int> st;
        long long current_number = 0;
        long long result = 0;
        int sign = 1; // 1 means positive, -1 means negative

        for (int i = 0; i < s.length(); ++i) {
            char c = s[i];

            if (isdigit(c)) {
                current_number = current_number * 10 + (c - '0');
            } else if (c == '+') {
                result += sign * current_number;
                current_number = 0;
                sign = 1;
            } else if (c == '-') {
                result += sign * current_number;
                current_number = 0;
                sign = -1;
            } else if (c == '(') {
                // Push the current result and sign onto the stack
                st.push(result);
                st.push(sign);
                
                // Reset for the inner parenthesis evaluation
                result = 0;
                sign = 1;
            } else if (c == ')') {
                result += sign * current_number;
                current_number = 0;
                
                // Pop the sign and previous result from before the parenthesis
                int prev_sign = st.top(); st.pop();
                int prev_result = st.top(); st.pop();
                
                result = prev_result + prev_sign * result;
            }
        }
        
        // Add any remaining number
        result += sign * current_number;
        return result;
    }
};

