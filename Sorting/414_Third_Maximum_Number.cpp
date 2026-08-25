/*
==================================================

Problem: 414. Third Maximum Number
LeetCode: Easy

Approach 1: Brute Force
Time: O(n²)
Space: O(n)

Idea:
- Find the maximum distinct number.
- Remove/ignore that number.
- Find the second maximum distinct number.
- Remove/ignore that number.
- Find the third maximum distinct number.
- If the third maximum does not exist,
  return the maximum number.

Algorithm:
1. Find the maximum element.
2. Find the largest element smaller
   than the maximum.
3. Find the largest element smaller
   than the second maximum.
4. If a third maximum exists,
   return it.
5. Otherwise, return the maximum.

Important:
Only DISTINCT values are considered.

Example:
nums = [2,2,3,1]
Distinct values:
[3,2,1]
Third maximum = 1

--------------------------------------------------

Approach 2: Sorting

Time: O(n log n)
Space: O(1)

Idea:
- Sort the array in descending order.
- Traverse the sorted array.
- Count only distinct values.
- The third distinct value is the
  third maximum.
- If there are fewer than 3 distinct
  values, return the maximum.

Example:

nums = [2,2,3,1]
After sorting:
[3,2,2,1]

Distinct values:
3 → first maximum
2 → second maximum
1 → third maximum

Answer: 1

Algorithm:
1. Sort nums in descending order.
2. Store the first element as maximum.
3. Initialize:
      count = 1
4. Traverse the remaining elements.
5. If the current element is different
   from the previous element:
      count++
6. If:
      count == 3
   return current element.
7. If no third maximum exists,
   return nums[0].

--------------------------------------------------

Approach 3: Three Variables (Optimal)

Time: O(n)
Space: O(1)

Idea:
- Maintain three variables:
      first
      second
      third
- They represent:
      first  = largest distinct number
      second = second largest distinct number
      third  = third largest distinct number
- Traverse the array once.
- Ignore duplicates.
- When a number is greater than first,
  shift all values down.
- Otherwise, if it is greater than second,
  update second and third.
- Otherwise, if it is greater than third,
  update third.

Important:
Use long long / LLONG_MIN as the initial
value so that INT_MIN can also be a valid
array element.

Algorithm:
1. Initialize:
      first = LLONG_MIN
      second = LLONG_MIN
      third = LLONG_MIN
2. Traverse every number.
3. If number equals first, second or third:
      skip it
4. If:
      number > first
   then:
      third = second
      second = first
      first = number
5. Else if:
      number > second
   then:
      third = second
      second = number
6. Else if:
      number > third
   then:
      third = number
7. If third does not exist,
   return first.
8. Otherwise, return third.

Why It Works:
Example:
nums = [2,2,3,1]
Initially:
first  = -∞
second = -∞
third  = -∞
Process 2:
first = 2
Process 2:
duplicate → ignore
Process 3:

third = 2
second = 2
first = 3

Process 1:
third = 1

Therefore:

first  = 3
second = 2
third  = 1

Answer:1

--------------------------------------------------

Important Edge Cases:

nums = [1,2]
Distinct values:
2,1
No third maximum.
Return:
2
nums = [2,2,2]
Only one distinct value.
Return:
2
nums = [1,1,2,2]
Only two distinct values.
Return:
2
nums = [3,2,1]

Three distinct values.

Return:

1

==================================================

*/

// ---------- Approach 1 : Brute Force ----------

class Solution {
public:
    int thirdMax(vector<int>& nums) {

        long long first = LLONG_MIN;
        long long second = LLONG_MIN;
        long long third = LLONG_MIN;

        for(int i = 0; i < nums.size(); i++) {

            if(nums[i] > first) {
                first = nums[i];
            }
        }

        for(int i = 0; i < nums.size(); i++) {

            if(nums[i] < first && nums[i] > second) {
                second = nums[i];
            }
        }

        for(int i = 0; i < nums.size(); i++) {

            if(nums[i] < second && nums[i] > third) {
                third = nums[i];
            }
        }

        if(third == LLONG_MIN)
            return first;

        return third;
    }
};


// ---------- Approach 2 : Sorting ----------

class Solution {
public:
    int thirdMax(vector<int>& nums) {

        sort(nums.begin(), nums.end(), greater<int>());

        int count = 1;

        for(int i = 1; i < nums.size(); i++) {

            if(nums[i] != nums[i - 1]) {

                count++;

                if(count == 3)
                    return nums[i];
            }
        }

        return nums[0];
    }
};


// ---------- Approach 3 : Three Variables (Optimal) ----------

class Solution {
public:
    int thirdMax(vector<int>& nums) {

        long long first = LLONG_MIN;
        long long second = LLONG_MIN;
        long long third = LLONG_MIN;

        for(long long num : nums) {

            if(num == first || num == second || num == third)
                continue;

            if(num > first) {

                third = second;
                second = first;
                first = num;
            }

            else if(num > second) {

                third = second;
                second = num;
            }

            else if(num > third) {

                third = num;
            }
        }

        if(third == LLONG_MIN)
            return first;

        return third;
    }
};