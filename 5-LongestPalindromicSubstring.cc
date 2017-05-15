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
string longestPalindrome(string s) {
        if(s.empty())
            return s;
        int sz=s.size();
        int mid=0;
        int beg,end;
        int max_len=1;
        int max_index=0;//important or max_len and max_len be 0
        while(mid<sz && sz-mid>max_len/2){
            beg=mid;
            end=mid;
            while(end<sz && s[end]==s[end+1])
                end++;
            mid=end+1;//notice shouldn't make mid be end
            while(beg>0 && end<sz-1 && s[beg-1]==s[end+1]){
                beg--;
                end++;
            }
            if(end-beg+1>max_len){
                max_len=end-beg+1;
                max_index=beg;
            }
        }
        return s.substr(max_index,max_len);
            
    }
