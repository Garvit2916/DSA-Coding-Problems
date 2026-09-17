class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int k = primes.size();

        vector<long long> ugly(n);
        ugly[0] = 1;

        vector<int> idx(k, 0);

        for (int i = 1; i < n; i++) {
            long long next = LLONG_MAX;

            // Find the next smallest super ugly number
            for (int j = 0; j < k; j++) {
                next = min(next, ugly[idx[j]] * primes[j]);
            }

            ugly[i] = next;

            // Move all pointers that generated this number
            for (int j = 0; j < k; j++) {
                if (ugly[idx[j]] * primes[j] == next) {
                    idx[j]++;
                }
            }
        }

        return ugly[n - 1];
    }
};