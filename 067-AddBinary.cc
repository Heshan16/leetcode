/*
 Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100". 
*/

class Solution {
public:
    string addBinary(string a, string b) {
        int sza=a.size(),szb=b.size(),sz=max(sza,szb)+1;
        string res(max(sza,szb)+1,'0');
        int carry=0;
        for(int i=1;i<=sz;i++){
            int ca=(sza>=i)?a[sza-i]-'0':0;
            int cb=(szb>=i)?b[szb-i]-'0':0;
            int sum=ca+cb+carry;
            res[sz-i]=sum%2+'0';
            carry=sum/2;
        }
        if(res[0]=='0')
            return string(res.begin()+1,res.end());
        return res;
    }
};
