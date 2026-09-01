/*
==================================================

Problem: 18. 4Sum

LeetCode: Medium

Approach 1: Brute Force

Time: O(n^4)

Space: O(1) excluding output

Idea:

- Check every possible combination of 4 elements.
- If their sum equals target, add the quadruplet.
- Since duplicate quadruplets are possible, we need to
  avoid adding the same quadruplet multiple times.

Algorithm:

1. Use 4 nested loops:
       i, j, k, l

2. Make sure all four indices are different.

3. Calculate:
       nums[i] + nums[j] + nums[k] + nums[l]

4. If the sum equals target:
       Add the quadruplet to the answer.

5. Sort the quadruplet before storing it so that
   duplicate combinations can be identified.

6. Remove duplicate quadruplets.

Problem:

- O(n^4) is too slow for large arrays.
- We can improve this using sorting and two pointers.

--------------------------------------------------

Approach 2: Sorting + Two Pointers (Optimal)

Time: O(n^3)

Space: O(1) excluding output

Idea:

- Sort the array first.
- Fix the first two elements using two loops.
- Use two pointers to find the remaining two elements.

Pointers:

    i → first element
    j → second element
    l → left pointer
    r → right pointer

After fixing nums[i] and nums[j]:

    nums[i] + nums[j] + nums[l] + nums[r]

Since the array is sorted:

- If sum < target:
      Increase l

- If sum > target:
      Decrease r

- If sum == target:
      Store the quadruplet
      Move both l and r

Duplicates are skipped at every level.

--------------------------------------------------

Example:

nums = [1,0,-1,0,-2,2]
target = 0

After sorting:

nums = [-2,-1,0,0,1,2]

Fix:

i = 0 → nums[i] = -2
j = 1 → nums[j] = -1

Remaining:

l = 2 → 0
r = 5 → 2

Sum:

-2 + (-1) + 0 + 2 = -1

sum < target

Move l:

l = 3

Sum:

-2 + (-1) + 0 + 2 = -1

Still smaller.

Eventually move i/j and pointers.

One valid quadruplet:

[-2,-1,1,2]

Sum:

-2 + (-1) + 1 + 2 = 0

Another:

[-2,0,0,2]

And:

[-1,0,0,1]

Final Answer:

[
    [-2,-1,1,2],
    [-2,0,0,2],
    [-1,0,0,1]
]

--------------------------------------------------

Handling Duplicates:

For i:

if(i > 0 && nums[i] == nums[i - 1])
    continue;

This prevents choosing the same first element again.

For j:

if(j > i + 1 && nums[j] == nums[j - 1])
    continue;

This prevents choosing the same second element again.

After finding a valid quadruplet:

while(l < r && nums[l] == nums[l + 1])
    l++;

while(l < r && nums[r] == nums[r - 1])
    r++;

Then:

l++;
r--;

This skips duplicate third and fourth elements.

--------------------------------------------------

Important:

Use long long for the sum.

Why?

The values in nums can be large, and adding four
integers can cause integer overflow.

So instead of:

int sum = nums[i] + nums[j] + nums[l] + nums[r];

Use:

long long sum =
    (long long)nums[i] + nums[j] + nums[l] + nums[r];

--------------------------------------------------

Algorithm:

1. Sort nums.

2. Loop i from 0 to n - 4.

3. Skip duplicate values of i.

4. Loop j from i + 1 to n - 3.

5. Skip duplicate values of j.

6. Set:
       l = j + 1
       r = n - 1

7. While l < r:

       Calculate sum.

       If sum == target:
           Add quadruplet.
           Skip duplicate l values.
           Skip duplicate r values.
           l++;
           r--;

       Else if sum < target:
           l++;

       Else:
           r--;

8. Return answer.

--------------------------------------------------

Why It Works:

- Sorting allows us to use the two-pointer technique.
- i and j fix the first two elements.
- l and r search for the remaining two elements.
- Because the array is sorted:
      smaller sum → move l forward
      larger sum  → move r backward
- Duplicate checks ensure that every quadruplet
  appears only once.

--------------------------------------------------

Complexity:

Sorting:

    O(n log n)

Choosing i and j:

    O(n^2)

Two-pointer search:

    O(n)

Overall:

    O(n^3)

Extra Space:

    O(1)

excluding the space required for the output.

==================================================
*/

// ---------- Approach 1 : Brute Force ----------

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, long long target) {

        vector<vector<int>> ans;
        int n = nums.size();

        set<vector<int>> unique;

        for(int i = 0; i < n - 3; i++) {
            for(int j = i + 1; j < n - 2; j++) {
                for(int k = j + 1; k < n - 1; k++) {
                    for(int l = k + 1; l < n; l++) {

                        long long sum =
                            (long long)nums[i] +
                            nums[j] +
                            nums[k] +
                            nums[l];

                        if(sum == target) {

                            vector<int> quad = {
                                nums[i],
                                nums[j],
                                nums[k],
                                nums[l]
                            };

                            sort(quad.begin(), quad.end());

                            unique.insert(quad);
                        }
                    }
                }
            }
        }

        for(auto quad : unique) {
            ans.push_back(quad);
        }

        return ans;
    }
};


// ---------- Approach 2 : Sorting + Two Pointer ----------

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, long long target) {

        vector<vector<int>> ans;

        int n = nums.size();

        sort(nums.begin(), nums.end());

        for(int i = 0; i < n - 3; i++) {

            // Skip duplicate first elements
            if(i > 0 && nums[i] == nums[i - 1])
                continue;

            for(int j = i + 1; j < n - 2; j++) {

                // Skip duplicate second elements
                if(j > i + 1 && nums[j] == nums[j - 1])
                    continue;

                int l = j + 1;
                int r = n - 1;

                while(l < r) {

                    long long sum =
                        (long long)nums[i] +
                        nums[j] +
                        nums[l] +
                        nums[r];

                    if(sum == target) {

                        ans.push_back({
                            nums[i],
                            nums[j],
                            nums[l],
                            nums[r]
                        });

                        // Skip duplicate third elements
                        while(l < r && nums[l] == nums[l + 1])
                            l++;

                        // Skip duplicate fourth elements
                        while(l < r && nums[r] == nums[r - 1])
                            r--;

                        l++;
                        r--;
                    }

                    else if(sum < target) {
                        l++;
                    }

                    else {
                        r--;
                    }
                }
            }
        }

        return ans;
    }
};

