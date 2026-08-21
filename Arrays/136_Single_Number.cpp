/*
==================================================
Problem: 136. Single Number
LeetCode: Easy

Approach 1: Brute Force
Time: O(n^2)
Space: O(1)

Idea:
- For every element, count how many times it appears.
- The element whose frequency is 1 is the single number.

Algorithm:
1. Traverse every element nums[i].
2. Count its occurrences using another loop.
3. If count == 1:
      Return nums[i].
4. Return -1 if no single element is found.

--------------------------------------------------

Approach 2: Hash Map
Time: O(n) Average
Space: O(n)

Idea:
- Store the frequency of every element in a hash map.
- The element with frequency 1 is the answer.

Algorithm:
1. Create a hash map:
      element → frequency
2. Traverse the array.
3. Increment frequency of nums[i].
4. Traverse the hash map.
5. Return the element whose frequency == 1.

--------------------------------------------------

Approach 3: Sorting
Time: O(n log n)
Space: O(1) Auxiliary

Idea:
- Sort the array.
- Equal elements will become adjacent.
- Check elements in pairs.
- The element that does not have an equal adjacent
  element is the single number.

Example:

nums = [4,1,2,1,2]

After sorting:

[1,1,2,2,4]
          ↑
       single

Algorithm:
1. Sort nums.
2. Traverse the array in pairs.
3. If nums[i] != nums[i+1]:
      Return nums[i].
4. If all pairs match, return the last element.

--------------------------------------------------

Approach 4: XOR (Optimal)
Time: O(n)
Space: O(1)

Idea:
- XOR has special properties that make it perfect for
  this problem.

Important XOR Properties:

1. x ^ x = 0

   Example:
   5 ^ 5 = 0

2. x ^ 0 = x

   Example:
   5 ^ 0 = 5

3. XOR is commutative:

   a ^ b = b ^ a

4. XOR is associative:

   (a ^ b) ^ c = a ^ (b ^ c)

Therefore, all elements that appear twice cancel each
other out, and only the single element remains.

Example:

nums = [4,1,2,1,2]

XOR all elements:

4 ^ 1 ^ 2 ^ 1 ^ 2

Rearrange:

4 ^ (1 ^ 1) ^ (2 ^ 2)

Since:

1 ^ 1 = 0
2 ^ 2 = 0

Therefore:

4 ^ 0 ^ 0 = 4

Answer = 4

--------------------------------------------------

Why XOR Works:

Every duplicate appears exactly twice.

Therefore:

a ^ a = 0

All duplicate pairs cancel each other.

The remaining element is:

single ^ 0 = single

So the final XOR result is the single number.

--------------------------------------------------

Algorithm:
1. Initialize:
      result = 0

2. Traverse every element x in nums:
      result = result ^ x

3. Return result.

--------------------------------------------------

Important:
- The array is guaranteed to contain exactly one element
  that appears once.
- Every other element appears exactly twice.
- Therefore, no extra verification is required.
- XOR works with negative integers as well because it
  operates on the binary representation.

--------------------------------------------------

Example:

nums = [2,2,1]

result = 0

0 ^ 2 = 2
2 ^ 2 = 0
0 ^ 1 = 1

Answer = 1

--------------------------------------------------

Complexity:

Time:
O(n)

We traverse the array once.

Space:
O(1)

Only one variable is used.

--------------------------------------------------

Pattern:

Bit Manipulation
+
XOR

Whenever you see:

"Every element appears twice except one"

Think:

      XOR

Because:

      x ^ x = 0
      x ^ 0 = x

So all duplicate elements cancel out and the
single element remains.

==================================================
*/


// ---------- Approach 1 : Brute Force ----------

class Solution {
public:
    int singleNumber(vector<int>& nums) {

        int n = nums.size();

        for(int i = 0; i < n; i++) {

            int count = 0;

            for(int j = 0; j < n; j++) {

                if(nums[i] == nums[j])
                    count++;
            }

            if(count == 1)
                return nums[i];
        }

        return -1;
    }
};


// ---------- Approach 2 : Hash Map ----------

class Solution {
public:
    int singleNumber(vector<int>& nums) {

        unordered_map<int, int> freq;

        for(int x : nums) {
            freq[x]++;
        }

        for(auto it : freq) {

            if(it.second == 1)
                return it.first;
        }

        return -1;
    }
};


// ---------- Approach 3 : Sorting ----------

class Solution {
public:
    int singleNumber(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        int n = nums.size();

        for(int i = 0; i < n - 1; i += 2) {

            if(nums[i] != nums[i + 1])
                return nums[i];
        }

        return nums[n - 1];
    }
};


// ---------- Approach 4 : XOR (Optimal) ----------

class Solution {
public:
    int singleNumber(vector<int>& nums) {

        int result = 0;

        for(int x : nums) {
            result = result ^ x;
        }

        return result;
    }
};