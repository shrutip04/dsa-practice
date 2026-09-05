/*
==================================================

Problem: 303. Range Sum Query - Immutable

LeetCode: Easy

Approach 1: Brute Force

Time: O(n) per query

Space: O(1)

-For every query, traverse from left to right.
-Add each element to a running sum.
-Return the sum after reaching right.

ALGORITHM:

1.Initialize sum to 0.

2.Traverse from index left to right:
    a.Add nums[i] to sum.

3.Return sum.

Problem:
-There can be up to 10^4 calls to sumRange().
-Recalculating the sum for every query can be expensive.

Approach 2: Prefix Sum (Optimal)

-Precompute the cumulative sum of the array once.
-Store the prefix sums in a separate vector.
-Use the prefix sums to answer every query in O(1).

For example:

nums   = [-2, 0, 3, -5, 2, -1]

prefix = [0, -2, -2, 1, -4, -2, -3]

The extra 0 at the beginning makes the range-sum
calculation easier.

PREFIX FORMULA:

prefix[i + 1] = prefix[i] + nums[i]

For a query from left to right:

sumRange = prefix[right + 1] - prefix[left]

Why?

prefix[right + 1] contains the sum from index 0 to right.

prefix[left] contains the sum from index 0 to left - 1.

Subtracting them leaves only the elements from
left to right.

ALGORITHM:

1.Create a prefix vector of size nums.size() + 1.

2.Initialize the prefix vector with 0.

3.Traverse the nums array:
    a.Calculate prefix[i + 1] = prefix[i] + nums[i].

4.For every query:
    a.Calculate prefix[right + 1] - prefix[left].
    b.Return the result.

Complexity:

Preprocessing:
Time: O(n)
Space: O(n)

Each sumRange query:
Time: O(1)
Space: O(1)

==================================================
*/

// ---------- Approach 1 : Brute Force ----------

class NumArray1 {

public:

    vector<int> nums;

    NumArray1(vector<int>& nums) {
        this->nums = nums;
    }

    int sumRange(int left, int right) {

        int sum = 0;

        for(int i = left; i <= right; i++) {

            sum += nums[i];
        }

        return sum;
    }
};


// ---------- Approach 2 : Prefix Sum (Optimal) ----------

class NumArray {

public:

    vector<int> prefix;

    NumArray(vector<int>& nums) {

        prefix.resize(nums.size() + 1);

        for(int i = 0; i < nums.size(); i++) {

            prefix[i + 1] =
                prefix[i] + nums[i];
        }
    }

    int sumRange(int left, int right) {

        return prefix[right + 1] - prefix[left];
    }
};
