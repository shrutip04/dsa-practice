/*
==================================================
Problem: 217. Contains Duplicate
LeetCode: Easy

Approach 1: Brute Force
Time: O(n²)
Space: O(1)

Approach 2: Sorting
Time: O(n log n)
Space: O(1)

Approach 3: Hash Set (Optimal)
Time: O(n)
Space: O(n)

Learning:
- Brute force causes TLE.
- Sorting makes duplicates adjacent.
- Hashing provides O(1) average lookup.
==================================================
*/

// ---------- Approach 1 : Brute Force ----------

class Solution1 {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();

        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if(nums[i] == nums[j])
                    return true;
            }
        }

        return false;
    }
};

// ---------- Approach 2 : Sorting ----------
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(), nums.end());
        for(int i=0;i<n-1;i++){
            if(nums[i]==nums[i+1]){
                return true;
            }
        }
        return false;
    }
};

// ---------- Approach 3 : Hash Set (Optimal) ----------
class Solution3 {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;

        for(int num : nums) {
            if(s.find(num) != s.end())
                return true;

            s.insert(num);
        }

        return false;
    }
};