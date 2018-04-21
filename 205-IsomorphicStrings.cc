class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<char> vcs(256,-1);
        vector<char> vct(256,-1);
        if(s.size()!=t.size())
            return false;
        int sz=s.size();
        for(int i=0;i<sz;i++) {
            if(vcs[s[i]]==-1 && vct[t[i]]==-1){
                vcs[s[i]]=t[i];
                vct[t[i]]=s[i];
            }
            else if(vcs[s[i]]==-1 || vct[t[i]]==-1 || vcs[s[i]]!=t[i] || vct[t[i]]!=s[i])
                return false;
        }
        return true;
    }
};
