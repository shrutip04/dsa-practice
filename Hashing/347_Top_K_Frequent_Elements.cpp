/*
==================================================
Problem: 347. Top K Frequent Elements
LeetCode: Medium

Approach 1: Sorting + Frequency Counting
Time: O(n log n)
Space: O(n)

Approach 2: Hash Map + Min Heap (Optimal)
Time: O(n log k)
Space: O(n)

Learning:
- Sorting groups identical elements together,
  making frequency counting easier.
- Store frequencies as {count, number} pairs.
- After counting frequencies, sort the pairs
  in descending order of frequency.
- The first k elements after sorting are the
  k most frequent elements.
- For Top K problems, a Heap (Priority Queue)
  is a common optimization.
- The optimal solution uses a Hash Map for
  frequency counting and a Min Heap of size k
  to keep only the k most frequent elements.
==================================================
*/

// ---------- Approach 1 : Sorting + Frequency Counting ----------

class Solution1 {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        sort(nums.begin(), nums.end());

        vector<pair<int,int>> freq; // {count, number}

        int count = 1;
        int n = nums.size();

        for(int i = 1; i < n; i++) {

            if(nums[i] == nums[i - 1]) {
                count++;
            }
            else {
                freq.push_back({count, nums[i - 1]});
                count = 1;
            }
        }

        freq.push_back({count, nums[n - 1]});

        sort(freq.begin(), freq.end(), greater<pair<int,int>>());

        vector<int> ans;

        for(int i = 0; i < k; i++) {
            ans.push_back(freq[i].second);
        }

        return ans;
    }
};

// ---------- Approach 2 : Hash Map + Min Heap (Optimal) ----------

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int, int> freq;

        for(int num : nums) {
            freq[num]++;
        }

        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;

        for(auto &it : freq) {

            pq.push({it.second, it.first});

            if(pq.size() > k) {
                pq.pop();
            }
        }

        vector<int> ans;

        while(!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};