/*
==================================================

Problem: 525. Contiguous Array
LeetCode: Medium

Approach: Prefix Sum + Hash Map
Time: O(n)
Space: O(n)

-Idea:
We need to find the longest contiguous subarray
containing an equal number of 0s and 1s.

-Convert every 0 into -1 and keep every 1 as +1.
-Then a subarray has an equal number of 0s and 1s
if and only if its sum is 0.
-Use prefix sum to find subarrays whose sum is 0.
-Key Observation:
If the same prefix sum occurs at two different
indices, the elements between those indices have
a sum of 0.

Therefore, they contain an equal number of 0s and 1s.

-Use a hash map to store:
prefix sum -> first index where it appeared
-Store only the FIRST occurrence of each prefix sum.
-This gives the longest possible subarray when the
same prefix sum appears again.

-Initialize:

mp[0] = -1

This handles subarrays that start from index 0.

ALGORITHM:

1.Initialize an unordered_map to store prefix sum
  and its first occurrence.
2.Store mp[0] = -1.
3.Initialize:
    sum = 0
    maxLength = 0
4.Traverse the array:
    a.If nums[i] == 0:
        decrease sum by 1.
    b.If nums[i] == 1:
        increase sum by 1.
    c.Check if the current prefix sum already
      exists in the map.
    d.If it exists:
        Calculate length = i - mp[sum].
        Update maxLength.
    e.If it does not exist:
        Store mp[sum] = i.
5.Return maxLength.

WHY DOES IT WORK?

Example:

nums = [0, 1, 0, 1]

After conversion:
[-1, +1, -1, +1]

Prefix sums:
[-1, 0, -1, 0]

The prefix sum -1 occurs more than once.
The prefix sum 0 also occurs more than once.
When the same prefix sum appears again,
the difference between the two prefix sums is 0.
Therefore, the elements between those indices
contain equal numbers of -1 and +1.

Since:
0 -> -1
1 -> +1
equal -1 and +1 means equal 0s and 1s.

==================================================
*/

// ---------- Approach : Prefix Sum + Hash Map ----------

class Solution {

public:

    int findMaxLength(vector<int>& nums) {

        unordered_map<int, int> mp;

        // Prefix sum 0 exists before the array starts
        mp[0] = -1;

        int sum = 0;
        int maxLength = 0;

        for(int i = 0; i < nums.size(); i++) {

            // Convert 0 -> -1 and 1 -> +1
            if(nums[i] == 0) {
                sum--;
            }
            else {
                sum++;
            }

            // Same prefix sum found
            if(mp.find(sum) != mp.end()) {

                int length = i - mp[sum];

                maxLength = max(maxLength, length);
            }

            // Store only the first occurrence
            else {

                mp[sum] = i;
            }
        }

        return maxLength;
    }
};
