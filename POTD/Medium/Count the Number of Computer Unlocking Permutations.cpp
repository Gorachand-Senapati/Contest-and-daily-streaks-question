class Solution {
public:
    int countPermutations(vector<int>& complexity) {
        int M = 1e9 +7;
        long long ans =1;//if all number is greater than complexity [0] then always ans 1 
        for(int i=1;i<complexity.size();i++){
            if(complexity[i] <= complexity[0]){
                return 0;//if any value is less than or equal to complextiy[0] then return 0
            }
            //now find factorial ans * (n-1)!
            ans = (ans * i ) % M;
        }
        return ans;
    }
};