class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        unordered_map<int,int>freq;
        for(int i=0;i<nums.size();i++){
            freq[nums[i]]++;
        }
        unordered_map<int,int>freq_cnt;
        for(auto& it:freq){
            freq_cnt[it.second]++;
        }
        for(int num: nums){
            if(freq_cnt[freq[num]] ==1) return  num;
        }
        return -1;
    }
};