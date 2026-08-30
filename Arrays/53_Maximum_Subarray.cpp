/*
==================================================

Problem: 53. Maximum Subarray

LeetCode: Medium

==================================================


==================================================

Approach 1: Brute Force

Time: O(n^2)

Space: O(1)

Idea:

- Consider every possible starting index.
- Extend the subarray from that index.
- Keep calculating the running sum.
- Track the maximum sum found so far.

Algorithm:

1. Initialize maxSum = INT_MIN.
2. Choose every index i as the starting point.
3. Set currentSum = 0.
4. For every j from i to n - 1:
   - Add nums[j] to currentSum.
   - Update maxSum.
5. Return maxSum.

Code:

*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int maxSum = INT_MIN;
        int n = nums.size();

        for (int i = 0; i < n; i++) {

            int currentSum = 0;

            for (int j = i; j < n; j++) {

                currentSum += nums[j];

                maxSum = max(maxSum, currentSum);
            }
        }

        return maxSum;
    }
};


/*
==================================================

Approach 2: Dynamic Programming

Time: O(n)

Space: O(n)

Idea:

- At every index i, calculate the maximum subarray
  sum that ends exactly at index i.

Let:

    dp[i] = maximum sum of a subarray ending at i

At every element, we have two choices:

1. Start a new subarray from nums[i].
2. Extend the previous subarray.

Therefore:

    dp[i] = max(nums[i], dp[i - 1] + nums[i])

The final answer is the maximum value in dp.

Algorithm:

1. Create a dp array.
2. Set:

       dp[0] = nums[0]

3. For every i from 1 to n - 1:

       dp[i] = max(nums[i],
                   dp[i - 1] + nums[i])

4. Track the maximum dp value.
5. Return the maximum.

Code:

*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int n = nums.size();

        vector<int> dp(n);

        dp[0] = nums[0];

        int maxSum = dp[0];

        for (int i = 1; i < n; i++) {

            dp[i] = max(nums[i],
                        dp[i - 1] + nums[i]);

            maxSum = max(maxSum, dp[i]);
        }

        return maxSum;
    }
};


/*
==================================================

Approach 3: Kadane's Algorithm

Time: O(n)

Space: O(1)

Idea:

- Kadane's Algorithm is the optimized version of the
  Dynamic Programming approach.
- We don't need to store the entire dp array.
- We only need the previous maximum subarray sum.

At every element:

    currentSum = maximum sum of a subarray
                 ending at the current position

We have two choices:

1. Start a new subarray:

       nums[i]

2. Continue the previous subarray:

       currentSum + nums[i]

Therefore:

       currentSum = max(nums[i],
                        currentSum + nums[i])

Then update the overall maximum:

       maxSum = max(maxSum, currentSum)

Algorithm:

1. Initialize currentSum = nums[0].
2. Initialize maxSum = nums[0].
3. Traverse the array from index 1.
4. At every index:

       currentSum = max(nums[i],
                        currentSum + nums[i])

5. Update:

       maxSum = max(maxSum, currentSum)

6. Return maxSum.

Code:

*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int currentSum = nums[0];
        int maxSum = nums[0];

        for (int i = 1; i < nums.size(); i++) {

            currentSum = max(nums[i],
                             currentSum + nums[i]);

            maxSum = max(maxSum, currentSum);
        }

        return maxSum;
    }
};


/*
==================================================

DRY RUN:

nums = [-2,1,-3,4,-1,2,1,-5,4]

Initially:

    currentSum = -2
    maxSum = -2


i = 1, nums[i] = 1

    currentSum = max(1, -2 + 1)
               = max(1, -1)
               = 1

    maxSum = max(-2, 1)
           = 1


i = 2, nums[i] = -3

    currentSum = max(-3, 1 + (-3))
               = max(-3, -2)
               = -2

    maxSum = 1


i = 3, nums[i] = 4

    currentSum = max(4, -2 + 4)
               = max(4, 2)
               = 4

    maxSum = 4


i = 4, nums[i] = -1

    currentSum = max(-1, 4 - 1)
               = 3

    maxSum = 4


i = 5, nums[i] = 2

    currentSum = max(2, 3 + 2)
               = 5

    maxSum = 5


i = 6, nums[i] = 1

    currentSum = max(1, 5 + 1)
               = 6

    maxSum = 6


i = 7, nums[i] = -5

    currentSum = max(-5, 6 - 5)
               = 1

    maxSum = 6


i = 8, nums[i] = 4

    currentSum = max(4, 1 + 4)
               = 5

    maxSum = 6


Final Answer:

    6

Maximum Subarray:

    [4, -1, 2, 1]


==================================================

WHY DOES KADANE'S ALGORITHM WORK?

At every position, ask:

"Should I continue the previous subarray,
 or should I start a new subarray here?"

If:

    currentSum + nums[i] < nums[i]

then the previous subarray is hurting our sum.

So we discard it and start fresh:

    currentSum = nums[i]

Otherwise, we continue the existing subarray.

Therefore:

    currentSum = max(nums[i],
                     currentSum + nums[i])


==================================================

IMPORTANT EDGE CASE:

All elements can be negative.

Example:

    nums = [-5,-2,-8,-1]

The answer is:

    -1

NOT 0.

Therefore, DO NOT initialize:

    currentSum = 0
    maxSum = 0

because that would incorrectly return 0.

Instead initialize using the first element:

    currentSum = nums[0]
    maxSum = nums[0]


==================================================

COMPARISON

Approach 1: Brute Force

- Very easy to understand
- Checks every possible subarray
- O(n^2) time
- O(1) space
- Too slow for large inputs

Approach 2: Dynamic Programming

- Uses the idea of maximum subarray ending at i
- O(n) time
- O(n) space
- Easy to understand
- Stores unnecessary information in the dp array

Approach 3: Kadane's Algorithm

- Optimized Dynamic Programming
- O(n) time
- O(1) space
- Only stores the current and overall maximum
- Most efficient approach


BEST APPROACH:

Approach 3: Kadane's Algorithm

Why?

- O(n) time
- O(1) extra space
- Simple implementation
- Handles negative numbers correctly
- Very common interview pattern
- Can also be extended to find the actual
  maximum subarray, not just its sum


==================================================

KEY PATTERN:

KADANE'S ALGORITHM

Whenever you see:

"Find the maximum sum of a contiguous subarray"

Think:

    Kadane's Algorithm

Core idea:

    currentSum =
        max(current element,
            current subarray + current element)

Then:

    maxSum =
        max(maxSum, currentSum)


==================================================

MEMORY TRICK:

At every element, ask:

    "Should I EXTEND or RESTART?"

EXTEND:

    currentSum + nums[i]

RESTART:

    nums[i]

Choose the larger:

    currentSum = max(nums[i],
                     currentSum + nums[i])


==================================================

*/