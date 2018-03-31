/*
 Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Some examples:

  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6

*/

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> operand;
        for(auto &s:tokens) {
            if(s.size()>1 || isdigit(s[0]))
                operand.push(stoi(s));
            else {
                int t=operand.top();
                operand.pop();
                int v=operand.top();
                operand.pop();
                switch(s[0]) {
                    case '+':
                        operand.push(v+t);
                        break;
                    case '-':
                        operand.push(v-t);
                        break;
                    case '*':
                        operand.push(v*t);
                        break;
                    case '/':
                        operand.push(v/t);
                        break;
                }
            }
        }
        return operand.top();
    
