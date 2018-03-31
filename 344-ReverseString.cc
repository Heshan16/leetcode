class Solution {
public:
    string reverseString(string s) {
        for(int i=s.size()-1,j=0;i>j;)
            swap(s[i--],s[j++]);
        return s;
    }
};
