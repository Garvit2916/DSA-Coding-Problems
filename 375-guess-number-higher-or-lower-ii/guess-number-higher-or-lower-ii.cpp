class Solution {
public:
    int solve(int l,int r,vector<vector<int>> & dp){
        if(l>=r){
            return 0;
        }
        if(dp[l][r] != -1) return dp[l][r];
        int ans = INT_MAX;
        for(int i=l;i<=r;i++){
            int cost = i+max(solve(l,i-1,dp),solve(i+1,r,dp));
            ans = min(ans,cost);
        }
        return dp[l][r] = ans;
    }
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n+1, vector<int>(n+1,-1));
        return solve(1,n,dp);
    }
};