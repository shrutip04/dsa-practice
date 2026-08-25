/*
==================================================

Problem: 350. Intersection of Two Arrays II

LeetCode: Easy

Approach 1: Brute Force

Time: O(n1 * n2)

Space: O(n)

Idea:

- For every element in nums1,
  search for the same element in nums2.

- If found, add the element to ans.

- After using an element from nums2,
  mark it as used so that it cannot
  be used again.

- This automatically handles duplicates.

Algorithm:

1. Traverse every element of nums1.

2. For every element, search nums2.

3. If nums1[i] == nums2[j]:

      add nums1[i] to ans

4. Mark nums2[j] as used.

5. Move to the next element.

6. Return ans.

--------------------------------------------------

Approach 2: Sorting + Two Pointers (Better)

Time: O(n1 log n1 + n2 log n2)

Space: O(n)

Idea:

- Sort both arrays.

- Use two pointers:

      i → nums1
      j → nums2

- If both elements are equal,
  they are part of the intersection.

- Add the element and move both pointers.

- If nums1[i] is smaller,
  move i.

- Otherwise, move j.

Important Difference from 349:

- In LeetCode 349, duplicates are removed.

- In LeetCode 350, duplicates must be included
  according to their frequency.

Example:

nums1 = [1,2,2,1]
nums2 = [2,2]

After sorting:

nums1 = [1,1,2,2]
nums2 = [2,2]

Both 2s match.

Answer:

[2,2]

Algorithm:

1. Sort nums1.

2. Sort nums2.

3. Initialize:

      i = 0
      j = 0

4. Traverse while both pointers
   are inside their arrays.

5. If:

      nums1[i] == nums2[j]

   add nums1[i] to ans.

   Move both pointers.

6. If:

      nums1[i] < nums2[j]

   move i.

7. Otherwise:

   move j.

8. Return ans.

--------------------------------------------------

Approach 3: Hash Map (Optimal)

Time: O(n1 + n2) Average

Space: O(n1)

Idea:

- Store the frequency of every element
  in nums1 using an unordered_map.

- Traverse nums2.

- If the element exists in the map
  and its frequency is greater than 0:

      add it to ans

      decrease its frequency

- Once the frequency becomes 0,
  that element cannot be used again.

Example:

nums1 = [1,2,2,1]

Frequency Map:

1 → 2
2 → 2

nums2 = [2,2]

First 2:

      add 2
      frequency of 2 = 1

Second 2:

      add 2
      frequency of 2 = 0

Answer:

[2,2]

Algorithm:

1. Create an unordered_map.

2. Count the frequency of every
   element in nums1.

3. Traverse nums2.

4. If:

      frequency[num] > 0

   then:

      add num to ans
      decrease frequency[num]

5. Return ans.

Why It Works:

If an element appears:

      3 times in nums1

and:

      2 times in nums2

then only:

      min(3,2) = 2

copies can be present in the intersection.

The frequency map naturally handles this.

==================================================

*/

// ---------- Approach 1 : Brute Force ----------

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {

        vector<int> ans;

        for(int i = 0; i < nums1.size(); i++) {

            for(int j = 0; j < nums2.size(); j++) {

                if(nums1[i] == nums2[j]) {

                    ans.push_back(nums1[i]);

                    nums2[j] = -1;

                    break;
                }
            }
        }

        return ans;
    }
};


// ---------- Approach 2 : Sorting + Two Pointers ----------

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {

        vector<int> ans;

        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        int i = 0;
        int j = 0;

        while(i < nums1.size() && j < nums2.size()) {

            if(nums1[i] == nums2[j]) {

                ans.push_back(nums1[i]);

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


// ---------- Approach 3 : Hash Map (Optimal) ----------

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {

        vector<int> ans;

        unordered_map<int, int> freq;

        for(int num : nums1) {
            freq[num]++;
        }

        for(int num : nums2) {

            if(freq[num] > 0) {

                ans.push_back(num);

                freq[num]--;
            }
        }

        return ans;
    }
};