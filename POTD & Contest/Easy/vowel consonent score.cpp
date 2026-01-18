class Solution {
public:
    int vowelConsonantScore(string s) {
        int consCnt =0, vowCnt = 0;
        for(char ch:s){
            if(ch >= 'a'&& ch<='z'){
                //check not vowel
                if(ch != 'a' && ch != 'e' && ch != 'i' && ch != 'o' && ch != 'u'){
                    consCnt++;
                }else if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
                    vowCnt++;
                }
            }
        }
        int ans =0;
        if(consCnt > 0){
            ans = floor(vowCnt / consCnt);
        } else{
            ans =0;
        }
        return ans;
    }
};