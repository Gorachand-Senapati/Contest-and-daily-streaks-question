class Solution {
public:
    long long countPairs(vector<string>& words) {
        unordered_map<string, int>freq;
        for(string s: words){
            freq[s]++;//first store the freq of the words string 
        }
        //2. make a vis map that not process vis pair again 
        unordered_map<string, bool> vis;
        long long totPair =0;//ans
        //3. process each string in words
        for(string s: words){
            if(vis[s]) continue;// // if this string is already part of a processed group
            long long grpSize =0;// total strings in this similarity group{aa,bb,cc,..zz}
            //generate all 26 transformation
            for(int j=0;j<26;j++){
                string t = s;//copy 
                //apply same shift to every char
                for(int i=0;i<t.size();i++){
                    int val = t[i] - 'a';//char to int transform0-25
                    val= (val+j) %26;// 25+1 26 % 26 =0 means a after z came a
                    t[i] = 'a' + val;//again char a+3 = d
                }
                //add freq value if exist this transform string
                grpSize += freq[t];//ab=1, za=1 so grpSize =2
                vis[t] = true;//make this transform string visited
            }
            totPair += grpSize * (grpSize-1) /2;//when 2 grpsize pair = 1when 4 pair 2 totparir inc
        }
        return totPair;
    }
};