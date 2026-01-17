//ignore the  maximal contiguous segment which is already equal to target
//only check how much number need to be chaged 
class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& target) {
        int n = nums.size();
        unordered_set<int>s;
        
        for(int i=0;i<n;i++){
            if(nums[i] != target[i]){
                s.insert(nums[i]);
            }
        }
        return s.size();
    }//TC:O(n) SC:O(n)
};