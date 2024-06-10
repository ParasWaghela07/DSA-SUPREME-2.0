class Solution
{
public:
    int byRecursion(int n, int x, int y, int z)
    {
        if (n == 0)
            return 0;

        if (n < 0)
            return INT_MIN;

        int op1 = 0, op2 = 0, op3 = 0;

        if (n >= x)
            op1 = 1 + byRecursion(n - x, x, y, z);
        if (n >= y)
            op2 = 1 + byRecursion(n - y, x, y, z);
        if (n >= z)
            op3 = 1 + byRecursion(n - z, x, y, z);

        return max(max(op1, op2), op3);
    }

    int byMemo(int n, int x, int y, int z, vector<int> &dp)
    {
        if (n == 0)
            return 0;
        if (n < 0)
            return INT_MIN;
        if (dp[n] != -1)
            return dp[n];

        int op1 = 1 + byMemo(n - x, x, y, z, dp);
        int op2 = 1 + byMemo(n - y, x, y, z, dp);
        int op3 = 1 + byMemo(n - z, x, y, z, dp);

        return dp[n] = max(max(op1, op2), op3);
    }
    // Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        // int ans=byRecursion(n,x,y,z);
        vector<int> dp(n + 1, -1);
        int ans = byMemo(n, x, y, z, dp);

        if (ans < 0)
            return 0;
        return ans;
    }
};