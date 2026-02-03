class Solution {
public:
    int countMonobit(int n) {
        int cnt =1;//1st 0 store in cnt
        int val =1;//start form 1 // 2^1 - 1 = 1
        while(val <= n){
            cnt++;
            val=( val<<1) | 1; //shift left + add 1 menas 1,11,111, means 2^k -1 untill val overtake
        }
       return cnt;
    }
};