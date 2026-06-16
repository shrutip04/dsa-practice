/*
==================================================
Problem: 322. Coin Change
LeetCode: Medium

Approach 1: Brute Force Recursion
Time: O(k^amount)
Space: O(amount)

-Try every coin for the current amount.
-Reduce the amount by the chosen coin.
-Recursively solve the remaining amount.
-Take the minimum answer among all choices.

ALGORITHM:
1.If amount becomes 0, return 0.
2.If amount becomes negative, return INF.
3.Try every coin.
4.Recursively solve for (amount - coin).
5.Store the minimum answer.
6.If no valid answer exists, return -1.

--------------------------------------------------

Approach 2: Bottom-Up Dynamic Programming (Optimal)
Time: O(amount * number_of_coins)
Space: O(amount)

-Define dp[i] as the minimum coins required to make amount i.
-dp[0] = 0 because amount 0 requires 0 coins.
-For every amount, try every coin.
-Assume the current coin is the last coin used.
-The remaining amount becomes (i - coin).
-If the remaining amount is possible, update dp[i].
-Final answer is stored in dp[amount].

ALGORITHM:
1.Create dp array of size amount + 1.
2.Initialize all values to INT_MAX.
3.Set dp[0] = 0.
4.For every amount i from 1 to amount:
    a.Try every coin.
    b.If coin <= i and remaining amount is valid:
         dp[i] = min(dp[i], 1 + dp[i - coin])
5.If dp[amount] is still INT_MAX, return -1.
6.Otherwise return dp[amount].

--------------------------------------------------

KEY OBSERVATION

To make amount i:

Assume coin is the LAST coin used.

Remaining amount = i - coin

If dp[i - coin] already stores the minimum coins
required for the remaining amount, then:

Current Answer
=
1 (current coin)
+
dp[i - coin]

Therefore:

dp[i] = min(dp[i], 1 + dp[i - coin])

--------------------------------------------------

WHY coin <= i ?

Example:

i = 3
coin = 5

3 - 5 = -2

Invalid.

Therefore the coin must fit into the current amount.

--------------------------------------------------

WHY dp[i - coin] != INT_MAX ?

INT_MAX means:

"This amount cannot be formed."

Example:

coins = [2]
amount = 3

dp[1] = INT_MAX

If we calculate:

1 + INT_MAX

overflow occurs.

Hence we only use dp[i - coin]
when it represents a valid answer.
*/

// ---------- Approach 1 : Brute Force Recursion ----------

class Solution1 {
public:

    int solve(vector<int>& coins, int amount) {

        if(amount == 0)
            return 0;

        if(amount < 0)
            return 1e9;

        int ans = 1e9;

        for(int coin : coins) {

            ans = min(ans,
                     1 + solve(coins, amount - coin));
        }

        return ans;
    }

    int coinChange(vector<int>& coins, int amount) {

        int ans = solve(coins, amount);

        return ans >= 1e9 ? -1 : ans;
    }
};

// ---------- Approach 2 : Bottom-Up DP (Optimal) ----------

class Solution {
public:

    int coinChange(vector<int>& coins, int amount) {

        vector<int> dp(amount + 1, INT_MAX);

        dp[0] = 0;

        for(int i = 1; i <= amount; i++) {

            for(int coin : coins) {

                if(coin <= i &&
                   dp[i - coin] != INT_MAX) {

                    dp[i] = min(
                                dp[i],
                                1 + dp[i - coin]
                            );
                }
            }
        }

        return dp[amount] == INT_MAX
                ? -1
                : dp[amount];
    }
};