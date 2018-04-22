class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> occur(26);
        for(auto c:magazine) 
            occur[c-'a']++;
        for(auto c:ransomNote)
            if(occur[c-'a']--<=0)
                return false;
        return true;
    }
};
