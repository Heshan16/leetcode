/*
 The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R

And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);

convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR". 
*/

//观察可知，字符串是成循环的，每一个循环为2n-2个字符，而最后一个循环的字符可能少于2n-2,也即经过
//n次循环(按行输出），每次循环输出第2n-2个字符串的一或两个字符即可
//其中观察规律可知，对于第一行和第n行，只需依次输出第(2n-2)*i+0 th 字符和(2n-2)*i+n-1个字符即可(0<=i<sz/2n-2)，
//对于其他任意第j行，观察规律可知其需要依次输出（2n-2)*i+j和（2n-2)*i+n-j个字符
class Solution {
public:
    string convert(string s, int numRows) {
        string res(s);
        //when rows=1,should coping up correctly
        if(numRows<2)
            return s;
        int div=2*numRows-2,i=0,sz=s.size();
        for(int j=0;j<sz;j+=div)
            res[i++]=s[j];
        for(int t=1,tb=div-2*t;t<numRows-1;t++) {
            for(int j=t;j<sz;j+=div) {
                res[i++]=s[j];
                if(j+tb<sz) //notice
                    res[i++]=s[j+tb];
            }
        }
        for(int j=numRows-1; j<sz;j+=div)
            res[i++]=s[j];
        return res;
    }
}
