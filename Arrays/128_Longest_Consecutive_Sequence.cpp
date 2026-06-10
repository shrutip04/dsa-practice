/*
==================================================
Problem: 128. Longest Consecutive Sequence
LeetCode: Medium

Approach 1: Sorting
Time: O(n log n)
Space: O(1) or O(log n) depending on sorting implementation

Approach 2: Hash Set (Optimal)
Time: O(n)
Space: O(n)

Learning:
- A consecutive sequence consists of numbers
  that differ by exactly 1.

- Sorting makes consecutive numbers adjacent,
  allowing us to scan the array and count the
  length of each sequence.

- The optimal solution uses a Hash Set for
  O(1) average lookup operations.

- Instead of starting a sequence from every
  number, only start when the previous number
  (num - 1) does not exist.

- If (num - 1) exists, then the current number
  is already part of another sequence and does
  not need to be processed again.

- This prevents repeated work and ensures that
  every number is visited at most once.

Example:

nums = [100,4,200,1,3,2]

Hash Set:

{100,4,200,1,3,2}

--------------------------------------------------

Check each number:

100:
99 does not exist
→ Start sequence

Length = 1

--------------------------------------------------

200:
199 does not exist
→ Start sequence

Length = 1

--------------------------------------------------

1:
0 does not exist
→ Start sequence

1 → 2 → 3 → 4

Length = 4

--------------------------------------------------

2:
1 exists
→ Not a sequence start

Skip

--------------------------------------------------

3:
2 exists
→ Not a sequence start

Skip

--------------------------------------------------

4:
3 exists
→ Not a sequence start

Skip

--------------------------------------------------

Longest Sequence:

1 → 2 → 3 → 4

Length = 4

Output:

4

Pattern:
- Hashing
- Hash Set
- Sequence Detection
- Consecutive Elements
==================================================
*/


// ---------- Approach 1 : Sorting ----------

class Solution1 {
public:
    int longestConsecutive(vector<int>& nums) {

        if(nums.empty())
            return 0;

        sort(nums.begin(), nums.end());

        int longest = 1;
        int current = 1;

        for(int i = 1; i < nums.size(); i++) {

            if(nums[i] == nums[i - 1]) {
                continue;
            }

            if(nums[i] == nums[i - 1] + 1) {
                current++;
            }
            else {
                longest = max(longest, current);
                current = 1;
            }
        }

        return max(longest, current);
    }
};


// ---------- Approach 2 : Hash Set (Optimal) ----------

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        unordered_set<int> st(nums.begin(), nums.end());

        int longest = 0;

        for(int num : st) {

            // Start only from the beginning
            // of a sequence

            if(st.find(num - 1) == st.end()) {

                int currentNum = num;
                int currentLength = 1;

                while(st.find(currentNum + 1) != st.end()) {
                    currentNum++;
                    currentLength++;
                }

                longest = max(longest, currentLength);
            }
        }

        return longest;
    }
};