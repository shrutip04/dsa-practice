/*
==================================================

Problem: 202. Happy Number
LeetCode: Easy

==================================================
Approach 1: Hash Set
Time: O(log n)
Space: O(log n)

Idea:
- Repeatedly calculate the sum of squares of the digits.
- Store every number that we have already seen.
- If the number becomes 1, it is a happy number.
- If the same number appears again, we have entered
  a cycle, so the number is not happy.

Algorithm:
1. Create an empty unordered_set.
2. While n is not 1:
   - If n is already present in the set, return false.
   - Add n to the set.
   - Replace n with the sum of squares of its digits.
3. Return true when n becomes 1.

Code:
*/
class Solution {
public:

    int sumOfSquares(int n) {

        int sum = 0;

        while (n > 0) {

            int digit = n % 10;

            sum += digit * digit;

            n = n / 10;
        }

        return sum;
    }

    bool isHappy(int n) {

        unordered_set<int> seen;

        while (n != 1) {

            if (seen.find(n) != seen.end()) {
                return false;
            }

            seen.insert(n);

            n = sumOfSquares(n);
        }

        return true;
    }
};



/*
==================================================
Approach 2: Floyd's Cycle Detection
Time: O(log n)
Space: O(1)

Idea:
- The process of repeatedly calculating the sum of
  squares of digits eventually reaches either:
  
  1. 1
  OR
  2. A cycle that does not contain 1.

- Instead of storing visited numbers in a Hash Set,
  use the Slow and Fast Pointer technique.

- slow moves one step at a time.
- fast moves two steps at a time.

- If fast and slow meet at 1, the number is happy.
- If they meet at another number, a cycle exists and
  the number is not happy.

Algorithm:
1. Define a function to calculate the sum of squares
   of the digits.
2. Initialize slow = n.
3. Initialize fast = n.
4. Repeat:
   - Move slow one step.
   - Move fast two steps.
5. Stop when slow == fast.
6. Return true if slow == 1.
7. Otherwise return false.

Code:
*/
class Solution {
public:

    int sumOfSquares(int n) {

        int sum = 0;

        while (n > 0) {

            int digit = n % 10;

            sum += digit * digit;

            n = n / 10;
        }

        return sum;
    }

    bool isHappy(int n) {

        int slow = n;
        int fast = n;

        do {

            slow = sumOfSquares(slow);

            fast = sumOfSquares(sumOfSquares(fast));

        } while (slow != fast);

        return slow == 1;
    }
};



/*
==================================================
Approach 3: Mathematical Observation
Time: O(log n)
Space: O(1)

Idea:
- For any positive integer, repeatedly calculating
  the sum of squares of its digits will eventually
  reduce the number to a small value.
- The process can only:
  
  1. Reach 1
  OR
  2. Enter a known cycle.

- For this problem, every unhappy number eventually
  reaches the cycle:

  4 → 16 → 37 → 58 → 89 → 145 → 42 → 20 → 4

- Therefore, we can repeatedly calculate the sum
  of squares of digits.

- If we reach 1, return true.
- If we reach 4, return false.

Algorithm:

1. While n is not 1 and n is not 4:
   - Calculate the sum of squares of its digits.
   - Assign the result back to n.
2. Return n == 1.

Code:
*/
class Solution {
public:

    int sumOfSquares(int n) {

        int sum = 0;

        while (n > 0) {

            int digit = n % 10;

            sum += digit * digit;

            n = n / 10;
        }

        return sum;
    }

    bool isHappy(int n) {

        while (n != 1 && n != 4) {

            n = sumOfSquares(n);
        }

        return n == 1;
    }
};



/*
==================================================

COMPARISON

Approach 1: Hash Set

- Easy to understand
- Stores previously seen numbers
- Detects the cycle explicitly
- O(log n) extra space
- Good for beginners


Approach 2: Floyd's Cycle Detection

- Uses slow and fast pointers
- No extra data structure
- O(1) extra space
- Detects the cycle without storing values
- More general solution
- Best for interviews


Approach 3: Mathematical Observation

- Uses the known unhappy cycle
- Very short and efficient
- O(1) extra space
- Depends on knowing the specific cycle
- Less general than Floyd's algorithm


BEST APPROACH:

Approach 2: Floyd's Cycle Detection

Why?

- Clean
- O(1) space
- Does not require a Hash Set
- Demonstrates the Slow + Fast Pointer pattern
- Does not depend on hardcoding the unhappy cycle
- Easy to explain in an interview


==================================================

*/