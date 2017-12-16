/*
Given an integer, convert it to a roman numeral.

Input is guaranteed to be within the range from 1 to 3999.
*/

class Solution {
public:
    string intToRoman(int num) {
        string T[]={"","M","MM","MMM"};
        string H[]={"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
        string Te[]={"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
        string O[]={"","I","II","III","IV","V","VI","VII","VIII","IX"};
        return T[num/1000]+H[(num%1000)/100]+Te[(num%100)/10]+O[num%10];
    }
};
