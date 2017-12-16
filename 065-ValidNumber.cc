/*
Validate if a given string is numeric.

Some examples:
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true

Note: It is intended for the problem statement to be ambiguous. You should gather all requirements up front before implementing one. 
*/
class Solution {
public:
    bool isNumber(string s) {
        bool exp=false,dot=false,first=true;
        int t=0,sz=s.size(),end;
        for(t=0;t<sz && isspace(s[t]);t++)
            ;
        for(end=s.size()-1;end>=0 && isspace(s[end]);end--)
            ;
        if(t<=end && (s[t]=='-' || s[t]=='+'))
            t++;
        for(int i=t;i<=end;i++) {
            if(s[i]=='e') {
                if(exp || i==end || first)
                    return false;
                if(s[i+1]=='-' || s[i+1]=='+'){
                    if(i+1==end)
                        return false;
                    i++;
                }
                exp=true;
            }
            else if(s[i]=='.') {
                if(dot || exp)
                    return false;
                dot=true;
            }
            else if(isdigit(s[i])) {
                first=false;
            }
            else
                return false;
        }
        if(first)
            return false;
        return true;
    }
};
