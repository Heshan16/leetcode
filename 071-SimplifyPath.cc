/*
Given an absolute path for a file (Unix-style), simplify it.

For example,
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"
*/

class Solution {
public:
    string simplifyPath(string path) {
        stringstream ss(path);
        vector<string> stk;
        string res,temp;
        while(getline(ss,temp,'/')) {
            if(temp=="" || temp==".")
                continue;
            else if(temp!="..")
                stk.push_back(temp);
            else if(!stk.empty())
                stk.pop_back();
        }
        for(auto s:stk)
            res+='/'+s;
        return res.empty()?"/":res;
    }
};
