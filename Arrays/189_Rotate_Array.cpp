/*
==================================================
Problem: 189. Rotate Array
LeetCode: Medium

Approach 1: Brute Force (Rotate One Step k Times)
Time: O(n * k)
Space: O(1)

Idea:
- Perform one right rotation repeatedly k times.
- For each rotation:
    1. Store the last element.
    2. Shift all elements one position right.
    3. Place stored element at index 0.

Algorithm:
1. Compute k %= n.
2. Repeat k times:
    a. Store nums[n-1].
    b. Shift elements right.
    c. Place stored value at nums[0].

--------------------------------------------------

Approach 2: Extra Array (Better)
Time: O(n)
Space: O(n)

Idea:
- Every element knows its final position.
- Place each element directly into its rotated index.

Formula:
newIndex = (i + k) % n

Algorithm:
1. Compute k %= n.
2. Create temp array of size n.
3. For every index i:
      temp[(i+k)%n] = nums[i]
4. Copy temp back to nums.

--------------------------------------------------

Approach 3: Reverse Technique (Optimal)
Time: O(n)
Space: O(1)

Idea:
- Let:
      A = first n-k elements
      B = last k elements

Original:
[A B]

Required:
[B A]

Reverse Trick:
1. Reverse whole array.
2. Reverse first k elements.
3. Reverse remaining n-k elements.

Algorithm:
1. Compute k %= n.
2. Reverse entire array.
3. Reverse first k elements.
4. Reverse remaining elements.

Why It Works:
1. [A B]
2. Reverse All
[reverse(B) reverse(A)]
3. Reverse Both Parts
[B A]
which is the rotated array.

==================================================
*/

// ---------- Approach 1 : Brute Force ----------

class Solution {
public:
    void rotate(vector<int>& nums, int k) {

        int n = nums.size();

        k %= n;

        for(int step = 0; step < k; step++) {

            int last = nums[n - 1];

            for(int i = n - 1; i > 0; i--) {
                nums[i] = nums[i - 1];
            }

            nums[0] = last;
        }
    }
};


// ---------- Approach 2 : Extra Array ----------
class Solution {
public:
    void rotate(vector<int>& nums, int k) {

        int n = nums.size();

        k %= n;

        vector<int> temp(n);

        for(int i = 0; i < n; i++) {
            temp[(i + k) % n] = nums[i];
        }

        nums = temp;
    }
};


// ---------- Approach 3 : Reverse Technique ----------
class Solution {
public:
    void rotate(vector<int>& nums, int k) {

        int n = nums.size();

        if(n <= 1) return;

        k %= n;

        reverse(nums.begin(), nums.end());

        reverse(nums.begin(), nums.begin() + k);

        reverse(nums.begin() + k, nums.end());
    }
};
