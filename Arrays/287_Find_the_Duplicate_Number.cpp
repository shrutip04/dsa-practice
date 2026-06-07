/*
==================================================
Problem: 287. Find the Duplicate Number
LeetCode: Medium

Approach 1: Binary Search on Answer
Time: O(n log n)
Space: O(1)

Approach 2: Floyd's Cycle Detection (Optimal)
Time: O(n)
Space: O(1)

Learning:
- Array contains n+1 numbers in range [1, n].
- Pigeonhole Principle guarantees a duplicate.
- Binary Search is performed on the value range,
  not on array indices.
- Floyd's Tortoise and Hare treats the array as
  a linked list and finds the cycle entrance,
  which is the duplicate number.
==================================================
*/

// ---------- Approach 1 : Binary Search on Answer ----------

class Solution1 {
public:
    int findDuplicate(vector<int>& nums) {
        int low = 1;
        int high = nums.size() - 1;

        while(low < high) {
            int mid = low + (high - low) / 2;

            int count = 0;

            for(int num : nums) {
                if(num <= mid)
                    count++;
            }

            if(count > mid)
                high = mid;
            else
                low = mid + 1;
        }

        return low;
    }
};

// ---------- Approach 2 : Floyd's Cycle Detection (Optimal) ----------

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];

        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while(slow != fast);

        slow = nums[0];

        while(slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};