/*
==================================================

Problem: 389. Find the Difference
LeetCode: Easy

Approach 1: Brute Force
Time: O(n²)
Space: O(1)

Idea:

- For every character in t,
  search for the same character in s.

- If the character is found,
  mark it as used.

- The character which cannot be matched
  is the added character.

Algorithm:

1. Traverse every character of t.
2. For every character, search in s.
3. If the character is found:
      mark it as used
4. If the character is not found,
   return that character.
5. Return the added character.

--------------------------------------------------

Approach 2: Sorting
Time: O(n log n)
Space: O(1)

Idea:

- Sort both strings.

- Since t contains exactly one extra
  character, compare both strings
  from the beginning.

- The first position where the
  characters differ contains the
  added character.

- If all characters of s match,
  then the extra character is the
  last character of t.

Algorithm:

1. Sort s.
2. Sort t.
3. Traverse s.
4. Compare:
      s[i] with t[i]
5. If they are different:
      return t[i]
6. If no difference is found,
   return t.back().

Example:

s = "abcd"
t = "abcde"

After sorting:

s = "abcd"
t = "abcde"

Comparison:

a == a
b == b
c == c
d == d

All characters match.
Therefore:
t.back() = e

Answer:   e

--------------------------------------------------

Approach 3: Frequency Map

Time: O(n)
Space: O(26)

Idea:

- Store the frequency of every
  character in s.

- Traverse t.

- Decrease the frequency of each
  character.

- The added character will make its
  frequency negative.

- Return that character.

Algorithm:

1. Create a frequency array of size 26.
2. Count every character in s.
3. Traverse every character in t.
4. Decrease its frequency.
5. If frequency becomes negative:
      return that character.
6. Return the answer.

Example:

s = "abcd"
t = "abcde"

Initial frequency:

a → 1
b → 1
c → 1
d → 1
e → 0

Process t:

a → 0
b → 0
c → 0
d → 0
e → -1

Therefore:

e is the added character.

--------------------------------------------------

Approach 4: XOR (Optimal)

Time: O(n)
Space: O(1)

Idea:

- XOR has two important properties:

      x ^ x = 0

      x ^ 0 = x

- Every character in s appears
  exactly once in t.

- XOR all characters of s and t.

- All matching characters cancel out.

- Only the added character remains.

Example:

s = "abcd"
t = "abcde"

XOR:

a ^ b ^ c ^ d

and:

a ^ b ^ c ^ d ^ e

Combined:

a ^ b ^ c ^ d ^ a ^ b ^ c ^ d ^ e

Matching characters cancel:

e

Therefore:

Answer = e

Algorithm:

1. Initialize:
      ans = 0
2. Traverse every character in s.
3. XOR it with ans.
4. Traverse every character in t.
5. XOR it with ans.
6. Return ans.

Why It Works:

Every character except the added one
appears exactly twice.

Since:

      x ^ x = 0

all duplicate characters cancel.

The only character left is the
character added to t.

==================================================

*/

// ---------- Approach 1 : Brute Force ----------

class Solution {
public:
    char findTheDifference(string s, string t) {

        for(int i = 0; i < t.size(); i++) {

            bool found = false;

            for(int j = 0; j < s.size(); j++) {

                if(t[i] == s[j]) {
                    found = true;
                    s[j] = '#';
                    break;
                }
            }

            if(!found)
                return t[i];
        }

        return '\0';
    }
};


// ---------- Approach 2 : Sorting ----------

class Solution {
public:
    char findTheDifference(string s, string t) {

        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        for(int i = 0; i < s.size(); i++) {

            if(s[i] != t[i])
                return t[i];
        }

        return t.back();
    }
};


// ---------- Approach 3 : Frequency Map ----------

class Solution {
public:
    char findTheDifference(string s, string t) {

        int freq[26] = {0};

        for(char ch : s) {
            freq[ch - 'a']++;
        }

        for(char ch : t) {

            freq[ch - 'a']--;

            if(freq[ch - 'a'] < 0)
                return ch;
        }

        return '\0';
    }
};


// ---------- Approach 4 : XOR (Optimal) ----------

class Solution {
public:
    char findTheDifference(string s, string t) {

        char ans = 0;

        for(char ch : s) {
            ans ^= ch;
        }

        for(char ch : t) {
            ans ^= ch;
        }

        return ans;
    }
};