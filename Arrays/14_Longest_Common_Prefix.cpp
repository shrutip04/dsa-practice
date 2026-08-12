/*
==================================================
Problem: 14. Longest Common Prefix
LeetCode: Easy

Approach 1: Horizontal Scanning
Time: O(n * m)
Space: O(1)

Where:
- n = number of strings
- m = length of the shortest string

Idea:
- Start with the first string as the prefix.
- Compare it with every other string.
- If characters don't match, reduce the prefix.
- Continue until all strings share the prefix.

Algorithm:
1. Set prefix = strs[0].
2. For every remaining string:
    a. Compare prefix with the current string.
    b. Find the number of matching characters.
    c. Reduce prefix to the matching part.
3. If prefix becomes empty, return "".
4. Return prefix.

--------------------------------------------------

Approach 2: Vertical Scanning
Time: O(n * m)
Space: O(1)

Idea:
- Compare characters at the same index across all strings.
- Start from index 0 and move forward.
- Stop when:
    1. A string ends, or
    2. A character differs.

Algorithm:
1. Take the first string as reference.
2. For every character index i:
    a. Compare strs[0][i] with the same position
       in every other string.
    b. If any character differs, return prefix
       before index i.
3. Return the complete matching prefix.

--------------------------------------------------

Approach 3: Sorting
Time: O(n log n + m)
Space: O(1) / O(n) depending on sorting implementation

Idea:
- Sort all strings lexicographically.
- After sorting:
      First string
      ...
      Last string

- The common prefix of the entire array must be the
  common prefix of only the FIRST and LAST strings.

Why?
- Lexicographical sorting places the most different
  strings at the extremes.
- If the first and last strings share a prefix,
  every string between them must also share it.

Algorithm:
1. Sort the array.
2. Compare the first and last strings.
3. Find their matching prefix.
4. Return it.

==================================================
*/

// ---------- Approach 1 : Horizontal Scanning ----------

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        string prefix = strs[0];

        for(int i = 1; i < strs.size(); i++) {

            int j = 0;

            while(j < prefix.size() &&
                  j < strs[i].size() &&
                  prefix[j] == strs[i][j]) {
                j++;
            }

            prefix = prefix.substr(0, j);

            if(prefix.empty())
                return "";
        }

        return prefix;
    }
};


// ---------- Approach 2 : Vertical Scanning ----------

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        for(int i = 0; i < strs[0].size(); i++) {

            char current = strs[0][i];

            for(int j = 1; j < strs.size(); j++) {

                if(i >= strs[j].size() ||
                   strs[j][i] != current) {

                    return strs[0].substr(0, i);
                }
            }
        }

        return strs[0];
    }
};


// ---------- Approach 3 : Sorting ----------

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        sort(strs.begin(), strs.end());

        string first = strs[0];
        string last = strs.back();

        int i = 0;

        while(i < first.size() &&
              i < last.size() &&
              first[i] == last[i]) {
            i++;
        }

        return first.substr(0, i);
    }
};