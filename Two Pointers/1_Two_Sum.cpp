/*-----LeetCode 1 — Two Sum

Given an array of integers nums and an integer target,
return indices of the two numbers such that they add up to target.

You may assume:
1. Exactly one solution exists.
2. You may not use the same element twice.

Example

Input:  nums = [2,7,11,15], target = 9
Output: [0,1]

Explanation:
nums[0] + nums[1] = 2 + 7 = 9

------------------Approach 1: Brute Force-----------------------

Intuition :
Try every possible pair of elements.
If their sum equals target, return their indices.

Algorithm :
1. Use two nested loops.
2. Generate all possible pairs.
3. Check if nums[i] + nums[j] == target.
4. If yes, return {i, j}.

Time Complexity : O(n²)
Space Complexity : O(1)

------------------Approach 2: Optimal (HashMap)-----------------------

Intuition :
For every element nums[i], calculate the number needed
to reach the target.

needed = target - nums[i]

Check whether this needed value has already been seen.

HashMap stores:
    number -> index

If complement exists:
    answer found.

Otherwise:
    store current number and index.

Algorithm :
1. Create a HashMap.
2. Traverse the array.
3. Calculate:
      complement = target - nums[i]
4. Check if complement exists in HashMap.
5. If yes:
      return stored index and current index.
6. Otherwise store:
      nums[i] -> i
7. Continue until answer is found.

Time Complexity : O(n)
Space Complexity : O(n)
*/


--------------------Approach 1: Brute Force-----------------------

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        int n = nums.size();

        for(int i = 0; i < n; i++) {

            for(int j = i + 1; j < n; j++) {

                if(nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }

        return {};
    }
};


--------------------Approach 2: Optimal (HashMap)-----------------------

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int, int> mp;

        for(int i = 0; i < nums.size(); i++) {

            int complement = target - nums[i];

            if(mp.find(complement) != mp.end()) {
                return {mp[complement], i};
            }

            mp[nums[i]] = i;
        }

        return {};
    }
};