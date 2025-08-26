//3000
class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int n= dimensions.size();
       int maxArea=0, maxDiag=0;
       for(int i=0;i<n;i++){
        int length= dimensions[i][0];
        int width=  dimensions[i][1];
        int currDiag= (length*length) + (width*width);
        
        if(currDiag > maxDiag || (currDiag == maxDiag && length * width > maxArea)){
            maxDiag= currDiag;
            maxArea= length * width;
        }
       } 
       return maxArea;
    }
};