/*
==================================================
Problem: 121. Best Time to Buy and Sell Stock
LeetCode: Easy

Approach 1: Brute Force
Time: O(n²)
Space: O(1)

-try every possible buying day and selling day
-For each buying day , try every possible selling day after it and calculate the profit of each pair
-Store the maximum profit found

ALGORITHM:
1.Pick buying day i
2.Pick selling day j (j > i)
3.Calculate profit = prices[j] - prices[i]
4.Update max profit if profit is greater than current max profit

Approach 2: Greedy (Optimal)
-Keep track of the minimum price seen so far.
-Everyday after the first day, calculate the potential profit by selling on that day (current price - minimum price).
-Update the maximum profit if the potential profit is greater than the current maximum profit.

ALGORITHM:
1.Initialize minPrice to a very large value (e.g., INT_MAX).
2.Initialize maxProfit to 0.
3.Traverse the price array:
    a.Update minPrice if the current price is lower than minPrice.
    b.Calculate potential profit = current price - minPrice.
    c.Update maxProfit if potential profit is greater than maxProfit.
4.Return maxProfit at the end of the traversal.
*/

// ---------- Approach 1 : Brute Force ----------

class Solution1 {
public:
    int maxProfit(vector<int>& prices) {

        int maxProfit = 0;
        int n = prices.size();

        for(int i = 0; i < n; i++) {

            for(int j = i + 1; j < n; j++) {

                maxProfit =
                max(maxProfit, prices[j] - prices[i]);

            }
        }

        return maxProfit;
    }
};


// ---------- Approach 2 : Greedy (Optimal) ----------

class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int minPrice = prices[0];
        int maxProfit = 0;

        for(int i = 1; i < prices.size(); i++) {

            if(prices[i] < minPrice) {
                minPrice = prices[i];
            }

            int currentProfit =
            prices[i] - minPrice;

            if(currentProfit > maxProfit) {
                maxProfit = currentProfit;
            }
        }

        return maxProfit;
    }
};