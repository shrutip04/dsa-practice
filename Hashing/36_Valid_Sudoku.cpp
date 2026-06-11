/*
==================================================
Problem: 36. Valid Sudoku
LeetCode: Medium

Approach: Hash Set Tracking

Time Complexity: O(81) ≈ O(1)
Space Complexity: O(81) ≈ O(1)

Learning:

- The problem does NOT ask us to solve the
  Sudoku board.

- We only need to verify whether the current
  board configuration follows Sudoku rules.

- A valid Sudoku must satisfy:

  1. No duplicate digit in any row.
  2. No duplicate digit in any column.
  3. No duplicate digit in any 3x3 box.

- Empty cells are represented by '.'
  and should be ignored.

--------------------------------------------------

Brute Force Idea:

For every non-empty cell:

1. Check the entire row.
2. Check the entire column.
3. Check the entire 3x3 box.

If a duplicate is found,
the board is invalid.

This works but repeatedly scans the
same rows, columns and boxes.

--------------------------------------------------

Key Observation:

Instead of repeatedly checking whether a
number already exists, we can remember
what we have already seen.

This converts the problem into a
"Duplicate Detection" problem.

Whenever we encounter a digit:

- If it already exists in the current row
  -> Invalid

- If it already exists in the current column
  -> Invalid

- If it already exists in the current box
  -> Invalid

Otherwise store it for future checks.

--------------------------------------------------

Data Structures:

set<char> rows[9];
set<char> cols[9];
set<char> boxes[9];

Meaning:

rows[i]
-> Stores all digits already seen in row i

cols[j]
-> Stores all digits already seen in column j

boxes[k]
-> Stores all digits already seen in box k

--------------------------------------------------

Finding the Box Number:

Sudoku contains 9 boxes.

Box Layout:

0 0 0 | 1 1 1 | 2 2 2
0 0 0 | 1 1 1 | 2 2 2
0 0 0 | 1 1 1 | 2 2 2
---------------------
3 3 3 | 4 4 4 | 5 5 5
3 3 3 | 4 4 4 | 5 5 5
3 3 3 | 4 4 4 | 5 5 5
---------------------
6 6 6 | 7 7 7 | 8 8 8
6 6 6 | 7 7 7 | 8 8 8
6 6 6 | 7 7 7 | 8 8 8

Formula:

box = (i / 3) * 3 + (j / 3)

Example:

Cell (1,2)

box = (1/3)*3 + (2/3)
     = 0

Top-left box

--------------------------------------------------

Algorithm:

Traverse every cell.

If current cell is '.'
-> Skip

Otherwise:

1. Find box number.
2. Check if digit already exists in:
      - row
      - column
      - box

3. If found anywhere:
      return false

4. Otherwise insert digit into:
      - row set
      - column set
      - box set

If traversal finishes without duplicates:

return true

--------------------------------------------------

Example:

Board:

5 3 . . 7 . . . .
6 . . 1 9 5 . . .
. 9 8 . . . . 6 .
8 . . . 6 . . . 3
4 . . 8 . 3 . . 1
7 . . . 2 . . . 6
. 6 . . . . 2 8 .
. . . 4 1 9 . . 5
. . . . 8 . . 7 9

--------------------------------------------------

Process First Row:

5

Row 0 does not contain 5
Column 0 does not contain 5
Box 0 does not contain 5

Insert 5

--------------------------------------------------

3

Row 0 does not contain 3
Column 1 does not contain 3
Box 0 does not contain 3

Insert 3

--------------------------------------------------

Suppose another 5 appears in Row 0:

5 3 . . 7 . . . 5

Check:

rows[0].count('5')

Returns true

Duplicate found

return false

--------------------------------------------------

Pattern:

- Hashing
- Hash Set
- Duplicate Detection
- State Tracking
- Matrix Traversal

Related Problems:

- Contains Duplicate
- Valid Anagram
- Happy Number
- Group Anagrams
- Top K Frequent Elements
- Longest Consecutive Sequence

Interview Takeaway:

Whenever a problem asks:

"Have I seen this before?"

Think:

Hash Set / Hash Map

==================================================
*/


class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        set<char> rows[9];
        set<char> cols[9];
        set<char> boxes[9];

        for(int i = 0; i < 9; i++) {

            for(int j = 0; j < 9; j++) {

                char num = board[i][j];

                if(num == '.')
                    continue;

                int box = (i / 3) * 3 + (j / 3);

                if(rows[i].count(num))
                    return false;

                if(cols[j].count(num))
                    return false;

                if(boxes[box].count(num))
                    return false;

                rows[i].insert(num);
                cols[j].insert(num);
                boxes[box].insert(num);
            }
        }

        return true;
    }
};