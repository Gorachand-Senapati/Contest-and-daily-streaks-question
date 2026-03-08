3863. Minimum Operations to Sort a String
class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        string t = s;
        sort(t.begin(), t.end());
        if(s == t) return 0;
        if(n == 2)return -1;//base case as constrint not pickup whole string
        if(s[0] == t[0] || s[n-1] == t[n-1]) return 1;//when ans =1
        string s1 = s;// 1st in maximum
        sort(s1.begin(), s1.begin()+n -1);
        sort(s1.begin()+1, s1.end());
        
        string s2 = s;//if 1st in minimum
        sort(s2.begin()+1, s2.end());
        sort(s2.begin(), s2.begin()+n -1);
        if(s1 == t || s2== t) return 2;
        return 3;
    }
};