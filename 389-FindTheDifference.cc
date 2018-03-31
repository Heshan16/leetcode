//Solution 1
class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> occ(26);
        for(auto c:s)
            occ[c-'a']++;
        for(auto c:t)
            if(--occ[c-'a']<0)
                return c;
        return '/';
    }
};

//Solution 2
class Solution {
public:
    char findTheDifference(string s, string t) {
        char res=0;
        for(auto c:s)
           q res^=c;
        for(auto c:t)
            res^=c;
        return res;
    }
};
