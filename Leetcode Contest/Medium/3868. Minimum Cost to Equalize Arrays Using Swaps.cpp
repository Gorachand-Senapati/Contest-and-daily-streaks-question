class Solution {
public:
    int minCost(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int>freq;//even check
        unordered_map<int, int>hash;//how much time present
        for(int x:nums1){
            freq[x]++;
            hash[x]++;
        }
        for(int x:nums2){
            freq[x]++;
            hash[x]--;
        }
        for(auto& it:freq){
            if(it.second %2 != 0) return -1;
        }
        int ans =0;
        for(auto& it:hash){
            ans+= abs(it.second /2);
        }
        return ans/2;
    }
};