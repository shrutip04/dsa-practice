/*
==================================================
Problem: 238. Product of Array Except Self
LeetCode: Medium

Approach 1: Brute Force
Time: O(n²)
Space: O(1) (excluding output array)

Approach 2: Prefix Product + Suffix Product
Time: O(n)
Space: O(n)

Approach 3: Prefix Product + Running Suffix (Optimal)
Time: O(n)
Space: O(1) (excluding output array)

Learning:
- Division is NOT allowed, so we cannot simply
  calculate the total product and divide by nums[i].
- For each index i, we need:
  
      Product of all elements except nums[i]

- Observe that:

      answer[i]
      =
      (Product of elements to the left of i)
      ×
      (Product of elements to the right of i)

- Prefix array stores products of all elements
  before the current index.
- Suffix array stores products of all elements
  after the current index.
- Multiplying prefix[i] and suffix[i] gives
  the required answer for index i.
- The optimal solution avoids the suffix array
  by maintaining a running suffix product while
  traversing from right to left.
- This is a classic Prefix/Suffix Product pattern.

Example:

nums = [1, 2, 3, 4]

Step 1: Build Prefix Product Array

prefix[0] = 1

prefix[1] = 1
prefix[2] = 1 × 2 = 2
prefix[3] = 1 × 2 × 3 = 6

prefix = [1, 1, 2, 6]

--------------------------------------------------

Step 2: Build Suffix Product Array

suffix[3] = 1

suffix[2] = 4
suffix[1] = 3 × 4 = 12
suffix[0] = 2 × 3 × 4 = 24

suffix = [24, 12, 4, 1]

--------------------------------------------------

Step 3: Calculate Answer

answer[i] = prefix[i] × suffix[i]

answer[0] = 1 × 24 = 24
answer[1] = 1 × 12 = 12
answer[2] = 2 × 4  = 8
answer[3] = 6 × 1  = 6

Output:

[24, 12, 8, 6]

Pattern:
- Arrays
- Prefix Product
- Suffix Product
==================================================
*/


// ---------- Approach 1 : Brute Force ----------

class Solution1 {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int n = nums.size();
        vector<int> ans(n);

        for(int i = 0; i < n; i++) {

            int product = 1;

            for(int j = 0; j < n; j++) {

                if(i != j) {
                    product *= nums[j];
                }
            }

            ans[i] = product;
        }

        return ans;
    }
};


// ---------- Approach 2 : Prefix + Suffix Arrays ----------

class Solution2 {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int n = nums.size();

        vector<int> prefix(n, 1);
        vector<int> suffix(n, 1);
        vector<int> ans(n);

        for(int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] * nums[i - 1];
        }

        for(int i = n - 2; i >= 0; i--) {
            suffix[i] = suffix[i + 1] * nums[i + 1];
        }

        for(int i = 0; i < n; i++) {
            ans[i] = prefix[i] * suffix[i];
        }

        return ans;
    }
};


// ---------- Approach 3 : Optimal (O(1) Extra Space) ----------

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int n = nums.size();

        vector<int> ans(n, 1);

        // Store Prefix Products

        for(int i = 1; i < n; i++) {
            ans[i] = ans[i - 1] * nums[i - 1];
        }

        // Multiply by Suffix Products

        int suffix = 1;

        for(int i = n - 1; i >= 0; i--) {

            ans[i] *= suffix;
            suffix *= nums[i];
        }

        return ans;
    }
};