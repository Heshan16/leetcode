class Solution {
public:
    inline bool vowel(char c) {
        switch(c){
                case'a':case'e':case'i':case'o':case'u':
                case'A':case'E':case'I':case'O':case'U':
                    return true;
                }
        return false;
    }
    string reverseVowels(string s) {
        for(int i=s.size()-1,j=0;i>j;) {
            while(i>j && !vowel(s[i]))
                i--;
            while(i>j && !vowel(s[j]))
                j++;
            if(i>j)
                swap(s[i--],s[j++]);
        }
        return s;
    }
};
