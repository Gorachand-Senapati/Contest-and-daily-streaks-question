class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long totalCst1 = 1LL* need1*cost1 + 1LL*need2*cost2;//buy i1,i2 seperately
        //find minimun need 
        int minNeed = min(need1,need2);
        //buy item 3 and fullfill the i1,12 requirement from minneed
        long long totalCst2= 1LL* minNeed *costBoth + 1LL*(need1 - minNeed)* cost1 +
        1LL*(need2 - minNeed)* cost2;
        //buy type 3 large requirement and then automatically satisfy both i1,12
        long long totalCst3= 1LL* max(need1,need2) * costBoth;
        return min({totalCst1,totalCst2,totalCst3});//find the min from these 3 cost
    }
};