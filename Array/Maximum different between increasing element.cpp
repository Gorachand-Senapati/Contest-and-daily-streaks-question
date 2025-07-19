LC = 2016

class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n= nums.size();
        int minVal= nums[0];
        int maxDiff =-1;

        // for(int i=0;i<n-1;i++){
        //     for(int j=i+1;j<n;j++){
        //         if(nums[i]<nums[j]){
        //             maxDiff= max(maxDiff,nums[j] - nums[i]);
        //         } 
        //     }
        // }
        for(int i=1;i<n;i++){
            if(minVal<nums[i]){
                maxDiff= max(maxDiff,nums[i] - minVal);
            } else{
                minVal = nums[i]; //update minval;
            }
        }
        return maxDiff;
    }
};