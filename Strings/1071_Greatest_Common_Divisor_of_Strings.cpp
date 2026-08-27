/*
==================================================
Problem: 1071. Greatest Common Divisor of Strings

LeetCode: Easy

Approach 1: Brute Force

Time: O((n + m) * min(n, m))
Space: O(min(n, m))

Idea:
- The answer must be a prefix of both strings.
- Try every possible prefix length from the smaller
  string's length down to 1.
- Check whether that prefix can divide both strings.
- The first valid prefix is the largest answer.

Algorithm:
1. Find the smaller string length.
2. Start from that length and move backwards.
3. Take the prefix of that length.
4. Check if the prefix divides both strings.
5. Return the first valid prefix.
6. If no prefix works, return "".

Code:
*/

class Solution {
public:

    bool divides(string s, string x) {
        if (s.length() % x.length() != 0)
            return false;

        int n = s.length() / x.length();

        string temp = "";

        for (int i = 0; i < n; i++) {
            temp += x;
        }

        return temp == s;
    }

    string gcdOfStrings(string str1, string str2) {

        int len = min(str1.length(), str2.length());

        for (int i = len; i >= 1; i--) {

            string x = str1.substr(0, i);

            if (divides(str1, x) && divides(str2, x)) {
                return x;
            }
        }

        return "";
    }
};


/*
==================================================
Approach 2: Check Concatenation + GCD of Lengths

Time: O(n + m)
Space: O(n + m)

Idea:
- If str1 and str2 have a common divisor string, then:
  
      str1 + str2 == str2 + str1

- If this condition is false, there is no common
  divisor string.
- If it is true, the answer's length is the GCD of
  the two string lengths.
- Return the prefix having that length.

Example:

str1 = "ABABAB"
str2 = "ABAB"

str1 + str2 = "ABABABABAB"
str2 + str1 = "ABABABABAB"

GCD(lengths):
gcd(6, 4) = 2

Prefix of length 2 = "AB"

Answer = "AB"

Algorithm:
1. Check if str1 + str2 == str2 + str1.
2. If not, return "".
3. Find gcd(str1.length(), str2.length()).
4. Return the prefix of that length.

Code:
*/

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {

        if (str1 + str2 != str2 + str1)
            return "";

        int len = gcd(str1.length(), str2.length());

        return str1.substr(0, len);
    }
};


/*
==================================================
Approach 3: Euclidean Algorithm on Strings

Time: O(n + m)
Space: O(n + m)

Idea:
- This follows the same idea as the mathematical
  Euclidean algorithm for GCD.

For numbers:

gcd(a, b) = gcd(b, a % b)

For strings, if str1 starts with str2:
- Remove str2 from the beginning of str1.
- Continue with the remaining part and str2.

Example:

str1 = "ABABAB"
str2 = "ABAB"

Remove "ABAB" from str1:

"ABABAB" -> "AB"

Now:

str1 = "AB"
str2 = "ABAB"

Swap them:

str1 = "ABAB"
str2 = "AB"

Remove "AB":

"ABAB" -> "AB"

Finally both are "AB".

Algorithm:
1. If str1 == str2, return str1.
2. If str1 is shorter than str2, swap them.
3. Check whether the longer string starts with the
   shorter string.
4. If not, return "".
5. Remove the shorter string from the beginning.
6. Repeat.
7. Return the remaining string.

Code:
*/

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {

        if (str1 == str2)
            return str1;

        if (str1.length() < str2.length())
            swap(str1, str2);

        if (str1.substr(0, str2.length()) != str2)
            return "";

        str1 = str1.substr(str2.length());

        return gcdOfStrings(str1, str2);
    }
};


/*
==================================================
Approach 4: Mathematical GCD + Concatenation Check

Time: O(n + m)
Space: O(n + m)

Idea:
- The length of the answer must divide both string
  lengths.
- Therefore, its length must be:

      gcd(str1.length(), str2.length())

- But having the correct length is not enough.
- We must first check whether both strings are made
  from the same repeating pattern.
- The easiest way to verify this is:

      str1 + str2 == str2 + str1

- If true, return the prefix of GCD length.

Code:
*/

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {

        if (str1 + str2 != str2 + str1) {
            return "";
        }

        int len1 = str1.length();
        int len2 = str2.length();

        int g = gcd(len1, len2);

        return str1.substr(0, g);
    }
};


/*
==================================================
DRY RUN

str1 = "ABABAB"
str2 = "ABAB"

Step 1:

str1 + str2
= "ABABABABAB"

str2 + str1
= "ABABABABAB"

They are equal.

So a common divisor exists.

Step 2:

length(str1) = 6
length(str2) = 4

gcd(6, 4) = 2

Step 3:

str1.substr(0, 2)
= "AB"

Check:

"AB" + "AB" + "AB"
= "ABABAB"

"AB" + "AB"
= "ABAB"

Therefore:

Answer = "AB"


==================================================
IMPORTANT OBSERVATION

The key condition is:

str1 + str2 == str2 + str1

Why?

Suppose:

str1 = "ABCABC"
str2 = "ABC"

Both are made from the same repeating pattern "ABC".

Therefore:

str1 + str2
= "ABCABCABC"

str2 + str1
= "ABCABCABC"

But:

str1 = "LEET"
str2 = "CODE"

str1 + str2
= "LEETCODE"

str2 + str1
= "CODELEET"

They are different.

Therefore, there is no common divisor string.


==================================================
APPROACH COMPARISON

Approach 1: Brute Force
- Try every possible prefix.
- Easy to understand.
- Less efficient.

Approach 2: Concatenation + GCD
- Uses the key observation.
- Clean and short.
- Optimal.

Approach 3: String Euclidean Algorithm
- Mimics mathematical Euclidean algorithm.
- Recursive.
- More complicated than necessary.

Approach 4: Mathematical GCD + Check
- Same optimal idea as Approach 2.
- Very clean implementation.


==================================================
BEST APPROACH

Approach 2 / Approach 4

Why?

- Simple
- Optimal
- Easy to explain in an interview
- Uses an important GCD + string pattern observation

Time: O(n + m)
Space: O(n + m)

==================================================
*/