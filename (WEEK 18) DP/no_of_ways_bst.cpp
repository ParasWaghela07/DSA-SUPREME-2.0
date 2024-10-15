class Solution {
public:
    int byRec(int n) {
        if (n <= 1)
            return 1;

        int ans = 0;
        for (int i = 1; i <= n; i++) {
            ans += byRec(i - 1) * byRec(n - i);
        }
        return ans;
    }

    int byMem(int n, vector<int>& dp) {
        if (n <= 1)
            return 1;
        if (dp[n] != -1)
            return dp[n];

        int ans = 0;
        for (int i = 1; i <= n; i++) {
            ans += byMem(i - 1, dp) * byMem(n - i, dp);
        }
        return dp[n] = ans;
    }

    int byTabu(int n) {
        vector<int> dp(n + 1, 1);

        for (int nodes = 1; nodes <= n; nodes++) {
            int ans = 0;
            for (int i = 1; i <= nodes; i++) {
                ans += dp[i - 1] * dp[nodes - i];
            }
            dp[nodes] = ans;
        }

        return dp[n];
    }

    int numTrees(int n) {
        // return byRec(n);

        // vector<int>dp(n+1,-1);
        // return byMem(n,dp);

        return byTabu(n);
    }
};