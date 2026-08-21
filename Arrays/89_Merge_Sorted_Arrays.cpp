/*
==================================================
Problem: 88. Merge Sorted Array
LeetCode: Easy

Approach 1: Brute Force / Extra Array
Time: O(m + n)
Space: O(m + n)

Idea:
- Create a new array to store the merged result.
- Use two pointers to compare elements of nums1 and
  nums2.
- Copy the merged result back into nums1.

Algorithm:
1. Initialize:
      i = 0  → pointer for nums1
      j = 0  → pointer for nums2

2. Compare nums1[i] and nums2[j].
3. Add the smaller element to the new array.
4. Continue until one array is completely traversed.
5. Copy the remaining elements.
6. Copy the result back into nums1.

--------------------------------------------------

Approach 2: Two Pointers from Front
Time: O(m + n)
Space: O(m + n)

Idea:
- Use two pointers to traverse the valid elements of
  nums1 and nums2.
- Store the merged result in a temporary array.
- This avoids overwriting the original elements of nums1.

Algorithm:
1. Create a temporary array.
2. Use:
      i = 0  → nums1
      j = 0  → nums2

3. While i < m and j < n:
      If nums1[i] <= nums2[j]:
            Add nums1[i]
            i++
      Else:
            Add nums2[j]
            j++

4. Copy remaining elements from nums1.
5. Copy remaining elements from nums2.
6. Copy the temporary array into nums1.

--------------------------------------------------

Approach 3: Two Pointers from Back (Optimal)
Time: O(m + n)
Space: O(1)

Idea:
- nums1 already has enough empty space at the end to
  store nums2.
- Instead of merging from the front, merge from the back.
- The largest element is placed at the last available
  position.
- This prevents overwriting elements of nums1 that are
  still needed.

Use three pointers:

      i → last actual element of nums1
      j → last element of nums2
      k → last position of nums1

Example:

nums1 = [1,2,3,0,0,0]
nums2 = [2,5,6]

Initially:

      i = 2
      j = 2
      k = 5

Compare from the back:

3 vs 6 → place 6
3 vs 5 → place 5
3 vs 2 → place 3
2 vs 2 → place 2
1 vs 2 → place 2
1 remains → already in correct position

Final:
[1,2,2,3,5,6]

Why Merge from Back?
- nums1 contains its actual elements at the beginning
  and empty space at the end.
- If we merge from the front, we may overwrite elements
  of nums1 that have not been processed yet.
- Starting from the back avoids this problem.

Algorithm:
1. Initialize:
      i = m - 1
      j = n - 1
      k = m + n - 1

2. While j >= 0:

      If i >= 0 AND nums1[i] > nums2[j]:
            nums1[k] = nums1[i]
            i--
      
      Else:
            nums1[k] = nums2[j]
            j--

      k--

3. Return nums1.

Important:
- We only need to continue while j >= 0.
- If nums2 is completely processed, the remaining
  elements of nums1 are already in their correct
  positions.
- The condition i >= 0 is important because m can be 0.

--------------------------------------------------

Edge Case 1:

nums1 = [1]
m = 1
nums2 = []
n = 0

No elements from nums2 need to be merged.

Result:
[1]

--------------------------------------------------

Edge Case 2:

nums1 = [0]
m = 0
nums2 = [1]
n = 1

There are no actual elements in nums1.

The element from nums2 is directly placed:

[1]

--------------------------------------------------

Edge Case 3:

Duplicate Elements

nums1 = [1,2,3,0,0,0]
nums2 = [2,5,6]

Equal elements are handled correctly.

Result:
[1,2,2,3,5,6]

--------------------------------------------------

Why Does the Optimal Approach Work?

Both arrays are already sorted.

Therefore, the largest remaining element must be either:

      nums1[i]
           OR
      nums2[j]

We place the larger one at nums1[k].

Since k starts from the last position, we never overwrite
an unprocessed element of nums1.

--------------------------------------------------

Complexity:

Time:
O(m + n)

Each element is processed at most once.

Space:
O(1)

No extra array or data structure is used.

--------------------------------------------------

Pattern:

Two Pointers
+
In-Place Array
+
Merge from Back

Whenever you see:

"Two sorted arrays + first array has extra space
at the end + merge in-place"

Think:

      i = m - 1
      j = n - 1
      k = m + n - 1

      Merge from BACK.

==================================================
*/


// ---------- Approach 1 : Brute Force / Extra Array ----------

class Solution {
public:
    void merge(vector<int>& nums1, int m,
               vector<int>& nums2, int n) {

        vector<int> result;

        int i = 0;
        int j = 0;

        while(i < m && j < n) {

            if(nums1[i] <= nums2[j]) {
                result.push_back(nums1[i]);
                i++;
            }
            else {
                result.push_back(nums2[j]);
                j++;
            }
        }

        while(i < m) {
            result.push_back(nums1[i]);
            i++;
        }

        while(j < n) {
            result.push_back(nums2[j]);
            j++;
        }

        for(int k = 0; k < m + n; k++) {
            nums1[k] = result[k];
        }
    }
};


// ---------- Approach 2 : Two Pointers from Front ----------

class Solution {
public:
    void merge(vector<int>& nums1, int m,
               vector<int>& nums2, int n) {

        vector<int> result;

        int i = 0;
        int j = 0;

        while(i < m && j < n) {

            if(nums1[i] <= nums2[j]) {
                result.push_back(nums1[i]);
                i++;
            }
            else {
                result.push_back(nums2[j]);
                j++;
            }
        }

        while(i < m) {
            result.push_back(nums1[i]);
            i++;
        }

        while(j < n) {
            result.push_back(nums2[j]);
            j++;
        }

        nums1 = result;
    }
};


// ---------- Approach 3 : Two Pointers from Back (Optimal) ----------

class Solution {
public:
    void merge(vector<int>& nums1, int m,
               vector<int>& nums2, int n) {

        int i = m - 1;        // Last actual element of nums1
        int j = n - 1;        // Last element of nums2
        int k = m + n - 1;    // Last position of nums1

        while(j >= 0) {

            if(i >= 0 && nums1[i] > nums2[j]) {
                nums1[k] = nums1[i];
                i--;
            }
            else {
                nums1[k] = nums2[j];
                j--;
            }

            k--;
        }
    }
};