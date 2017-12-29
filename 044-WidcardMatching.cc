/*
Implement wildcard pattern matching with support for '?' and '*'.

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "*") → true
isMatch("aa", "a*") → true
isMatch("ab", "?*") → true
isMatch("aab", "c*a*b") → false

*/

class Solution {
public:
    bool isMatch(string s, string p) {
        int ssz=s.size(),psz=p.size();
        vector<vector<bool>> match(ssz+1,vector<bool>(psz+1,false));
        match[ssz][psz]=true;
        for(int t=psz-1;t>=0 && p[t]=='*';t--)
            match[ssz][t]=true;
        for(int pi=psz-1;pi>=0;pi--) {
            for(int si=ssz-1;si>=0;si--) {
                if((p[pi]!= '*' ) && (s[si]==p[pi] || p[pi]=='?'))
                    match[si][pi]=match[si+1][pi+1];
                else if(p[pi]=='*')
                   match[si][pi]=(match[si+1][pi]|match[si][pi+1]);
                else
                   match[si][pi]=false;
            }
        }
        return match[0][0];
    }                   
};
