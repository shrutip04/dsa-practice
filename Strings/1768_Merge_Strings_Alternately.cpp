/*
==================================================
Problem: 1768. Merge Strings Alternately

LeetCode: Easy
==================================================


==================================================
Approach 1: max() + Index

Time: O(n + m)
Space: O(n + m)

Idea:
- Find the maximum length of the two strings.
- Iterate from 0 to the maximum length.
- Add word1[i] if it exists.
- Add word2[i] if it exists.
- This automatically handles the remaining characters
  of the longer string.

Algorithm:
1. Create an empty string ans.
2. Find max(word1.length(), word2.length()).
3. Loop through every index i.
4. If i < word1.length(), add word1[i].
5. If i < word2.length(), add word2[i].
6. Return ans.

Code:
*/

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans = "";

        int n = max(word1.length(), word2.length());

        for (int i = 0; i < n; i++) {

            if (i < word1.length()) {
                ans += word1[i];
            }

            if (i < word2.length()) {
                ans += word2[i];
            }
        }

        return ans;
    }
};


/*
==================================================
Approach 2: Two Pointers

Time: O(n + m)
Space: O(n + m)

Idea:
- Use one pointer for each string.
- Add a character from word1.
- Add a character from word2.
- Continue until both strings are completely processed.
- If one string is longer, append its remaining characters.

Algorithm:
1. Create an empty string ans.
2. Initialize i = 0 and j = 0.
3. While i < word1.length() OR j < word2.length():
   - If word1 still has characters, add word1[i].
   - If word2 still has characters, add word2[j].
4. Return ans.

Code:
*/

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans = "";

        int i = 0;
        int j = 0;

        while (i < word1.length() || j < word2.length()) {

            if (i < word1.length()) {
                ans += word1[i];
                i++;
            }

            if (j < word2.length()) {
                ans += word2[j];
                j++;
            }
        }

        return ans;
    }
};


/*
==================================================
Approach 3: Merge Common Part + Append Remaining

Time: O(n + m)
Space: O(n + m)

Idea:
- First merge characters while both strings have
  characters remaining.
- Then append the remaining characters of the
  longer string.

Algorithm:
1. Create an empty string ans.
2. Initialize i = 0.
3. While both strings have characters:
   - Add word1[i].
   - Add word2[i].
   - Increment i.
4. Append remaining characters of word1.
5. Append remaining characters of word2.
6. Return ans.

Code:
*/

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans = "";

        int i = 0;

        while (i < word1.length() && i < word2.length()) {
            ans += word1[i];
            ans += word2[i];
            i++;
        }

        while (i < word1.length()) {
            ans += word1[i];
            i++;
        }

        while (i < word2.length()) {
            ans += word2[i];
            i++;
        }

        return ans;
    }
};


/*
==================================================
Approach 4: Two Pointers + append()

Time: O(n + m)
Space: O(n + m)

Idea:
- Merge characters while both strings have characters.
- Once one string ends, use append() to directly add
  the remaining part of both strings.

Code:
*/

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans = "";

        int i = 0;

        while (i < word1.length() && i < word2.length()) {
            ans += word1[i];
            ans += word2[i];
            i++;
        }

        ans.append(word1, i, word1.length() - i);
        ans.append(word2, i, word2.length() - i);

        return ans;
    }
};


/*
==================================================
Approach 5: For Loop + max()

Time: O(n + m)
Space: O(n + m)

Idea:
- Iterate up to the length of the longer string.
- Add characters from both strings if the current
  index is valid.

Code:
*/

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans = "";

        for (int i = 0; i < max(word1.length(), word2.length()); i++) {

            if (i < word1.length()) {
                ans += word1[i];
            }

            if (i < word2.length()) {
                ans += word2[i];
            }
        }

        return ans;
    }
};


/*
==================================================
COMPARISON

Approach 1: max() + Index
- Simple
- Easy to understand

Approach 2: Two Pointers
- Most intuitive
- Clearly shows the position in each string
- Best for learning the two-pointer pattern

Approach 3: Common Part + Remaining
- Separates the two cases clearly
- Easy to visualize

Approach 4: append()
- Shorter version of Approach 3
- Uses C++ string append()

Approach 5: for + max()
- Most compact version
- Same basic idea as Approach 1

BEST APPROACH:
Approach 2: Two Pointers

Why?
- Clean
- Easy to explain in an interview
- Handles unequal string lengths naturally
- O(n + m) time

==================================================
*/ 