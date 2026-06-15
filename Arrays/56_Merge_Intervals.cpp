/*
==================================================
Problem: 56. Merge Intervals
LeetCode: Medium

Approach 1: Brute Force
Time: O(n²)
Space: O(n)

Idea:
- Sort intervals by starting time.
- For every interval, check all following intervals.
- Merge intervals as long as overlap exists.
- Store the final merged interval in answer.

Overlap Condition:
nextStart <= currentEnd

Merge Operation:
mergedEnd = max(currentEnd, nextEnd)

Algorithm:
1. Sort intervals.
2. Traverse every interval.
3. Compare with following intervals.
4. Extend end if overlap exists.
5. Store merged interval.

--------------------------------------------------

Approach 2: Running Interval (Better)
Time: O(n log n)
Space: O(n)

Idea:
- After sorting, overlapping intervals become adjacent.
- Maintain a current interval using:
      start
      end
- If overlap exists:
      extend end
- Otherwise:
      store current interval
      start a new interval

Overlap Condition:
currentStart <= end

Algorithm:
1. Sort intervals.
2. Initialize start and end using first interval.
3. Traverse remaining intervals.
4. If overlap exists:
      end = max(end, currentEnd)
5. Else:
      store current interval
      start new interval
6. Add final interval to answer.

--------------------------------------------------

Approach 3: Answer Vector (Optimal)
Time: O(n log n)
Space: O(n)

Idea:
- Sort intervals by starting time.
- Store first interval in answer.
- The last interval in answer always represents
  the latest merged interval.
- Compare current interval with ans.back().

Overlap Condition:
intervals[i][0] <= ans.back()[1]

Merge Operation:
ans.back()[1] =
max(ans.back()[1], intervals[i][1])

Algorithm:
1. Sort intervals.
2. Push first interval into answer.
3. Traverse remaining intervals.
4. If overlap exists:
      update ending point.
5. Otherwise:
      push current interval.
6. Return answer.

Why It Works:

Sorted Intervals

[1,3] [2,6] [8,10]

Since:

2 <= 3

The intervals overlap.

Merged Interval:

[1,6]

After sorting, all overlapping intervals
appear next to each other, so checking only
the previous merged interval is sufficient.

==================================================
*/

// ---------- Approach 1 : Brute Force ----------

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;
        int n = intervals.size();

        for(int i = 0; i < n; i++) {

            int start = intervals[i][0];
            int end = intervals[i][1];

            if(!ans.empty() && end <= ans.back()[1])
                continue;

            for(int j = i + 1; j < n; j++) {

                if(intervals[j][0] <= end) {
                    end = max(end, intervals[j][1]);
                }
                else {
                    break;
                }
            }

            ans.push_back({start, end});
        }

        return ans;
    }
};

// ---------- Approach 2 : Running Interval ----------

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;

        int start = intervals[0][0];
        int end = intervals[0][1];

        for(int i = 1; i < intervals.size(); i++) {

            if(intervals[i][0] <= end) {

                end = max(end, intervals[i][1]);

            } else {

                ans.push_back({start, end});

                start = intervals[i][0];
                end = intervals[i][1];
            }
        }

        ans.push_back({start, end});

        return ans;
    }
};

// ---------- Approach 3 : Optimal ----------

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;

        ans.push_back(intervals[0]);

        for(int i = 1; i < intervals.size(); i++) {

            if(intervals[i][0] <= ans.back()[1]) {

                ans.back()[1] =
                max(ans.back()[1], intervals[i][1]);

            } else {

                ans.push_back(intervals[i]);
            }
        }

        return ans;
    }
};