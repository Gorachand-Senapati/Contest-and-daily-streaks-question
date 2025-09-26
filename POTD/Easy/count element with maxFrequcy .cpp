class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int>freq;
        for(int num: nums){
            freq[num]++;//every element freqency store in map num,freq
        }
        //find maxFreq
        int maxFreq=0;
        for(auto& p: freq){
            maxFreq= max(maxFreq, p.second);
        }
        //how much have maxfreq
        int cnt=0;
        for(auto& p: freq){
            if(maxFreq == p.second){
                cnt++;
            }
        }
        return maxFreq*cnt;
    }
};// TC= O(N) SC= O(N)