class Solution {
public:
    int residuePrefixes(string s) {
        vector<int>freq(26,0);//size lowerletter
        int uqe = 0, cnt =0;
        for(int i=0;i<s.size();i++){
            int idx = s[i] -'a';//find the char
            if(freq[idx] == 0) uqe++;
            freq[idx]++;
            int len = i +1;//0 index
            if(uqe == (len % 3)){
                cnt++;
            }
        }
        return cnt;
    }
};//TC & SC= O(n)