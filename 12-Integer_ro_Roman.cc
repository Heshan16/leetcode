/*
Given an integer, convert it to a roman numeral.

Input is guaranteed to be within the range from 1 to 3999.
*/
//显然对于此题而言，可以考虑，依次从数的头部算起，但这样不好操纵
//而从尾数算起最为简单，但是这样频繁的从string中插入会导致效率极低
//对于这种情形，可以用递归来解决
//故每次递归迭代，最底层递归即为首端的数字
//对于每次递归而言，其要处理的数字0-9间，roman[pos]是表征1,roman[pos+1]=5,roman[pos+2]=10

    string roman="IVXLCDM";
    string intToRoman(int num) {
        string s;
        int size=0;
        recur_getroman(s,size,num,0);
        return s;
    }
    void recur_getroman(string &s,int &size,int number,int pos) {
       //roman[pos] is 1,roman[pos+1] is 5,roman[pos+2] is 10 
        if(number<=0)
            return;
        recur_getroman(s,size,number/10,pos+2);
        int digit=number%10;
        if(digit==4 || digit==9) {
            s.push_back(roman[pos]);
            s.push_back(roman[pos+1+(digit&1)]);
            return;
        }
        if(digit>=5) {
            s.push_back(roman[pos+1]);
            digit-=5;
        }
        size=s.size();
        s.insert(size,digit,roman[pos]);
        size+=digit;
    }
