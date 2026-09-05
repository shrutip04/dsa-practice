/*
==================================================

Problem: 643. Maximum Average Subarray I
LeetCode: Medium
--------------------------------------------------

Approach 1: Brute Force
Time: O(n × k)
Space: O(1)

-Idea:
-Try every possible starting index of a subarray
of length k.
-For every starting index, calculate the sum of the
next k elements.
-Calculate the average and keep track of the maximum
average.
-Each window takes O(k) time to calculate its sum.
-There can be O(n) possible windows.
-Therefore total time is O(n × k).

ALGORITHM:
1.Initialize maxAverage to a very small value.
2.Traverse every possible starting index i.
3.For each i, calculate the sum of the k elements:
    nums[i], nums[i+1], ..., nums[i+k-1]
4.Calculate:
    average = sum / k
5.Update maxAverage.
6.Return maxAverage.

--------------------------------------------------

Approach 2: Prefix Sum (Better)
Time: O(n)
Space: O(n)

-Idea:
-Create a prefix sum array.
-prefix[i] stores the sum of the first i elements.
-Therefore:
    prefix[i] = nums[0] + nums[1] + ... + nums[i-1]
-The sum of any subarray from index i to j is:
    prefix[j + 1] - prefix[i]
-For every subarray of length k:
    sum = prefix[i + k] - prefix[i]
-Then calculate the average:
    average = sum / k
-Store the maximum average.
-This avoids recalculating the sum of every window.

ALGORITHM:
1.Create a prefix array of size n + 1.
2.Set:
    prefix[0] = 0
3.Build the prefix sum:
    prefix[i + 1] =
    prefix[i] + nums[i]
4.Traverse all possible windows of length k.
5.For each starting index i:
    sum = prefix[i + k] - prefix[i]
6.Calculate:
    average = (double)sum / k
7.Update maxAverage.
8.Return maxAverage.

--------------------------------------------------

Approach 3: Sliding Window (Optimal)
Time: O(n)
Space: O(1)

-Idea:
-Since every subarray has exactly k elements, we can
maintain a window of exactly k elements.
-First calculate the sum of the first k elements.
-Then slide the window one position at a time.
-When the window moves:
    Remove the element leaving the window.
    Add the new element entering the window.
-Therefore:
    new sum =
    old sum - nums[i-k] + nums[i]
-Store the maximum window sum.
-At the end:
    maximum average = maximum sum / k
-There is no need to calculate the average for every
window. Since k is fixed, the window with the largest
sum will also have the largest average.

ALGORITHM:
1.Calculate the sum of the first k elements.
2.Store this sum in maxSum.
3.Start from index k.
4.For every new element:
    a.Remove the element leaving the window:
        sum = sum - nums[i-k]
    b.Add the new element:
        sum = sum + nums[i]
    c.Update maxSum.
5.Return:
    (double)maxSum / k

EXAMPLE:

nums = [1,12,-5,-6,50,3]
k = 4

First window:
[1,12,-5,-6]
sum = 2

Next window:
[12,-5,-6,50]
Remove 1
Add 50
sum = 2 - 1 + 50
    = 51

Next window:
[-5,-6,50,3]
Remove 12
Add 3
sum = 51 - 12 + 3
    = 42
Maximum sum = 51
Maximum average:  51 / 4 = 12.75

IMPORTANT:
Because every window has exactly k elements:
Maximum Sum = Maximum Average
So we can compare sums instead of averages.
==================================================
*/

// ---------- Approach 1 : Brute Force ----------

class Solution1 {
public:
    double findMaxAverage(vector<int>& nums, int k) {

        double maxAverage = -1e9;

        int n = nums.size();

        for(int i = 0; i <= n - k; i++) {

            int sum = 0;

            for(int j = i; j < i + k; j++) {
                sum += nums[j];
            }

            double average =
                (double)sum / k;

            maxAverage =
                max(maxAverage, average);
        }

        return maxAverage;
    }
};

// ---------- Approach 2 : Prefix Sum (Better) ----------

class Solution2 {
public:
    double findMaxAverage(vector<int>& nums, int k) {

        int n = nums.size();

        vector<int> prefix(n + 1, 0);

        // Build prefix sum
        for(int i = 0; i < n; i++) {

            prefix[i + 1] =
                prefix[i] + nums[i];
        }

        double maxAverage = -1e9;

        // Check every window of size k
        for(int i = 0; i <= n - k; i++) {

            int sum =
                prefix[i + k] - prefix[i];

            double average =
                (double)sum / k;

            maxAverage =
                max(maxAverage, average);
        }

        return maxAverage;
    }
};

// ---------- Approach 3 : Sliding Window (Optimal) ----------

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {

        int sum = 0;

        // Sum of first k elements
        for(int i = 0; i < k; i++) {
            sum += nums[i];
        }

        int maxSum = sum;

        // Slide the window
        for(int i = k; i < nums.size(); i++) {

            sum =
                sum - nums[i - k] + nums[i];

            maxSum =
                max(maxSum, sum);
        }

        return (double)maxSum / k;
    }
};
