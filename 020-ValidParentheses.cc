/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
*/
class Solution {
public:
    bool isValid(string s) {
        stack<char> sc;
        unordered_map<char,char> par{{')','('},{']','['},{'}','{'}};
        for(auto c:s) {
            if(c=='(' || c=='[' || c=='{')
                sc.push(c);
            else {
                if(sc.empty() || sc.top()!=par[c])
                    return false;
                sc.pop();
            }
        }
        return sc.empty()?true:false;
    }
};
