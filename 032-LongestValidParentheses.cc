/*
Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

For "(()", the longest valid parentheses substring is "()", which has length = 2.

Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.

*/
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> si;
        s+="x";
        int sz=s.size(),res=0;
        for(int i=0;i<sz;i++) {
            if(s[i]==')' && !si.empty() && s[si.top()]=='(') 
                si.pop();
            else {
                res=max(res,si.empty()?i:i-si.top()-1);
                si.push(i);
            }
        }
        return res;
    }
};
