/*
Write a function to find the longest common prefix string amongst an array of strings.
*/
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res=strs.empty()?"":strs[0];
        int sz=strs.size(),max_i=res.size(),j=0;
        for(int i=1;i<sz;i++) {
            int msz=min(int(strs[i].size()),max_i);
            for(j=0;j<msz && res[j]==strs[i][j];j++) 
                ;
            if(j<max_i)
                max_i=j;
        }
        return string(res,0,max_i);
    }
};
