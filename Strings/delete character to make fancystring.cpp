//1957

// class Solution {
// public:
//     string makeFancyString(string s) { //O(n) TC & SC
//         char prev = s[0];
//         int freq = 1;
//         string ans = "";
//         ans.push_back(s[0]);

//         for(int i = 1;i<s.length();i++){
//             if(s[i] == prev){
//                 freq++;
//             } else{
//                 prev = s[i];
//                 freq =1;
//             }
//             if(freq<3) ans.push_back(s[i]);
//         }
//         return ans;
//     }
// };

class Solution {  //O(1) SC no need to extra space change in main string
public:
    string makeFancyString(string s) {
        // If size of string is less than 3, return it.
        if (s.length() < 3) {
            return s;
        }
        int j = 2;
        for (int i = 2; i < s.size(); ++i) {
            // If the current character is not equal to the previously inserted
            // two characters, then we can add it to the string.
            if (s[i] != s[j - 1] || s[i] != s[j - 2]) {
                s[j++] = s[i];
            }
        }

        // Resize the string to the number of characters added in the string,
        // given by j.
        s.resize(j);
        return s;
    }
};