class Solution {
public:
    int climbStairs(int n) {
        // --------classic fibonacci math question---------- //
        if (n == 0 || n == 1) return 1; // edge case, 0 and 1 only have one way climb to the top
        // recursive solution //
        // return climbStairs(n-1) + climbStairs(n-2);

        // DP table solution //
        // initialize dp table
        // vector<int> dp(n+1);
        // dp[0] = dp[1] = 1; // initialize 0 and 1 as one, because they only have one way to climb to the top
        // for (int i = 2; i <= n; i++){
        //     dp[i] = dp[i - 1] + dp[i - 2];
        // }
        // return dp[n];

        // space optimized solution //
        int prev = 1, curr = 1;
        for (int i = 2; i <= n; i++){
            int temp = curr;
            curr = prev + curr;
            prev = temp;
        }
        return curr;

    }
};