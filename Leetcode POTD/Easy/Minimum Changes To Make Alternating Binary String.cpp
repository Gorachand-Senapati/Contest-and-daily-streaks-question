1758. Minimum Changes To Make Alternating Binary String

class Solution {
public:
    int minOperations(string s) {
        int n =s.size();
        int st_0=0, st_1 =0;//ops1= for 0 even ops2 for 1 even position
        for(int i=0;i<n;i++){
            if(i %2 == 0){//here even for 0
                if(s[i] == '0')st_1++;
                else st_0++;
            }else{//here even for 1
                 if(s[i] == '1')st_1++;
                else st_0++;
            }
        }
        return min(st_0,st_1);
    }
};