/*
Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.
*/
//dfs solution with o(4^n)time complexity
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        static const vector<string> numch{" ","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> res;
        string cur(digits.size(),'0');
        if(digits.empty())
            return res;
        recur_combi(numch,cur,res,digits,digits.size(),0);
        return res;
    }
    void recur_combi(const vector<string>& numch,string &cur,vector<string> &res,string &digits,int sz,int index) {
        if(index==sz) {
            res.push_back(cur);
            return;
        }
        int ch=digits[index]-'0';
        for(int i=0;i<numch[ch].size();i++) {
            cur[index]=numch[ch][i];
            recur_combi(numch,cur,res,digits,sz,index+1);
        }
    }
};
