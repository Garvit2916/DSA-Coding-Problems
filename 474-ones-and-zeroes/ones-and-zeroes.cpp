class Solution {
public:
    vector<vector<vector<int>>> dp;

    int solve(int i, int m, int n, vector<string>& strs) {
        if (i == strs.size())
            return 0;
        if (dp[i][m][n] != -1)
            return dp[i][m][n];
        int zeros = 0, ones = 0;
        for (char ch : strs[i]) {
            if (ch == '0')
                zeros++;
            else
                ones++;
        }
        int notTake = solve(i + 1, m, n, strs);
        int take = 0;
        if (zeros <= m && ones <= n) {
            take = 1 + solve(i + 1,
                             m - zeros,
                             n - ones,
                             strs);
        }
        return dp[i][m][n] = max(take, notTake);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        int sz = strs.size();
        dp = vector<vector<vector<int>>>
             (sz, vector<vector<int>>
             (m + 1, vector<int>(n + 1, -1)));
        return solve(0, m, n, strs);
    }
};