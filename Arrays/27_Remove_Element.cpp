/*
==================================================
Problem: 27. Remove Element
LeetCode: Easy

Approach 1: Extra Array
Time: O(n)
Space: O(n)

Idea:
- Create a temporary array.
- Store only the elements that are NOT equal to val.
- Copy the valid elements back into nums.
- Return the number of valid elements.

Algorithm:
1. Create an empty temporary array.
2. Traverse the array.
3. If nums[i] != val:
      Add nums[i] to temp.
4. Copy temp back into nums.
5. Return temp.size().

--------------------------------------------------

Approach 2: Two Pointer / In-Place (Optimal)
Time: O(n)
Space: O(1)

Idea:
- Use one pointer to keep track of the position
  where the next valid element should be placed.
- Traverse the entire array using another pointer.
- If nums[j] != val:
      Store nums[j] at nums[i].
      Move i forward.
- Elements equal to val are simply skipped.

Pointers:
    i → position where next valid element is placed
    j → scans every element

Example:
nums = [3,2,2,3], val = 3

Initial:
i = 0

j = 0 → 3 == val → skip

j = 1 → 2 != val
nums[i] = nums[j]
nums[0] = 2
i++

j = 2 → 2 != val
nums[i] = nums[j]
nums[1] = 2
i++

j = 3 → 3 == val → skip

Result:
[2,2,_,_]

Return:
i = 2

Algorithm:
1. Set i = 0.
2. Traverse j from 0 to n-1.
3. If nums[j] != val:
      nums[i] = nums[j];
      i++;
4. Return i.

Why It Works:
- i always represents the next position where a
  valid element should be placed.
- j checks every element.
- Elements equal to val are ignored.
- Therefore, the first i elements contain all
  elements that are not equal to val.

--------------------------------------------------

Approach 3: Two Pointer from Both Ends
Time: O(n)
Space: O(1)

Idea:
- Since the problem allows the order of elements
  to change, we can replace an unwanted element
  with an element from the end of the array.
- Use:
      i → scans from the beginning
      n-1 → scans from the end
- When nums[i] == val, replace it with nums[last].
- Reduce the effective array size.

Algorithm:
1. Set i = 0 and n = nums.size().
2. While i < n:
      a. If nums[i] == val:
            nums[i] = nums[n-1];
            n--;
      b. Else:
            i++;
3. Return n.

Why It Works:
- The order of elements does not matter.
- Whenever val is found, replace it with an
  element from the end.
- Reduce the effective size of the array.
- Continue until all elements in the first n
  positions are valid.

==================================================
*/

// ---------- Approach 1 : Extra Array ----------

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {

        vector<int> temp;

        for(int i = 0; i < nums.size(); i++) {

            if(nums[i] != val) {
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
    int removeElement(vector<int>& nums, int val) {

        int i = 0;

        for(int j = 0; j < nums.size(); j++) {

            if(nums[j] != val) {

                nums[i] = nums[j];

                i++;
            }
        }

        return i;
    }
};


// ---------- Approach 3 : Two Pointer from Both Ends ----------

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {

        int i = 0;
        int n = nums.size();

        while(i < n) {

            if(nums[i] == val) {

                nums[i] = nums[n - 1];

                n--;
            }
            else {

                i++;
            }
        }

        return n;
    }
};