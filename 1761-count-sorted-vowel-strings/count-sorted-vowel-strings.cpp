class Solution {
public:
    int solve(int pos, int vowel, int n, vector<vector<int>>& dp) {

        if (pos == n)
            return 1;

        if (vowel == 5)
            return 0;

        if (dp[pos][vowel] != -1)
            return dp[pos][vowel];

        int take = solve(pos + 1, vowel, n, dp);

        int notTake = solve(pos, vowel + 1, n, dp);

        return dp[pos][vowel] = take + notTake;
    }

    int countVowelStrings(int n) {

        vector<vector<int>> dp(n + 1, vector<int>(5, -1));

        return solve(0, 0, n, dp);
    }
};