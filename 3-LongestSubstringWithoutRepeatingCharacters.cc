//看到最长字串，则想到可以以一个表来表示是否出现重复字符，表中保存下标则刚好可以满足此题的需要
//此题应用了动态规划法
//max_len=max(max_len,i-start),即max字串有两种可能，一是包含当前最后一个字符，
//一是不包含当前最后一个字符
//i-start即是包含最后一个字符的最长不重复字串
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> appear_num(255,-1);
        int start=-1;
        int sz=s.size();
        int max_len=0;
        for(int i=0;i<sz;i++){
            //start 不包含在最长字串内
            if(appear_num[s[i]]>start){
                start=appear_num[s[i]];
            }
            appear_num[s[i]]=i;
            max_len=max(max_len,i-start);
        }
        return max_len;
    }
};
