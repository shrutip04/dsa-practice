/*
==================================================

Problem: 268. Missing Number

LeetCode: Easy

Approach 1: Brute Force

Time: O(n²)

Space: O(1)

Idea:

- For every number from 0 to n,
  check whether it exists in nums.

- The number which does not exist
  is the missing number.

Algorithm:

1. Find n = nums.size().

2. Traverse numbers from 0 to n.

3. For every number, search for it
   inside the array.

4. If the number is not found,
   return that number.

5. If all numbers are found,
   return n.

--------------------------------------------------

Approach 2: Sorting

Time: O(n log n)

Space: O(1)

Idea:

- Sort the array.

- After sorting, every number should
  be equal to its index.

Expected:

index:  0 1 2 3
value:  0 1 2 3

- If nums[i] != i, then i is the
  missing number.

- If no mismatch is found, then n
  is the missing number.

Important Cases:

nums = [1,2,3]

Missing number = 0

nums = [0,1,2]

Missing number = n

Algorithm:

1. Find n = nums.size().

2. Sort nums.

3. If nums[0] != 0:

      return 0

4. Traverse the sorted array.

5. If:

      nums[i] != i

   return i.

6. If no mismatch is found,
   return n.

--------------------------------------------------

Approach 3: XOR (Optimal)

Time: O(n)

Space: O(1)

Idea:

- XOR has two important properties:

      x ^ x = 0

      x ^ 0 = x

- Every number from 0 to n should appear
  exactly once.

- XOR all indices and all array values.

- Every number that exists in both places
  cancels out.

- Only the missing number remains.

Example:

nums = [3,0,1]

Numbers:

0 1 2 3

XOR:

0 ^ 1 ^ 2 ^ 3

Array:

3 ^ 0 ^ 1

Common numbers cancel:

3 ^ 0 ^ 1 ^ 3 ^ 0 ^ 1 ^ 2

= 2

Therefore:

Missing Number = 2

Algorithm:

1. Initialize:

      ans = nums.size()

2. Traverse the array.

3. XOR the current index with nums[i]:

      ans = ans ^ i ^ nums[i]

4. After the loop, ans contains
   the missing number.

Why It Works:

Every number from 0 to n appears
once in the complete range.

All numbers present in nums appear
twice in the XOR operation:

      number ^ number = 0

Therefore, only the missing number
remains.

==================================================

*/

// ---------- Approach 1 : Brute Force ----------

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();

        for(int i = 0; i <= n; i++) {
            bool found = false;

            for(int j = 0; j < n; j++) {
                if(nums[j] == i) {
                    found = true;
                    break;
                }
            }

            if(!found)
                return i;
        }

        return -1;
    }
};

// ---------- Approach 2 : Sorting ----------

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        if(nums[0] != 0)
            return 0;

        for(int i = 0; i < n; i++) {
            if(nums[i] != i)
                return i;
        }

        return n;
    }
};

// ---------- Approach 3 : XOR (Optimal) ----------

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int ans = n;

        for(int i = 0; i < n; i++) {
            ans = ans ^ i ^ nums[i];
        }

        return ans;
    }
};