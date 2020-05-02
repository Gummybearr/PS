class Solution {
public:
    int climbStairs(int n) {
        long long dp[4];
        dp[1] = 1;  dp[2] = 2;
        for(int i = 3;i<=n;i++) dp[i%4] = dp[(i-2)%4]+dp[(i-1)%4];
        return dp[n%4];
    }
};