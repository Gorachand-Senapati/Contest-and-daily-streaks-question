class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {
        int n= nums.size();
        vector<int>neg;
        //collect non neg
        for(int x: nums){
            if(x > 0 || x == 0){
                neg.push_back(x);
            }
        }
        int m = neg.size();
        if (m==0) return nums;
        k = k%m;//normalize k
        //rotate fn
        rotate(neg.begin() , neg.begin() + k, neg.end());//rotate

        int ind =0;
        for(int i=0;i<n;i++){
            if(nums[i] > 0 || nums[i] == 0){
                nums[i] = neg[ind++];
            }
        }
        return nums;
    }
};