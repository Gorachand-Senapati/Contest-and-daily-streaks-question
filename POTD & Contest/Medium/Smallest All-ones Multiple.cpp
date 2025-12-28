class Solution {
public:
    int minAllOneMultiple(int k) {
        if(k == 2 || k==5) return -1;//bcz number never even 0,2 thakbe na
        int rem =0;
        for(int sz=1;sz<=k;sz++){
            rem = (rem *10+1)% k ;//for last add 1 so +1
            if(rem ==0) return sz;
        }
        return  -1;
    }
};