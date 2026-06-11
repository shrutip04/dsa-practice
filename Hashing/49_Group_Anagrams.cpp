/*
==================================================
Problem: 49. Group Anagrams
LeetCode: Medium

Approach 1: Brute Force
Time: O(n² * k log k)
Space: O(n)

Approach 2: Sorting + HashMap
Time: O(n * k log k)
Space: O(n * k)

Approach 3: Frequency Count + HashMap (Optimal)
Time: O(n * k)
Space: O(n * k)

Learning:
- Two strings are anagrams if they contain the
  same characters with the same frequencies.
- Sorting anagrams produces the same string,
  which can be used as a unique key.
- HashMap helps group all strings having the
  same sorted representation together.
- Instead of sorting, character frequencies can
  be used to generate a unique key in O(k) time.
- Frequency counting avoids the sorting cost and
  gives the optimal solution.
- Classic Hashing + String problem.
==================================================
*/

// ---------- Approach 1 : Brute Force ----------

class Solution1 {
public:
    bool isAnagram(string a, string b) {
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        return a == b;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        int n = strs.size();

        vector<bool> visited(n, false);
        vector<vector<string>> ans;

        for(int i = 0; i < n; i++) {

            if(visited[i])
                continue;

            vector<string> group;
            group.push_back(strs[i]);
            visited[i] = true;

            for(int j = i + 1; j < n; j++) {

                if(!visited[j] &&
                   isAnagram(strs[i], strs[j])) {

                    group.push_back(strs[j]);
                    visited[j] = true;
                }
            }

            ans.push_back(group);
        }

        return ans;
    }
};

// ---------- Approach 2 : Sorting + HashMap ----------

class Solution2 {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string, vector<string>> mp;

        for(string s : strs) {

            string key = s;

            sort(key.begin(), key.end());

            mp[key].push_back(s);
        }

        vector<vector<string>> ans;

        for(auto &it : mp) {
            ans.push_back(it.second);
        }

        return ans;
    }
};

// ---------- Approach 3 : Frequency Count + HashMap (Optimal) ----------

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string, vector<string>> mp;

        for(string s : strs) {

            vector<int> freq(26, 0);

            for(char c : s)
                freq[c - 'a']++;

            string key = "";

            for(int count : freq)
                key += to_string(count) + "#";

            mp[key].push_back(s);
        }

        vector<vector<string>> ans;

        for(auto &it : mp) {
            ans.push_back(it.second);
        }

        return ans;
    }
};