/*
Reverse bits of a given 32 bits unsigned integer.

For example, given input 43261596 (represented in binary as 00000010100101000001111010011100), return 964176192 (represented in binary as 00111001011110000010100101000000).
*/

//Solution 1

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int bit=0;
        uint32_t res=0;
        for(int i=0;i<32;i++){
            bit=n&1;
            res<<=1;
            res=res|bit;
            n>>=1;
        }
        return res;
    }
};


//Solution 2
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        n=(n>>16)|(n<<16);
        n=((n&0xff00ff00)>>8)|((n&0x00ff00ff)<<8);
        n=((n&0xf0f0f0f0)>>4)|((n&0x0f0f0f0f)<<4);
        n=((n&0xcccccccc)>>2)|((n&0x33333333)<<2);
        n=((n&0xaaaaaaaa)>>1)|((n&0x55555555)<<1);
        return n;
    }
};
