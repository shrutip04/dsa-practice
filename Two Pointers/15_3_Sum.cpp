/*-----LeetCode 15 — 3Sum

Given an integer array nums, return all the triplets:

[a, b, c]

such that:

a + b + c = 0

The solution set must not contain duplicate triplets.

Example

Input:  nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]

Explanation:
(-1) + (-1) + 2 = 0
(-1) + 0 + 1 = 0

------------------Approach 1: Brute Force-----------------------

Intuition :
Try every possible triplet using three nested loops.
If the sum equals 0, store the triplet.
Sort each triplet before storing so duplicates can be removed using a set.

Algorithm :
1. Use three loops to generate all triplets.
2. Check if their sum is 0.
3. Sort the triplet.
4. Insert into a set.
5. Convert set into vector and return.

Time Complexity : O(n³)
Space Complexity : O(k)

(k = number of unique triplets)

------------------Approach 2: Better (HashSet)-----------------------

Intuition :
Fix one element and reduce the problem to Two Sum.

For every nums[i]:

nums[j] + nums[k] = -nums[i]

Use a HashSet to quickly check whether the required third element already exists.

Algorithm :
1. Fix one element using loop i.
2. Create a HashSet for every i.
3. Traverse remaining elements using j.
4. Calculate required third element.
5. If third element exists in HashSet:
      triplet found.
6. Sort triplet and insert into set.
7. Add current element into HashSet.
8. Return all unique triplets.

Time Complexity : O(n²)
Space Complexity : O(n)

------------------Approach 3: Optimal (Sorting + Two Pointers)-----------------------

Intuition :
Sort the array.

Fix one element nums[i].

Now find two numbers whose sum equals:

-nums[i]

Since array is sorted:
    If sum is too small → move left pointer.
    If sum is too large → move right pointer.
    If sum becomes 0 → triplet found.

Skip duplicates to avoid repeated triplets.

Algorithm :
1. Sort the array.
2. Fix one element using i.
3. Skip duplicate values of i.
4. Initialize:
      left = i + 1
      right = n - 1
5. Calculate sum.
6. If sum == 0:
      store triplet
      skip duplicate left and right values
7. If sum < 0:
      left++
8. If sum > 0:
      right--
9. Return answer.

Time Complexity : O(n²)
Space Complexity : O(1)

(excluding output array)
*/


--------------------Approach 1: Brute Force-----------------------

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        set<vector<int>> st;
        int n = nums.size();

        for(int i = 0; i < n; i++) {

            for(int j = i + 1; j < n; j++) {

                for(int k = j + 1; k < n; k++) {

                    if(nums[i] + nums[j] + nums[k] == 0) {

                        vector<int> temp = {
                            nums[i],
                            nums[j],
                            nums[k]
                        };

                        sort(temp.begin(), temp.end());

                        st.insert(temp);
                    }
                }
            }
        }

        return vector<vector<int>>(st.begin(), st.end());
    }
};


--------------------Approach 2: Better (HashSet)-----------------------

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        set<vector<int>> st;
        int n = nums.size();

        for(int i = 0; i < n; i++) {

            unordered_set<int> seen;

            for(int j = i + 1; j < n; j++) {

                int third = -(nums[i] + nums[j]);

                if(seen.find(third) != seen.end()) {

                    vector<int> temp = {
                        nums[i],
                        nums[j],
                        third
                    };

                    sort(temp.begin(), temp.end());

                    st.insert(temp);
                }

                seen.insert(nums[j]);
            }
        }

        return vector<vector<int>>(st.begin(), st.end());
    }
};


--------------------Approach 3: Optimal (Sorting + Two Pointers)-----------------------

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());

        int n = nums.size();

        for(int i = 0; i < n - 2; i++) {

            if(i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            int left = i + 1;
            int right = n - 1;

            while(left < right) {

                int sum =
                    nums[i] +
                    nums[left] +
                    nums[right];

                if(sum == 0) {

                    ans.push_back({
                        nums[i],
                        nums[left],
                        nums[right]
                    });

                    while(left < right &&
                          nums[left] == nums[left + 1]) {
                        left++;
                    }

                    while(left < right &&
                          nums[right] == nums[right - 1]) {
                        right--;
                    }

                    left++;
                    right--;
                }

                else if(sum < 0) {
                    left++;
                }

                else {
                    right--;
                }
            }
        }

        return ans;
    }
};