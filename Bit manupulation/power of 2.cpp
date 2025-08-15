class Solution {
public:
    bool isPowerOfTwo(int n) {
        return (n>0 && (n &(n-1))==0);//here only 1 bit is set so it is power of 2 and if -1 is added to it then it will become 0
    }
};