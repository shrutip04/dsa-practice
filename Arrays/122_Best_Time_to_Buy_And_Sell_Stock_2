/*
==================================================

Problem: 122. Best Time to Buy and Sell Stock II
LeetCode: Medium

Approach 1: Brute Force / Recursion
Time: O(2^n)
Space: O(n)

Approach 2: Dynamic Programming
Time: O(n)
Space: O(n)

Approach 3: Greedy (Optimal)
Time: O(n)
Space: O(1)

Algorithm - Approach 1: Brute Force / Recursion
1. At every day, we have two choices:
   - Buy / hold the stock.
   - Sell the stock.
2. Explore all possible combinations of buying
   and selling.
3. Keep track of the maximum profit obtained.
4. This generates many repeated states, making
   the approach inefficient.

--------------------------------------------------

Algorithm - Approach 2: Dynamic Programming

1. Maintain two states for each day:
   - hold = maximum profit when holding a stock.
   - notHold = maximum profit when not holding a stock.
2. If we buy:
   hold = max(hold, notHold - price)
3. If we sell:
   notHold = max(notHold, hold + price)
4. Continue this for every day.
5. The final answer is the maximum profit when
   we are not holding a stock.

--------------------------------------------------

Algorithm - Approach 3: Greedy (Optimal)

1. Start with profit = 0.
2. Compare today's price with yesterday's price.
3. If today's price is greater than yesterday's
   price, take the difference as profit.
4. Add every positive difference to the total.
5. Ignore decreases because buying before a decrease
   does not provide any profit.
6. This works because every increasing sequence can
   be split into individual profitable transactions.

Example:
prices = [1, 2, 3, 4, 5]
Profit:
(2 - 1) + (3 - 2) + (4 - 3) + (5 - 4)  =   1 + 1 + 1 + 1  =   4
This is equivalent to: 5 - 1 = 4

==================================================
*/

// ---------- Approach 1 : Brute Force / Recursion ----------

// Not recommended because of exponential time.

// ---------- Approach 2 : Dynamic Programming ----------

class Solution2 {
public:
    int maxProfit(vector<int>& prices) {

        int n = prices.size();

        int hold = -prices[0];
        int notHold = 0;

        for(int i = 1; i < n; i++) {

            int prevHold = hold;

            hold = max(hold, notHold - prices[i]);

            notHold = max(notHold,
                          prevHold + prices[i]);
        }

        return notHold;
    }
};


// ---------- Approach 3 : Greedy (Optimal) ----------

class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int profit = 0;

        for(int i = 1; i < prices.size(); i++) {

            if(prices[i] > prices[i - 1]) {
                profit = profit + (prices[i] - prices[i - 1]);
            }
        }

        return profit;
    }
};
