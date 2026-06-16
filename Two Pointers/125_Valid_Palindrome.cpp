/*-----LeetCode 125 — Valid Palindrome

Given a string s, return true if it is a palindrome after:
Converting all uppercase letters to lowercase.
Removing all non-alphanumeric characters.
Otherwise, return false.
Example
Input:  "A man, a plan, a canal: Panama"
Output: true
Explanation:
Processed string = "amanaplanacanalpanama"

------------------Approach 1: Brute Force (Clean + Reverse)-----------------------
Intuition : Create a new string containing only lowercase letters and digits. Reverse the cleaned string. Compare the original cleaned string with its reverse.

Algorithm : 
1. Traverse the string.
2. Keep only alphanumeric characters.
3. Convert them to lowercase.
4. Store them in a new string.
5. Reverse the string.
6. Compare both strings.

Time Complexity : O(n)
Space Complexity : O(n)

------------------Approach 2: Two Pointers-----------------------
Intuition :
Instead of creating a new string:
    Start one pointer from the beginning.
    Start another pointer from the end.
    Skip non-alphanumeric characters.
    Compare valid characters ignoring case.
This avoids extra space.

Algorithm : 
1. Initialize two pointers:
left = 0
right = n - 1
2. Skip invalid characters from both sides.
3. Compare lowercase versions of characters.
4. If mismatch found, return false.
5. Move pointers inward.
6. If pointers cross, return true.

Time Complexity : O(n)
Space Complexity : O(1)
*/

--------------------Approach 1: Brute Force (Clean + Reverse)-----------------------
class Solution {
public:
    bool isPalindrome(string s) {

        string cleaned = "";

        for (char c : s) {
            if (isalnum(c)) {
                cleaned += tolower(c);
            }
        }

        string rev = cleaned;
        reverse(rev.begin(), rev.end());

        return cleaned == rev;
    }
};


--------------------Approach 2: Two Pointers-----------------------
class Solution {
public:
    bool isPalindrome(string s) {

        int left = 0;
        int right = s.length() - 1;

        while (left < right) {

            while (left < right && !isalnum(s[left])) {
                left++;
            }

            while (left < right && !isalnum(s[right])) {
                right--;
            }

            if (tolower(s[left]) != tolower(s[right])) {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }
};