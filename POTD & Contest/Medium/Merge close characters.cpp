class Solution {
public:
    string mergeCharacters(string s, int k) {
        string merged= "";
        int n = s.size();
        for(int i=0;i<n;i++){
            int m= merged.size(),equal =0;
            for(int j=m-1;j>= max(0,m-k);j--){
                if(s[i] == merged[j]) equal =1;//here merge occurs ignore
            }
            if(!equal){
                merged.push_back(s[i]);//new inser
            }
        }
        return merged;
    }
};