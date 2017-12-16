/*
Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999.
*/

class Solution {
public:
    int romanToInt(string s) {
        int res=0;
        unordered_map<char,int> ch{{'I',1},{'V',5},{'X',10},{'L',50},
                         {'C',100},{'D',500},{'M',1000}};
        res+=ch[s.back()];
        for(int i=s.size()-2;i>=0;i--) {
            if(ch[s[i+1]]>ch[s[i]])
                res-=ch[s[i]];
            else
                res+=ch[s[i]];
        }
        return res;
    }
};
