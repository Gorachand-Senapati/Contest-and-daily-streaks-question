//3021
class Solution {
public:
    long long flowerGame(int n, int m) {
        // you see only odd case alice win
        // odd = odd+even, even+odd
        return 1LL * (n / 2) * ((m + 1) / 2) //even x odd y
     + 1LL * ((n + 1) / 2) * (m / 2);//odd x even y

    }
};