/*
 Implement strStr().

Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Example 1:

Input: haystack = "hello", needle = "ll"
Output: 2

Example 2:

Input: haystack = "aaaaa", needle = "bba"
Output: -1

*/
//using kmp
class Solution {
public:
    int strStr(string haystack, string needle) {
        int sz1=haystack.size(),sz2=needle.size();
        if(sz2==0)
            return 0;
        if(sz1<sz2)
            return -1;
        vector<int> next(sz2);
        getnext(next,needle);
        int i=0,j=0;
        while(i<sz1 && j<sz2) {
            if(haystack[i]==needle[j]) {
                i++;
                j++;
            }
            else if(next[j]==-1) //换成j==0亦是可以的
                i++;
            else
                j=next[j];
        }
        return j==sz2?i-sz2:-1;
    }
    void getnext(vector<int> &next,const string &needle) {
        next[0]=-1;
        int sz=next.size(),pos=2,cur=0;
        if(sz<2)
            return;
        next[1]=0;
        while(pos<sz) {
            if(needle[pos-1]==needle[cur])
                next[pos++]=++cur;
            else if(cur>0)
                cur=next[cur];
            else //上个字符0号字符不匹配
                next[pos++]=0;
        }
    }
};
