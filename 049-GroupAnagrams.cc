/* Given an array of strings, group anagrams together.

For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"],
Return:

[
  ["ate", "eat","tea"],
  ["nat","tan"],
  ["bat"]
]
*/
Note: All inputs will be in lower-case.
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string,multiset<string> > mp;
        for(auto s:strs) {
            string t=s;
            std::sort(t.begin(),t.end());
            mp[t].insert(s);
        }
        
        for(auto ms:mp) {
            vector<string> vi(ms.second.begin(),ms.second.end());
            res.push_back(vi);
        }
        return res;
    }
};
