/*
==================================================

Problem: 283. Move Zeroes
LeetCode: Easy

Approach 1: Brute Force
Time: O(n)
Space: O(n)

Approach 2: Two Pointers (Optimal)
Time: O(n)
Space: O(1)

Algorithm - Approach 1: Brute Force
1. Create a separate array.
2. Traverse nums and add all non-zero elements
   to the new array.
3. Add zeroes at the end.
4. Copy the result back to nums.

--------------------------------------------------

Algorithm - Approach 2: Two Pointers (Optimal)
1. Use a pointer `j` to represent the position
   where the next non-zero element should be placed.
2. Traverse the array using pointer `i`.
3. If nums[i] is non-zero:
   - Swap nums[i] with nums[j].
   - Increment j.
4. This places all non-zero elements at the front
   while maintaining their relative order.
5. All zeroes automatically move towards the end.
6. No extra array is required.

==================================================
*/

// ---------- Approach 1 : Brute Force ----------

class Solution1 {
public:
    void moveZeroes(vector<int>& nums) {

        vector<int> temp;

        for(int i = 0; i < nums.size(); i++) {

            if(nums[i] != 0)
                temp.push_back(nums[i]);
        }

        while(temp.size() < nums.size()) {
            temp.push_back(0);
        }

        nums = temp;
    }
};


// ---------- Approach 2 : Two Pointers (Optimal) ----------

class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        int j = 0;

        for(int i = 0; i < nums.size(); i++) {

            if(nums[i] != 0) {

                swap(nums[i], nums[j]);

                j++;
            }
        }
    }
};