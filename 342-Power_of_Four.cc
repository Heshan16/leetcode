//Solution 1,seems stupid
class Solution {
public:
    bool isPowerOfFour(int num) {
        switch(num) {
                case 0x00000001:case 0x00000004:
                case 0x00000010:case 0x00000040:
                case 0x00000100:case 0x00000400:
                case 0x00001000:case 0x00004000:
                case 0x00010000:case 0x00040000:
                case 0x00100000:case 0x00400000:
                case 0x01000000:case 0x04000000:
                case 0x10000000:case 0x40000000:
                    return true;
        }
        return false;
    }
};

//Solution 2
class Solution {
public:
    bool isPowerOfFour(int num) {
        return num>0 && (num&(num-1))==0 && (num-1)%3==0;   
    }
};
