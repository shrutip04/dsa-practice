/*
==================================================

Problem: 58. Length of Last Word
LeetCode: Easy

==================================================


Approach 1: Reverse Traversal

Time: O(n)
Space: O(1)

Idea:

- Start from the end of the string.
- Skip all trailing spaces.
- Once we reach a character, start counting.
- Stop when we reach a space or the beginning of the string.
- The count is the length of the last word.

Algorithm:

1. Set i = s.length() - 1.
2. Skip trailing spaces.
3. Initialize count = 0.
4. Count characters until a space is found.
5. Return count.

Code:

*/

class Solution {
public:
    int lengthOfLastWord(string s) {

        int i = s.length() - 1;
        int count = 0;

        // Skip trailing spaces
        while (i >= 0 && s[i] == ' ') {
            i--;
        }

        // Count last word
        while (i >= 0 && s[i] != ' ') {
            count++;
            i--;
        }

        return count;
    }
};


/*
==================================================

Approach 2: Using find_last_not_of() and find_last_of()

Time: O(n)

Space: O(1)

Idea:

- Find the position of the last non-space character.
- Find the space before that character.
- The difference between these positions gives the
  length of the last word.

Algorithm:

1. Find the last non-space character.
2. Find the last space before it.
3. Return the difference between their positions.

Code:

*/

class Solution {
public:
    int lengthOfLastWord(string s) {

        int end = s.find_last_not_of(' ');
        int start = s.find_last_of(' ', end);

        return end - start;
    }
};


/*
==================================================

Approach 3: Using stringstream

Time: O(n)

Space: O(n)

Idea:

- Use stringstream to split the string into words.
- Keep updating the last word.
- Return the length of the final word.

Algorithm:

1. Create a stringstream from s.
2. Read each word.
3. Store the current word as last.
4. Return last.length().

Code:

*/

class Solution {
public:
    int lengthOfLastWord(string s) {

        stringstream ss(s);
        string word;
        string last;

        while (ss >> word) {
            last = word;
        }

        return last.length();
    }
};


/*
==================================================

Approach 4: Using find() from the End

Time: O(n)

Space: O(1)

Idea:

- Start from the last character.
- Ignore trailing spaces.
- Count characters until a space is encountered.

This is similar to Approach 1 but uses a direct
backward traversal pattern.

Code:

*/

class Solution {
public:
    int lengthOfLastWord(string s) {

        int n = s.length();
        int i = n - 1;

        while (i >= 0 && s[i] == ' ') {
            i--;
        }

        int end = i;

        while (i >= 0 && s[i] != ' ') {
            i--;
        }

        return end - i;
    }
};


/*
==================================================

COMPARISON

Approach 1: Reverse Traversal

- Simple
- Easy to understand
- O(1) extra space
- Best for beginners

Approach 2: find_last_not_of()

- Uses built-in string functions
- Very compact
- Less useful for learning basic traversal

Approach 3: stringstream

- Very readable
- Automatically handles spaces
- Uses extra memory
- Slightly more than necessary for this problem

Approach 4: Backward Traversal with Positions

- Avoids maintaining a separate count
- Uses O(1) extra space
- Good alternative implementation


BEST APPROACH:

Approach 1: Reverse Traversal

Why?

- Simple logic
- No extra data structures
- O(n) time
- O(1) extra space
- Easy to explain in an interview
- Directly solves the problem without processing
  unnecessary words


==================================================

KEY PATTERN:

For problems asking for the "last word", "last element",
or "suffix":

→ Start from the end.

→ Skip unwanted characters.

→ Process until the required boundary is found.


==================================================
*/