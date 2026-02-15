class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        unordered_map<char,int> mp;
        for(int i = 0; i < 26; i++){
            mp['a' + i] = weights[i];
        }
        // Step 2: Store reverse alphabet order
        vector<char> revAlpha(26);
        for(int i = 0; i < 26; i++){
            revAlpha[i] = 'z' - i;
        }
        /*
            revAlpha[0] = 'z'
            revAlpha[1] = 'y'
            ...
            revAlpha[25] = 'a'
        */
        // Step 3: Process words
        string result = "";
        for(auto &w : words){
            int sum = 0;
            for(char ch : w){
                sum += mp[ch];
            }
            int index = sum % 26;
            result += revAlpha[index];
        }
        return result;
    }
};