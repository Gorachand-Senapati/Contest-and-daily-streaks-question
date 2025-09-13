class Solution {
public:
 bool isVowel(char c){
    return c=='a'|| c=='e' || c=='i' || c=='o' || c=='u';
 }
    int maxFreqSum(string s) {
        unordered_map<char, int>mp;
        //give freq in map
        for(auto ch: s){
            mp[ch]++;
        }
        int vowel =0, consonent =0;
        for(char ch='a';ch<='z';ch++){
            if(isVowel(ch)){
                vowel= max(vowel, mp[ch]);
            }else {
                consonent= max(consonent, mp[ch]);
            }
        }
        return vowel+consonent;
    }
};