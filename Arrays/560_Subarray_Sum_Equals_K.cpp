/*
==================================================

Problem: 560. Subarray Sum Equals K

LeetCode: Medium

==================================================


==================================================

Approach 1: Brute Force

Time: O(n^2)

Space: O(1)

Idea:

- Consider every possible starting index.
- Extend the subarray from that starting index.
- Keep calculating the running sum.
- Whenever the sum becomes equal to k, increment
  the answer.

Algorithm:

1. Initialize count = 0.
2. Choose every index i as the starting point.
3. Initialize sum = 0.
4. For every j from i to n-1:
   - Add nums[j] to sum.
   - If sum == k, increment count.
5. Return count.

Code:

*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        int count = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {

            int sum = 0;

            for (int j = i; j < n; j++) {

                sum += nums[j];

                if (sum == k) {
                    count++;
                }
            }
        }

        return count;
    }
};


/*
==================================================

Approach 2: Prefix Sum + Brute Force

Time: O(n^2)

Space: O(n)

Idea:

- Create a prefix sum array.
- prefix[i] stores the sum of elements from index 0
  to i-1.
- The sum of a subarray from i to j is:

      prefix[j + 1] - prefix[i]

- Check every possible pair of prefix sums.
- If their difference is k, we found a valid subarray.

Formula:

    subarray_sum = prefix[j] - prefix[i]

If:

    prefix[j] - prefix[i] == k

then:

    prefix[j] - k == prefix[i]

Algorithm:

1. Create prefix sum array.
2. Calculate prefix sums.
3. Check every pair (i, j).
4. If prefix[j] - prefix[i] == k, increment count.
5. Return count.

Code:

*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        int n = nums.size();
        int count = 0;

        vector<long long> prefix(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        for (int i = 0; i < n; i++) {

            for (int j = i + 1; j <= n; j++) {

                if (prefix[j] - prefix[i] == k) {
                    count++;
                }
            }
        }

        return count;
    }
};


/*
==================================================

Approach 3: Prefix Sum + Hash Map

Time: O(n) average

Space: O(n)

Idea:

- Instead of checking every previous prefix sum,
  store their frequencies in a hash map.

Suppose current prefix sum is:

    sum

For a subarray to have sum k:

    current_sum - previous_sum = k

Therefore:

    previous_sum = current_sum - k

So, for every current prefix sum, we simply check:

    sum - k

in the hash map.

If it exists, its frequency tells us how many
subarrays ending at the current position have sum k.

Important:

- Initialize map[0] = 1.
- This represents the empty prefix before the array starts.
- It allows us to correctly count subarrays beginning
  at index 0.

Algorithm:

1. Create an unordered_map to store:
       prefix_sum -> frequency

2. Initialize:
       prefixSum = 0
       count = 0

3. Put:
       map[0] = 1

4. Traverse the array.

5. Add nums[i] to prefixSum.

6. Calculate:
       required = prefixSum - k

7. If required exists in the map:
       count += map[required]

8. Store the current prefix sum:
       map[prefixSum]++

9. Return count.

Code:

*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        unordered_map<long long, int> mp;

        long long prefixSum = 0;
        int count = 0;

        // Empty prefix
        mp[0] = 1;

        for (int num : nums) {

            prefixSum += num;

            long long required = prefixSum - k;

            if (mp.find(required) != mp.end()) {
                count += mp[required];
            }

            mp[prefixSum]++;
        }

        return count;
    }
};


/*
==================================================

WHY DOES map[0] = 1 MATTER?

Consider:

nums = [1, 2, 3]
k = 3

Initially:

    mp[0] = 1

After reading 1:

    prefixSum = 1

    required = 1 - 3 = -2

    -2 does not exist.

Store:

    mp[1]++

After reading 2:

    prefixSum = 3

    required = 3 - 3 = 0

    mp[0] = 1

Therefore:

    count += 1

The subarray is:

    [1, 2]

Without mp[0] = 1, we would miss subarrays
whose sum starts from index 0.


==================================================

DRY RUN:

nums = [1, 1, 1]
k = 2

Initially:

    prefixSum = 0
    count = 0
    mp[0] = 1


i = 0:

    prefixSum = 1
    required = 1 - 2 = -1

    -1 not found

    mp[1] = 1


i = 1:

    prefixSum = 2
    required = 2 - 2 = 0

    mp[0] = 1

    count = 1

    mp[2] = 1


i = 2:

    prefixSum = 3
    required = 3 - 2 = 1

    mp[1] = 1

    count = 2

    mp[3] = 1


Final answer:

    count = 2


The two subarrays are:

    [1, 1]
       ↑ ↑

    [1, 1]
         ↑ ↑


==================================================

WHY HASH MAP MAKES IT O(n)

Without a hash map:

For every current prefix sum, we would need to
search through all previous prefix sums.

That gives:

    O(n^2)

With a hash map:

    prefixSum - k

can be searched in O(1) average time.

Therefore:

    n elements × O(1) lookup

    = O(n)


==================================================

COMPARISON

Approach 1: Brute Force

- Very simple
- Easy to understand
- No extra space
- O(n^2) time
- Too slow for large inputs

Approach 2: Prefix Sum + Brute Force

- Introduces the prefix sum concept
- Avoids repeatedly calculating subarray sums
- Still requires checking pairs
- O(n^2) time
- O(n) space

Approach 3: Prefix Sum + Hash Map

- Uses prefix sum efficiently
- Hash map stores prefix sum frequencies
- Avoids checking every pair
- O(n) average time
- O(n) space
- Best approach for this problem


BEST APPROACH:

Approach 3: Prefix Sum + Hash Map

Why?

- O(n) average time
- Handles negative numbers
- Does not require a sorted array
- Does not use a sliding window
- Efficiently counts all valid subarrays
- Important interview pattern


==================================================

KEY PATTERN:

PREFIX SUM + HASH MAP

The most important equation:

    currentPrefixSum - previousPrefixSum = k

Therefore:

    previousPrefixSum = currentPrefixSum - k


Whenever you see:

"Count the number of subarrays whose sum is K"

Think:

    Prefix Sum
          +
    Hash Map


==================================================

IMPORTANT:

Do NOT use Sliding Window for this problem.

Sliding Window generally relies on properties such as
non-negative numbers.

Here:

    nums[i] can be negative.

Therefore, the window cannot be safely expanded/
contracted based only on whether the current sum is
greater or smaller than k.

Prefix Sum + Hash Map works with positive, zero,
and negative numbers.


==================================================
*/