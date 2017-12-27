/*
 Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

a) Insert a character
b) Delete a character
c) Replace a character
*/

class Solution {
public:
    int minDistance(string word1, string word2) {
        int sz2=word2.size();
        vector<int> step(sz2+1);
        for(int i=0;i<=sz2;i++)
            step[i]=sz2-i;
        for(int i1=word1.size()-1;i1>=0;i1--) {
            for(int i2=sz2-1,last=step[sz2]++;i2>=0;i2--) {
                last=min(last+(word1[i1]!=word2[i2]),min(step[i2],step[i2+1])+1);
                swap(last,step[i2]);
            }
        }
        return step[0];
    }
};
