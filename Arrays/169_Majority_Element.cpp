/*
==================================================
Problem: 169. Majority Element
LeetCode: Easy

Approach 1: Brute Force
Time: O(n^2)
Space: O(1)

Idea:
- For every element, count how many times it appears.
- If its frequency is greater than n/2, it is the
  majority element.

Algorithm:
1. Traverse every element nums[i].
2. Count its occurrences using another loop.
3. If count > n/2:
      Return nums[i].
4. Return -1 if no majority element is found.

--------------------------------------------------

Approach 2: Hash Map
Time: O(n) Average
Space: O(n)

Idea:
- Store the frequency of each element in a hash map.
- As soon as an element's frequency becomes greater
  than n/2, return it.

Algorithm:
1. Create a hash map:
      element → frequency
2. Traverse the array.
3. Increment the frequency of nums[i].
4. If frequency > n/2:
      Return nums[i].
5. Return -1.

--------------------------------------------------

Approach 3: Sorting
Time: O(n log n)
Space: O(1) Auxiliary

Idea:
- Sort the array.
- Since the majority element appears more than n/2
  times, it must occupy the middle position.
- Therefore, nums[n/2] is always the majority element.

Example:
nums = [2,2,1,1,1,2,2]

After sorting:
[1,1,1,2,2,2,2]
          ↑
        n/2

Algorithm:
1. Sort nums.
2. Return nums[n/2].

--------------------------------------------------

Approach 4: Boyer-Moore Voting Algorithm (Optimal)
Time: O(n)
Space: O(1)

Idea:
- Maintain:
      candidate → current possible majority
      count     → current vote balance

- If count becomes 0, choose the current element
  as the new candidate.
- If current element equals candidate:
      count++
- Otherwise:
      count--

Why It Works:
- The majority element appears more than n/2 times.
- Therefore, it occurs more times than all other
  elements combined.
- We can cancel one majority occurrence with one
  non-majority occurrence.
- After all possible cancellations, the majority
  element will still remain as the candidate.

Example:
[2,2,1,1,1,2,2]

2 → candidate = 2, count = 1
2 → count = 2
1 → count = 1
1 → count = 0
1 → candidate = 1, count = 1
2 → count = 0
2 → candidate = 2, count = 1

Final candidate = 2

Important:
- The problem guarantees that a majority element exists.
- Therefore, the final candidate can be returned directly.
- If a majority was NOT guaranteed, a second pass would
  be required to verify the candidate.

Algorithm:
1. Initialize:
      candidate = 0
      count = 0
2. Traverse every element x:
      a. If count == 0:
            candidate = x
      b. If x == candidate:
            count++
         Else:
            count--
3. Return candidate.

==================================================
*/

// ---------- Approach 1 : Brute Force ----------

class Solution {
public:
    int majorityElement(vector<int>& nums) {

        int n = nums.size();

        for(int i = 0; i < n; i++) {

            int count = 0;

            for(int j = 0; j < n; j++) {

                if(nums[i] == nums[j])
                    count++;
            }

            if(count > n / 2)
                return nums[i];
        }

        return -1;
    }
};


// ---------- Approach 2 : Hash Map ----------

class Solution {
public:
    int majorityElement(vector<int>& nums) {

        int n = nums.size();

        unordered_map<int, int> freq;

        for(int x : nums) {

            freq[x]++;

            if(freq[x] > n / 2)
                return x;
        }

        return -1;
    }
};


// ---------- Approach 3 : Sorting ----------

class Solution {
public:
    int majorityElement(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        return nums[nums.size() / 2];
    }
};


// ---------- Approach 4 : Boyer-Moore Voting Algorithm ----------

class Solution {
public:
    int majorityElement(vector<int>& nums) {

        int candidate = 0;
        int count = 0;

        for(int x : nums) {

            if(count == 0) {
                candidate = x;
            }

            if(x == candidate)
                count++;
            else
                count--;
        }

        return candidate;
    }
};