class Solution {
public:
    bool isPowerOfFour(int n) {
         return (n>0 && (n &(n-1))==0) && (n & 0x55555555) != 0;
        //(n & 0x55555555) != 0; this is for odd position bits because 4^n has 1 at odd positions
    }
};