class Solution {
public:
    int minLength(vector<int>& nums, int k) {
        unordered_map<int, int>mp;//store freq
        int n= nums.size();
        int l=0, sum =0;
        int ans = INT_MAX;
        for(int r=0;r<n;r++){
            //if not find in map
            if(mp.find(nums[r]) == mp.end()){
                sum+=nums[r];
            }
            mp[nums[r]]++;//freq increase
            while(k<=sum){
                mp[nums[l]]--;//reduce l value from map
                if(mp[nums[l]] == 0){
                    mp.erase(nums[l]);//if not freq delete it
                    sum-=nums[l];
                }
                ans = min(ans,r-l+1);
                l++;
            }
        }
       if (ans == INT_MAX) return -1;
       return ans;
    }
};//TC & SC= O(n)