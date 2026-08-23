/*
\==================================================

Problem: 28. Find the Index of the First Occurrence in a String

LeetCode: Easy

Approach 1: Brute Force

Time: O(n * m)

Space: O(1)

Where:

n = length of haystack

m = length of needle

Idea:

\- Check every possible starting position in haystack.

\- Starting from that position, compare the characters

  of needle with the characters of haystack.

\- If all characters match, return that starting index.

\- If no complete match is found, return -1.

Algorithm:

1\. Traverse every possible starting position i.

2\. For every i, compare needle[j] with:

      haystack[i + j]

3\. Continue comparing while characters match.

4\. If all characters of needle match:

      Return i.

5\. If no match is found:

      Return -1.

--------------------------------------------------

Example:

haystack = "sadbutsad"

needle = "sad"

At index 0:

haystack:

s a d

needle:

s a d

All characters match.

Therefore:

Answer = 0

--------------------------------------------------

Why do we traverse only up to n - m?

Suppose:

haystack.length() = 9

needle.length() = 3

The last possible starting position is:

9 - 3 = 6

Therefore, we only need to check:

0, 1, 2, 3, 4, 5, 6

Starting from index 7 is not possible because only

2 characters remain, but needle has 3 characters.

Therefore:

      i <= n - m

--------------------------------------------------

Example:

haystack = "hello"

needle = "ll"

Check index 0:

h != l

Check index 1:

e != l

Check index 2:

l = l

l = l

Complete match found.

Answer = 2

--------------------------------------------------

Example:

haystack = "leetcode"

needle = "leeto"

At index 0:

l = l

e = e

e = e

t = t

c != o

Mismatch.

Continue checking other positions.

No complete match is found.

Answer = -1

--------------------------------------------------

Complexity:

Time:

O(n * m)

In the worst case, we compare m characters at

each possible starting position.

Space:

O(1)

Only a few variables are used.

\--------------------------------------------------

Approach 2: Built-in find()

Time: O(n * m) Worst Case

Space: O(1) Auxiliary

Idea:

\- C++ provides a built-in find() function for strings.

\- It searches for the first occurrence of needle

  inside haystack.

\- If needle is found, it returns its starting index.

\- If needle is not found, it returns string::npos.

Algorithm:

1\. Use:

      haystack.find(needle)

2\. Store the returned position.

3\. If the position is string::npos:

      Return -1.

4\. Otherwise:

      Return the position.

--------------------------------------------------

Example:

haystack = "sadbutsad"

needle = "sad"

      haystack.find(needle)

returns:

      0

Therefore:

Answer = 0

--------------------------------------------------

Important:

\- This approach is very short.

\- However, in interviews, the interviewer may ask

  you to implement the string matching logic yourself.

\- Therefore, understand the Brute Force approach properly.

--------------------------------------------------

Complexity:

Time:

O(n * m) Worst Case

Space:

O(1) Auxiliary

--------------------------------------------------

Approach 3: KMP (Knuth-Morris-Pratt)

Time: O(n + m)

Space: O(m)

Idea:

\- Brute Force may compare the same characters repeatedly.

\- KMP avoids unnecessary comparisons.

\- KMP uses an LPS array to determine how much of the

  pattern can be reused after a mismatch.

LPS stands for:

Longest Proper Prefix which is also a Suffix.

--------------------------------------------------

Example:

needle = "abab"

LPS array:

[0, 0, 1, 2]

Explanation:

For "a":

No proper prefix and suffix.

LPS[0] = 0

For "ab":

No matching prefix and suffix.

LPS[1] = 0

For "aba":

Prefix = "a"

Suffix = "a"

Therefore:

LPS[2] = 1

For "abab":

Prefix = "ab"

Suffix = "ab"

Therefore:

LPS[3] = 2

--------------------------------------------------

Why KMP Works:

Suppose some characters of needle have already matched

and then a mismatch occurs.

Brute Force starts comparing again from the beginning

of needle.

KMP uses the LPS array to know how many characters

are already useful.

Therefore, unnecessary comparisons are avoided.

--------------------------------------------------

Algorithm:

1\. Create an LPS array for needle.

2\. Initialize:

      i = 0

      j = 0

3\. Compare:

      haystack[i]

   with:

      needle[j]

4\. If they match:

      i++

      j++

5\. If:

      j == m

   then the complete needle has been found.

   Return:

      i - j

6\. If characters do not match and j > 0:

      j = lps[j - 1]

7\. If characters do not match and j == 0:

      i++

8\. If the complete needle is never found:

      Return -1.

--------------------------------------------------

Complexity:

Time:

O(n + m)

Building the LPS array takes O(m).

Searching the haystack takes O(n).

Therefore:

O(n + m)

Space:

O(m)

The LPS array requires O(m) space.

--------------------------------------------------

Pattern:

String Matching

\+

Pattern Searching

\+

LPS / Prefix-Suffix

Whenever you see:

"Find the first occurrence of one string inside

another string"

Think:

      String Matching

Basic approach:

      Try every starting index

      +

      Compare characters

      +

      Return first complete match

For optimized string matching:

      KMP

--------------------------------------------------

Important:

\- Brute Force is the easiest approach to understand.

\- Built-in find() is the shortest implementation.

\- KMP provides O(n + m) time complexity.

\- For LeetCode Easy and placement preparation,

  Brute Force is an important approach to know first.

\==================================================
*/


// ---------- Approach 1 : Brute Force ----------

class Solution {
public:

    int strStr(string haystack, string needle) {

        int n = haystack.size();
        int m = needle.size();

        for(int i = 0; i <= n - m; i++) {

            int j = 0;

            while(j < m && haystack[i + j] == needle[j]) {
                j++;
            }

            if(j == m)
                return i;
        }

        return -1;
    }
};


// ---------- Approach 2 : Built-in find() ----------

class Solution {
public:

    int strStr(string haystack, string needle) {

        size_t pos = haystack.find(needle);

        if(pos == string::npos)
            return -1;

        return pos;
    }
};


// ---------- Approach 3 : KMP (Optimal) ----------

class Solution {
public:

    int strStr(string haystack, string needle) {

        int n = haystack.size();
        int m = needle.size();

        vector<int> lps(m, 0);

        // Build LPS array
        int len = 0;
        int i = 1;

        while(i < m) {

            if(needle[i] == needle[len]) {

                len++;
                lps[i] = len;
                i++;

            } else {

                if(len != 0) {

                    len = lps[len - 1];

                } else {

                    lps[i] = 0;
                    i++;
                }
            }
        }

        // Search needle in haystack
        i = 0;
        int j = 0;

        while(i < n) {

            if(haystack[i] == needle[j]) {

                i++;
                j++;

                if(j == m)
                    return i - j;

            } else {

                if(j != 0) {

                    j = lps[j - 1];

                } else {

                    i++;
                }
            }
        }

        return -1;
    }
};