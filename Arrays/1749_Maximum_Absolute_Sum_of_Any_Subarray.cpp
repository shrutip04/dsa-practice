/*
==================================================

Problem: 1749. Maximum Absolute Sum of Any Subarray
LeetCode: Medium

Approach 1: Brute Force
Time: O(n^2)
Space: O(1)

Algorithm:
1. Start from every possible starting index.
2. Keep calculating the subarray sum by extending
   the ending index.
3. For every subarray, calculate abs(sum).
4. Keep track of the maximum absolute sum.
5. Return the maximum value found.

--------------------------------------------------

Approach 2: Kadane's Algorithm (Optimal)
Time: O(n)
Space: O(1)

Algorithm:
1. Since the sum of a subarray can be positive or
   negative, find both:
   - Maximum subarray sum.
   - Minimum subarray sum.
2. Use normal Kadane's Algorithm to find the
   maximum subarray sum.
3. Use modified Kadane's Algorithm to find the
   minimum subarray sum.
4. For Maximum Kadane:
   - Add current element to currmax.
   - Update globalmax.
   - If currmax becomes negative, reset it to 0.
5. For Minimum Kadane:
   - Add current element to currmin.
   - Update globalmin.
   - If currmin becomes positive, reset it to 0.
6. Since the problem asks for absolute sum:

   Answer = max(globalmax, abs(globalmin))
7. This problem is NOT circular, so there is no
   totalSum - globalMin calculation.

==================================================
*/

// ---------- Approach 1 : Brute Force ----------

class Solution1 {
public:
    int maxAbsoluteSum(vector<int>& nums) {

        int n = nums.size();
        int ans = 0;

        for(int i = 0; i < n; i++) {

            int sum = 0;

            for(int j = i; j < n; j++) {

                sum = sum + nums[j];

                ans = max(ans, abs(sum));
            }
        }

        return ans;
    }
};


// ---------- Approach 2 : Kadane's Algorithm (Optimal) ----------

class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {

        int currmax = 0;
        int currmin = 0;

        int globalmax = INT_MIN;
        int globalmin = INT_MAX;

        for(int i = 0; i < nums.size(); i++) {

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

        return max(globalmax, abs(globalmin));
    }
};
