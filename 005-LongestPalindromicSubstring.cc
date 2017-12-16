/*
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example:

Input: "babad"

Output: "bab"

Note: "aba" is also a valid answer.

Example:

Input: "cbbd"

Output: "bb"
*/

//此题关键是要要找准对谁进行遍历，显然，对回文串的中点遍历处理起来最为简单
//故，对字符串的字符一一检查，其作为回文串的中点时是否其最大回文串的大小
class Solution {
public:
    string longestPalindrome(string s) {
        int sz=s.size(),max_len=0,mid=0,pos=0;
        while(mid<sz && sz-mid>max_len/2) {//cut
            int beg=mid,end=mid;
            while(end<sz-1 && s[end]==s[end+1]) //for repeat char,it's so amazing
                end++;
            mid=end+1;
            while(beg>0 && end<sz-1 && s[beg-1]==s[end+1]) {
                beg--;
                end++;
            }
            if(end-beg+1>max_len) {
                max_len=end-beg+1;
                pos=beg;
            }
        }
        return string(s,pos,max_len);
    }
};
