class Solution {
public:
    bool checkDivisibility(int n) {
        int sum =0, product =1;
        int original = n;
        while(n >0){
            int rem = n % 10;
            sum+= rem;
            product*= rem;
            n= n/10;
        }
        int totalSum = sum + product;
        if(original % totalSum == 0){
            return true;
        } else{
            return false;
        }
        
    }
};