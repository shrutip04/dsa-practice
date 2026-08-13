/*
==================================================
Problem: 66. Plus One
LeetCode: Easy

Approach 1: Extra Array
Time: O(n)
Space: O(n)

Idea:
- Create a separate array ans as a copy of digits.
- Start from the last digit because addition begins
  from the least significant digit.
- If the current digit is less than 9:
      Increase it by 1 and return.
- If the current digit is 9:
      Change it to 0 and continue to the left.
- If all digits are 9, insert 1 at the beginning.

Example:
digits = [1,2,9]

Start from right:
9 → 0
2 → 3

Result:
[1,3,0]

--------------------------------------------------

Approach 2: In-Place (Optimal)
Time: O(n)
Space: O(1)

Idea:
- No extra array is required.
- Modify digits directly.
- Start from the last digit.
- If digit < 9:
      Increment it and return.
- If digit == 9:
      Set it to 0 and continue left.
- If all digits are 9:
      Insert 1 at the beginning.

Example:
digits = [1,2,9]

9 → 0
2 → 3

Result:
[1,3,0]

Special Case:
digits = [9,9,9]

9 → 0
9 → 0
9 → 0

Result becomes:
[0,0,0]

Add 1 at beginning:
[1,0,0,0]

Why It Works:
- Adding 1 only affects the suffix of 9s.
- Any digit less than 9 can simply be increased by 1.
- Once such a digit is found, there is no further carry.
- If every digit is 9, an extra digit 1 is required.

--------------------------------------------------

Key Pattern:

Start from RIGHT → LEFT

If digit < 9:
    digit++
    return

If digit == 9:
    digit = 0
    continue

If loop finishes:
    add 1 at beginning

==================================================
*/

// ---------- Approach 1 : Extra Array ----------

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {

        int n = digits.size();

        vector<int> ans = digits;

        for(int i = n - 1; i >= 0; i--) {

            if(digits[i] < 9) {

                ans[i] = digits[i] + 1;

                return ans;
            }

            if(digits[i] == 9) {

                ans[i] = 0;
            }
        }

        // All digits were 9
        ans.insert(ans.begin(), 1);

        return ans;
    }
};


// ---------- Approach 2 : In-Place / Optimal ----------

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {

        int n = digits.size();

        for(int i = n - 1; i >= 0; i--) {

            if(digits[i] < 9) {

                digits[i]++;

                return digits;
            }

            digits[i] = 0;
        }

        // All digits were 9
        digits.insert(digits.begin(), 1);

        return digits;
    }
};