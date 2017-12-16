/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
*/

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string temp(2*n,'0');
        if(n<1)
            return res;
        recur_generate(res,temp,n,0,0,0);
        return res;
    }
    void recur_generate(vector<string> &res,string &temp,int n,int i,int left_num,int cur) {
        if(i==2*n) {
            res.push_back(temp);
            return;
        }
        if(left_num<n) {
            temp[i]='(';
            recur_generate(res,temp,n,i+1,left_num+1,cur+1);
        }
        if(cur>0) {
            temp[i]=')';
            recur_generate(res,temp,n,i+1,left_num,cur-1);
        }
    }
};
