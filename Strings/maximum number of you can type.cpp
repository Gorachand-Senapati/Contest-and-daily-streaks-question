class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_set<char>broke(brokenLetters.begin(), brokenLetters.end());//all brokenletters word put in a set
        stringstream ss(text);//split text by spaces
        string word;
        int cnt=0;
        while(ss>>word){//take one word at a time
            bool valid= true;
            for(char c:word){
                if(broke.count(c)){//if briken letter found in word
                    valid=false;
                    break;
                }
            }
            if(valid)cnt++;//no broken Letters->cnt it
        }
        return cnt;
    }
}; // TC= O(n+m) SC=O(m) n=text length m=brokenletters length