/*
==================================================

Problem: 918. Maximum Sum Circular Subarray
LeetCode: Medium

Approach 1: Brute Force
Time: O(n^2)
Space: O(1)

Approach 2: Kadane's Algorithm
Time: O(n)
Space: O(1)

Learning:
- The array is circular, so a maximum subarray can
  either be:
  1. Non-circular
  2. Circular / wrapping around the end

- Brute Force can check every possible circular
  subarray.

- Kadane's Algorithm efficiently finds the maximum
  non-circular subarray.

- For a circular maximum subarray:
  Circular Sum = Total Sum - Minimum Subarray Sum

- Minimum Subarray Sum can be found using a modified
  version of Kadane's Algorithm.

- Therefore:
  Answer = max(Maximum Subarray Sum,
               Total Sum - Minimum Subarray Sum)

- If all elements are negative, the circular
  calculation gives 0, representing an empty
  subarray.

- Since the problem requires a non-empty subarray,
  return the normal maximum when all elements
  are negative.

==================================================
*/


// ---------- Approach 1 : Brute Force ----------

class Solution1 {
public:
    int maxSubarraySumCircular(vector<int>& nums) {

        int n = nums.size();
        int ans = INT_MIN;

        for(int start = 0; start < n; start++) {

            int sum = 0;

            for(int len = 0; len < n; len++) {

                int index = (start + len) % n;

                sum = sum + nums[index];

                ans = max(ans, sum);
            }
        }

        return ans;
    }
};


// ---------- Approach 2 : Kadane's Algorithm (Optimal) ----------

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {

        int currmax = 0;
        int globalmax = INT_MIN;

        int currmin = 0;
        int globalmin = INT_MAX;

        int sum = 0;

        for(int i = 0; i < nums.size(); i++) {

            sum = nums[i] + sum;

            // Maximum Kadane
            currmax = nums[i] + currmax;

            if(currmax > globalmax)
                globalmax = currmax;

            if(currmax < 0)
                currmax = 0;


            // Minimum Kadane
            currmin = nums[i] + currmin;

            if(currmin < globalmin)
                globalmin = currmin;

            if(currmin > 0)
                currmin = 0;
        }

        // All elements are negative
        if(globalmax < 0)
            return globalmax;

        // Circular maximum
        int circular = sum - globalmin;

        return max(globalmax, circular);
    }
};
