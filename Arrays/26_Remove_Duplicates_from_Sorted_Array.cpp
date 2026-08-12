/*
==================================================
Problem: 26. Remove Duplicates from Sorted Array
LeetCode: Easy

Approach 1: Extra Array
Time: O(n)
Space: O(n)

Idea:
- Create a new array to store only unique elements.
- Since the input array is sorted, duplicates are
  always next to each other.
- Add an element only when it is different from
  the previously stored element.
- Copy the unique elements back into nums.

Algorithm:
1. Create an empty temporary array.
2. Add nums[0] to temp.
3. Traverse nums from index 1.
4. If nums[i] != nums[i-1]:
      Add nums[i] to temp.
5. Copy temp back to nums.
6. Return temp.size().

--------------------------------------------------

Approach 2: Two Pointer / In-Place (Optimal)
Time: O(n)
Space: O(1)

Idea:
- Since nums is sorted, duplicates are adjacent.
- Use two pointers:
  
      i → position of the last unique element
      j → scans the array

- Whenever nums[j] is different from nums[i],
  we found a new unique element.
- Place it at the next available position.

Example:
nums = [0,0,1,1,2,2,3]

Initial:
i = 0
nums = [0,0,1,1,2,2,3]

j finds 1:
nums[i+1] = nums[j]
nums = [0,1,1,1,2,2,3]

j finds 2:
nums = [0,1,2,1,2,2,3]

j finds 3:
nums = [0,1,2,3,2,2,3]

First 4 elements are unique.

Algorithm:
1. If nums is empty, return 0.
2. Set i = 0.
3. Traverse j from 1 to n-1.
4. If nums[j] != nums[i]:
      i++;
      nums[i] = nums[j];
5. Return i + 1.

Why It Works:
- The array is sorted, so equal elements are adjacent.
- i always points to the last unique element.
- j searches for the next different element.
- Every unique element is placed at the next position.

==================================================
*/

// ---------- Approach 1 : Extra Array ----------

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        vector<int> temp;

        temp.push_back(nums[0]);

        for(int i = 1; i < nums.size(); i++) {

            if(nums[i] != nums[i - 1]) {
                temp.push_back(nums[i]);
            }
        }

        for(int i = 0; i < temp.size(); i++) {
            nums[i] = temp[i];
        }

        return temp.size();
    }
};


// ---------- Approach 2 : Two Pointer / In-Place ----------

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        int n = nums.size();

        if(n == 0)
            return 0;

        int i = 0;

        for(int j = 1; j < n; j++) {

            if(nums[j] != nums[i]) {

                i++;

                nums[i] = nums[j];
            }
        }

        return i + 1;
    }
};