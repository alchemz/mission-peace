class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1,amount+1);
        dp[0] = 0;
        for (int i = 0; i < coins.size(); ++i) {
            for (int j = 1; j <= amount; ++j) { 
                if (j>=coins[i]) { //需要3，有2的硬币
                    dp[j] = min(dp[j], dp[j - coins[i]] + 1);
                }
            }
        }
        if(dp[amount] > amount) 
            return -1;
        return dp[amount];
    }
};


// equation:
// if j>= coins[i]
//     T[i][j] = T[i-1][j] + T[i][j-1];
// else
//     T[i][j] = T[i-1][j]
