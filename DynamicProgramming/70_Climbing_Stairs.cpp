/*
==================================================
Problem: 70. Climbing Stairs
LeetCode: Easy

Approach 1: Brute Force (Recursion)
Time: O(2^n)
Space: O(n)

Idea:
- To reach stair n, we can come from:
    1. Stair (n-1) by taking 1 step.
    2. Stair (n-2) by taking 2 steps.
- Recursively calculate both possibilities.
- This leads to overlapping subproblems.

Recurrence:
ways(n) = ways(n-1) + ways(n-2)

Base Cases:
ways(0) = 1
ways(1) = 1

Algorithm:
1. If n <= 1, return 1.
2. Recursively compute:
      ways(n-1) + ways(n-2)
3. Return the result.

--------------------------------------------------

Approach 2: Memoization (Top-Down DP)
Time: O(n)
Space: O(n)

Idea:
- Store answers of already solved states.
- Avoid repeated recursive calculations.
- Each state is computed only once.

DP State:
dp[i] = Number of ways to reach stair i

Recurrence:
dp[i] = dp[i-1] + dp[i-2]

Algorithm:
1. Create dp array initialized with -1.
2. Solve recursively.
3. If state already exists in dp, return it.
4. Store computed answer in dp.
5. Return dp[n].

--------------------------------------------------

Approach 3: Tabulation (Bottom-Up DP)
Time: O(n)
Space: O(n)

Idea:
- Build answers from smaller states.
- Start from base cases and move upward.

DP State:
dp[i] = Number of ways to reach stair i

Transition:
dp[i] = dp[i-1] + dp[i-2]

Algorithm:
1. Initialize:
      dp[0] = 1
      dp[1] = 1
2. Iterate from 2 to n.
3. Fill dp using recurrence.
4. Return dp[n].

--------------------------------------------------

Approach 4: Space Optimized DP (Optimal)
Time: O(n)
Space: O(1)

Idea:
- Current state depends only on previous two states.
- No need to store the entire DP array.

Recurrence:
curr = prev1 + prev2

Algorithm:
1. Initialize:
      prev2 = 1
      prev1 = 1
2. Iterate from 2 to n.
3. Compute current answer.
4. Shift previous values forward.
5. Return prev1.

Why It Works:
- Since dp[i] only depends on dp[i-1] and dp[i-2],
  keeping only the last two answers is sufficient.
- This reduces space complexity from O(n) to O(1).

==================================================
*/

// ---------- Approach 1 : Brute Force (Recursion) ----------

class Solution {
public:

    int solve(int n) {

        if(n <= 1)
            return 1;

        return solve(n - 1) + solve(n - 2);
    }

    int climbStairs(int n) {

        return solve(n);
    }
};



// ---------- Approach 2 : Memoization (Top-Down DP) ----------

class Solution {
public:

    int solve(int n, vector<int>& dp) {

        if(n <= 1)
            return 1;

        if(dp[n] != -1)
            return dp[n];

        dp[n] = solve(n - 1, dp) + solve(n - 2, dp);

        return dp[n];
    }

    int climbStairs(int n) {

        vector<int> dp(n + 1, -1);

        return solve(n, dp);
    }
};



// ---------- Approach 3 : Tabulation (Bottom-Up DP) ----------

class Solution {
public:

    int climbStairs(int n) {

        vector<int> dp(n + 1);

        dp[0] = 1;
        dp[1] = 1;

        for(int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n];
    }
};



// ---------- Approach 4 : Space Optimized DP (Optimal) ----------

class Solution {
public:

    int climbStairs(int n) {

        if(n <= 1)
            return 1;

        int prev2 = 1;
        int prev1 = 1;

        for(int i = 2; i <= n; i++) {

            int curr = prev1 + prev2;

            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};