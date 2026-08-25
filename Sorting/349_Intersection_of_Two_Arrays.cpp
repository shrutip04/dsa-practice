/*
==================================================

Problem: 349. Intersection of Two Arrays

LeetCode: Easy

Approach 1: Brute Force

Time: O(n1 * n2)

Space: O(n)

Idea:

- For every element in nums1,
  search for the same element in nums2.

- If the element is found,
  add it to the answer.

- Since the answer must contain
  unique elements, check whether
  the element is already present
  before adding it.

Algorithm:

1. Traverse every element of nums1.

2. For every element, traverse nums2.

3. If:

      nums1[i] == nums2[j]

   then the element is common.

4. Check whether the element is
   already present in ans.

5. If not present, add it to ans.

6. Return ans.

--------------------------------------------------

Approach 2: Sorting + Nested Loop

Time: O(n1 log n1 + n2 log n2 + n1 * n2)

Space: O(n)

Idea:

- Sort both arrays.

- Sorting makes the values ordered,
  but we still search nums2 for
  every element of nums1.

- Use ans.back() to avoid duplicates.

- This is slightly cleaner than
  pure brute force, but the nested
  loop still makes it O(n1 * n2).

Algorithm:

1. Sort nums1.

2. Sort nums2.

3. Traverse every element of nums1.

4. Search for that element in nums2.

5. If found:

      add it to ans

   only if it is not already present.

6. Return ans.

--------------------------------------------------

Approach 3: Sorting + Two Pointers (Better)

Time: O(n1 log n1 + n2 log n2)

Space: O(n)

Idea:

- Sort both arrays.

- Use two pointers:

      i → nums1
      j → nums2

- Since both arrays are sorted,
  we can decide which pointer to move.

Conditions:

If:

      nums1[i] == nums2[j]

Then the element is common.

      add nums1[i]
      i++
      j++

If:

      nums1[i] < nums2[j]

Then nums1[i] cannot match the
current or any previous element
of nums2.

      i++

If:

      nums1[i] > nums2[j]

Then nums2[j] cannot match the
current or any previous element
of nums1.

      j++

To maintain unique elements:

      if(ans.empty() || ans.back() != nums1[i])

add the element to ans.

Algorithm:

1. Sort nums1.

2. Sort nums2.

3. Initialize:

      i = 0
      j = 0

4. Traverse while both pointers
   are inside their arrays.

5. If nums1[i] == nums2[j]:

      add element if it is unique
      i++
      j++

6. If nums1[i] < nums2[j]:

      i++

7. Otherwise:

      j++

8. Return ans.

Why It Works:

Example:

nums1 = [1,2,2,1]
nums2 = [2,2]

After sorting:

nums1 = [1,1,2,2]
nums2 = [2,2]

Initially:

i = 0
j = 0

1 < 2

Therefore:

i++

Now:

1 < 2

Therefore:

i++

Now:

2 == 2

Add 2.

Move both pointers.

The next 2 is already present
in ans, so it is not added again.

Result:

[2]

--------------------------------------------------

Approach 4: Hash Set (Optimal)

Time: O(n1 + n2) Average

Space: O(n1)

Idea:

- Store all elements of nums1
  in an unordered_set.

- Traverse nums2.

- If an element exists in the set,
  it is common.

- Add it to ans.

- Remove it from the set after adding
  so that duplicates are not added.

Algorithm:

1. Create an unordered_set.

2. Insert all elements of nums1.

3. Traverse nums2.

4. If nums2[i] exists in the set:

      add it to ans

5. Erase the element from the set.

6. Continue until nums2 is completely
   traversed.

7. Return ans.

Why Erase?

Suppose:

nums2 = [2,2,2]

After finding the first 2:

      ans = [2]

Erase 2 from the set.

Therefore, the next 2 will not
be added again.

==================================================

*/

// ---------- Approach 1 : Brute Force ----------

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

        vector<int> ans;

        for(int i = 0; i < nums1.size(); i++) {

            for(int j = 0; j < nums2.size(); j++) {

                if(nums1[i] == nums2[j]) {

                    if(find(ans.begin(), ans.end(), nums1[i]) == ans.end()) {
                        ans.push_back(nums1[i]);
                    }

                    break;
                }
            }
        }

        return ans;
    }
};


// ---------- Approach 2 : Sorting + Nested Loop ----------

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

        vector<int> ans;

        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        for(int i = 0; i < nums1.size(); i++) {

            for(int j = 0; j < nums2.size(); j++) {

                if(nums1[i] == nums2[j]) {

                    if(ans.empty() || ans.back() != nums1[i]) {
                        ans.push_back(nums1[i]);
                    }

                    break;
                }
            }
        }

        return ans;
    }
};


// ---------- Approach 3 : Sorting + Two Pointers ----------

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

        vector<int> ans;

        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        int i = 0;
        int j = 0;

        while(i < nums1.size() && j < nums2.size()) {

            if(nums1[i] == nums2[j]) {

                if(ans.empty() || ans.back() != nums1[i]) {
                    ans.push_back(nums1[i]);
                }

                i++;
                j++;
            }

            else if(nums1[i] < nums2[j]) {
                i++;
            }

            else {
                j++;
            }
        }

        return ans;
    }
};


// ---------- Approach 4 : Hash Set (Optimal) ----------

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

        unordered_set<int> s(nums1.begin(), nums1.end());

        vector<int> ans;

        for(int num : nums2) {

            if(s.count(num)) {

                ans.push_back(num);

                s.erase(num);
            }
        }

        return ans;
    }
};