class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        vector<int>ans;
        int n =bulbs.size();
        unordered_map<int,int>freq;
        for(int i=0;i<n;i++){
            freq[bulbs[i]]++;
        }
        for(auto& it: freq){
            if(it.second %2 != 0){
                ans.push_back(it.first);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};