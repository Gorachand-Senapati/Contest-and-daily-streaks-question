int n = nums.size();
        vector<bool> isPrime(n, true);
        isPrime[0] = isPrime[1] = false;

        // Sieve of Eratosthenes to mark prime indices
        for (int i = 2; i * i < n; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j < n; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        long long sumA = 0, sumB = 0;
        for (int i = 0; i < n; i++) {
            if (isPrime[i]) {
                sumA += nums[i];
            } else {
                sumB += nums[i];
            }
        }

        return abs(sumA - sumB);