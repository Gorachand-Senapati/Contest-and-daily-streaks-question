class Solution {
public:
    vector<int> minDistinctFreqPair(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1) return {-1,-1};
        unordered_map<int,int>freq;
        for(int x:nums){
            freq[x]++;
        }
        unordered_map<int,vector<int>>group;
        for(auto& it:freq){
            group[it.second].push_back(it.first);
        }
        int first= INT_MAX, second = INT_MAX;
        for(auto& it: group){
            auto&  vec = it.second;
            int mini = INT_MAX;
            for(int x:vec){
                mini = min(mini,x);
            }
            if(mini<first){
                second = first;
                first = mini;
            } else if(mini<second){
                second = mini;
            }
        }
        if(second == INT_MAX) return {-1,-1};
        return {first,second};
    }
};