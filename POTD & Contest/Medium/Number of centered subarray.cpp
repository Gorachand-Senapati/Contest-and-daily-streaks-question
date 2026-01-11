class Solution {
public:
    int centeredSubarrays(vector<int>& nums) {
        int n = nums.size(), cnt =0;
        for(int i=0;i<n;i++){
            int sum =0;
            unordered_set<int>s;
            for(int j=i;j<n;j++){
                sum+=nums[j];
                s.insert(nums[j]);
                if(s.count(sum)) cnt++;
            }
        }
        return cnt;
    }
};