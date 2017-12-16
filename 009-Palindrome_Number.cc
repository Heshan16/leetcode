/*Determine whether an integer is a palindrome. Do this without extra space.*/


//本来此题转换成字符串再一一检验，十分简单且直观，但题中已说不可多用空间。
//那么可考虑，用另一个数字表示其回文后的前半部分，显然对于回文数字，回文后的数字一定不可能大于原数字。
//注意，中间字符若仅有一个 则需回文乘之后，而原数未除10才两数相等。而两个中间字符的情况，则需两边均操作后才相等。故注意要在while循环结束后检验是否rev/10==x
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0 ||(x!=0 && x%10==0))
            return false;
        int rev=0;
        while(x>rev) {
            rev=rev*10+x%10;
            x/=10;
        }
        return (x==rev)||(rev/10==x);
    }
}
