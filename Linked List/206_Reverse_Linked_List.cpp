/*
==================================================
Problem: 206. Reverse Linked List
LeetCode: Easy
==================================================
Approach 1: Iterative Approach (Three Pointers)
Time: O(n)
Space: O(1)

Idea:
- We reverse the `next` pointer of every node.
- We use three pointers:
    1. prev  → previous node
    2. curr  → current node
    3. next  → stores the next node before changing the link
- We move through the list one node at a time.
- Finally, `prev` becomes the new head.

Example:
Original: 1 → 2 → 3 → 4 → 5 → NULL
After reversing: 5 → 4 → 3 → 2 → 1 → NULL

Important:
Before changing: curr → next
We first save: next = curr->next
Then reverse: curr->next = prev
Then move forward: prev = curr
                   curr = next

Algorithm:
1. Set `prev = NULL`.
2. Set `curr = head`.
3. While `curr != NULL`:
   - Store the next node in `next`.
   - Reverse the current node's pointer.
   - Move `prev` to `curr`.
   - Move `curr` to `next`.
4. Return `prev`.

Code:
*/
class Solution {
public:
    ListNode* reverseList(ListNode* head) {

        ListNode* prev = NULL;
        ListNode* curr = head;

        while (curr != NULL) {

            // Save the next node
            ListNode* next = curr->next;

            // Reverse the pointer
            curr->next = prev;

            // Move prev forward
            prev = curr;

            // Move curr forward
            curr = next;
        }

        // prev is the new head
        return prev;
    }
};



/*
==================================================

Approach 2: Recursive Approach
Time: O(n)
Space: O(n)

Idea:
- Recursively reverse the rest of the linked list first.
- Once we reach the last node, that node becomes the new head.
- Then we reverse the connection between the current node and the next node.

Example:
1 → 2 → 3 → 4 → 5 → NULL
Recursion goes to:
1 → 2 → 3 → 4 → 5
                ↑
              new head
Then while returning:
5 → 4
5 → 4 → 3
5 → 4 → 3 → 2
5 → 4 → 3 → 2 → 1
The important two lines are:
head->next->next = head;
This makes:
2 → 1
instead of:
1 → 2
Then:
head->next = NULL;
This prevents the old connection from creating a cycle.

Algorithm:
1. If the list is empty or has only one node, return `head`.
2. Recursively reverse the list starting from `head->next`.
3. Reverse the connection:
   `head->next->next = head`.
4. Set:
   `head->next = NULL`.
5. Return the new head.

Code:
*/
class Solution {
public:
    ListNode* reverseList(ListNode* head) {

        // Base case
        if (head == NULL || head->next == NULL) {
            return head;
        }

        // Reverse the remaining list
        ListNode* newHead = reverseList(head->next);

        // Reverse the connection
        head->next->next = head;

        // Remove old connection
        head->next = NULL;

        return newHead;
    }
};



/*
==================================================

Approach 3: Iterative Approach Using a Dummy Node
Time: O(n)
Space: O(1)
Idea:
- We can build the reversed list by taking one node at a time
  from the original list.
- `prev` represents the already reversed portion.
- Each current node is inserted at the beginning of the reversed portion.

Example:
Original: 1 → 2 → 3 → NULL
Step 1: prev = NULL
        curr = 1
Reverse: 1 → NULL
Step 2: 2 → 1 → NULL
Step 3: 3 → 2 → 1 → NULL

Algorithm:
1. Set `prev = NULL`.
2. Start from `curr = head`.
3. Save `curr->next`.
4. Point `curr->next` to `prev`.
5. Move `prev` to `curr`.
6. Move `curr` to the saved next node.
7. Continue until `curr == NULL`.
8. Return `prev`.

Code:
*/
class Solution {
public:
    ListNode* reverseList(ListNode* head) {

        ListNode* prev = NULL;

        while (head != NULL) {

            ListNode* next = head->next;

            head->next = prev;

            prev = head;

            head = next;
        }

        return prev;
    }
};



/*
==================================================

COMPARISON

Approach 1: Iterative Approach (Three Pointers)

- Time: O(n)
- Space: O(1)
- Uses `prev`, `curr`, and `next`.
- Easy to understand once pointer movement is clear.
- No recursion overhead.

Approach 2: Recursive Approach

- Time: O(n)
- Space: O(n)
- Uses recursion.
- Very elegant and follows the natural structure of a linked list.
- Uses call stack memory.

Approach 3: Iterative Approach Using a Dummy Node

- Time: O(n)
- Space: O(1)
- Also reverses the list iteratively.
- Similar logic to Approach 1.
- The separate `next` pointer is still required to avoid losing the rest of the list.


BEST APPROACH:

Approach 1: Iterative Approach (Three Pointers)

Why?

- O(n) time.
- O(1) extra space.
- No recursion.
- Works efficiently even for large linked lists.
- This is the standard interview solution.
- The three-pointer technique is an important linked-list pattern.

==================================================

*/