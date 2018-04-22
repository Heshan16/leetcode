class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i=0,j=0,ssz=s.size(),tsz=t.size();
        while(i<ssz && j<tsz)
            if(s[i]==t[j++])
                i++;
        return i==ssz;
    }
};
