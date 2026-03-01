class Solution {
public:
    bool isVowel(char ch){
        if(ch == 'a' || ch=='e' ||ch=='o'|| ch=='i' ||ch=='u'){
            return true;
        }
        return false;
    }
    string trimTrailingVowels(string s) {
      while(!s.empty() && isVowel(s.back())){
          s.pop_back();
      }
        return s;
    }
};