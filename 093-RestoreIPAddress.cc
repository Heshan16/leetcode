/*
Given a string containing only digits, restore it by returning all possible valid IP address combinations.

For example:
Given "25525511135",

return ["255.255.11.135", "255.255.111.35"]. (Order does not matter) 
*/

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        string cur;
        recur_restoreIPAddr(res,s,cur,0,1,s.size());
        return res;
    }
    void recur_restoreIPAddr(vector<string> &res,string &s,string cur,int i,int count,int sz) {
        if(count>4) {
            cur.pop_back();
            res.push_back(cur);
        }
        for(int j=1;j<=3 && i+j<=sz;j++) {
            string sdig=s.substr(i,j);
            if(sz-(i+j)<4-count || (sdig.size()>1 && sdig[0]=='0')|| stoi(sdig)>255)
                break;
            if(sz-(i+j)>3*(4-count))
                continue;
            recur_restoreIPAddr(res,s,cur+sdig+".",i+j,count+1,sz);
        }
    }
};
