/*
==================================================
Problem: 242. Valid Anagram
LeetCode: Easy

Approach 1: Sorting
Time: O(n log n)
Space: O(1) or O(n) depending on sorting implementation

Approach 2: Frequency Array (Optimal)
Time: O(n)
Space: O(1)

Learning:
- Two strings are anagrams if they contain the
  same characters with the same frequencies.
- Always check if the lengths are equal first.
- Sorting both strings makes anagrams identical.
- Frequency counting is more efficient because
  it avoids sorting and directly tracks character
  occurrences.
==================================================
*/

// ---------- Approach 1 : Sorting ----------

class Solution1 {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())
            return false;

        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        return s == t;
    }
};

// ---------- Approach 2 : Frequency Array (Optimal) ----------

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())
            return false;

        vector<int> freq(26, 0);

        for(char c : s)
            freq[c - 'a']++;

        for(char c : t)
            freq[c - 'a']--;

        for(int count : freq) {
            if(count != 0)
                return false;
        }

        return true;
    }
};