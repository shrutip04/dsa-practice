/*
==================================================

Problem: 92. Reverse Linked List II
LeetCode: Medium
==================================================

Approach 1: Iterative Approach (Dummy Node + Pointer Manipulation)
Time: O(n)
Space: O(1)

Idea:
- We only need to reverse the part of the linked list between
  positions `left` and `right`.
- Use a dummy node before the head.
- Move `prev` to the node just before the `left` position.
- `curr` points to the first node that needs to be reversed.
- Repeatedly take the node after `curr` and move it to the
  front of the reversing section.
- This reverses the required portion without reversing the
  entire linked list.

Example:
Input: 1 → 2 → 3 → 4 → 5
left = 2
right = 4
We need to reverse: 2 → 3 → 4
After reversal: 1 → 4 → 3 → 2 → 5

Important Pointers:
dummy → 1 → 2 → 3 → 4 → 5
         ↑    ↑
        prev curr
`prev` = node before the reversing section.
`curr` = first node of the reversing section.

For every iteration:
1. Store the node after `curr`.
2. Remove that node from its current position.
3. Insert it immediately after `prev`.

Example:
Initial: 1 → 2 → 3 → 4 → 5
Take `3` and move it before `2`: 1 → 3 → 2 → 4 → 5
Take `4` and move it before `3`: 1 → 4 → 3 → 2 → 5

Algorithm:
1. Create a dummy node and connect it to `head`.
2. Set `prev = dummy`.
3. Move `prev` to the node just before position `left`.
4. Set `curr = prev->next`.
5. Repeat `right - left` times:
   - Store `curr->next` in `next`.
   - Remove `next` from its current position.
   - Insert `next` after `prev`.
6. Return `dummy->next`.

Code:
*/
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {

        // If list is empty or no reversal is needed
        if (head == NULL || left == right) {
            return head;
        }

        // Dummy node handles the case where left = 1
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        // Move prev to the node just before left
        ListNode* prev = dummy;

        for (int i = 1; i < left; i++) {
            prev = prev->next;
        }

        // curr is the first node to be reversed
        ListNode* curr = prev->next;

        // Reverse the required portion
        for (int i = 0; i < right - left; i++) {

            // Store the node after curr
            ListNode* next = curr->next;

            // Remove next from its current position
            curr->next = next->next;

            // Insert next immediately after prev
            next->next = prev->next;
            prev->next = next;
        }

        // dummy->next is the new head
        return dummy->next;
    }
};



/*
==================================================
Approach 2: Iterative Approach (Three-Pointer Reversal)
Time: O(n)
Space: O(1)

Idea:
- First reach the `left` position.
- Then reverse the sublist using the standard
  three-pointer technique:
    1. prev
    2. curr
    3. next
- After reversing the sublist, reconnect it with the
  remaining part of the linked list.

Example:
1 → 2 → 3 → 4 → 5
left = 2
right = 4
Before reversal:
1 → 2 → 3 → 4 → 5
    ↑
   curr

Reverse: 2 → 3 → 4

Result: 1 → 4 → 3 → 2 → 5

Algorithm:
1. Create a dummy node before `head`.
2. Move `beforeLeft` to the node before `left`.
3. Set `start` to the node at position `left`.
4. Set `prev = NULL` and `curr = start`.
5. Reverse nodes until position `right`.
6. Connect the reversed portion back to the list.
7. Return `dummy->next`.

Code:
*/
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {

        if (head == NULL || left == right) {
            return head;
        }

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        // Find the node before left
        ListNode* beforeLeft = dummy;

        for (int i = 1; i < left; i++) {
            beforeLeft = beforeLeft->next;
        }

        // Start of the section to reverse
        ListNode* start = beforeLeft->next;

        // Reverse the sublist
        ListNode* prev = NULL;
        ListNode* curr = start;

        for (int i = left; i <= right; i++) {

            ListNode* next = curr->next;

            curr->next = prev;

            prev = curr;
            curr = next;
        }

        // Connect the first part with reversed part
        beforeLeft->next = prev;

        // start is now the last node of reversed section
        start->next = curr;

        return dummy->next;
    }
};



/*
==================================================

Approach 3: Using an Array / Vector
Time: O(n)
Space: O(n)

Idea:
- Store the values of the linked list in a vector.
- Reverse the values between positions `left` and `right`.
- Copy the modified values back into the linked list.
- The linked-list structure itself is not changed.

Example:
Linked List: 1 → 2 → 3 → 4 → 5
Vector: [1, 2, 3, 4, 5]
Reverse positions 2 to 4: [1, 4, 3, 2, 5]
Copy values back: 1 → 4 → 3 → 2 → 5
This approach is simple but uses extra memory and does not
actually reverse the links between nodes.

Algorithm:
1. Traverse the linked list and store all values in a vector.
2. Reverse the vector elements from index `left - 1`
   to `right - 1`.
3. Traverse the linked list again.
4. Replace each node's value with the corresponding
   vector value.
5. Return `head`.

Code:
*/
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {

        vector<int> values;

        // Store all node values
        ListNode* curr = head;

        while (curr != NULL) {
            values.push_back(curr->val);
            curr = curr->next;
        }

        // Reverse required portion
        reverse(values.begin() + left - 1,
                values.begin() + right);

        // Copy values back
        curr = head;
        int i = 0;

        while (curr != NULL) {
            curr->val = values[i];
            curr = curr->next;
            i++;
        }

        return head;
    }
};



/*
==================================================

COMPARISON

Approach 1: Dummy Node + Pointer Manipulation

- Time: O(n)
- Space: O(1)
- Directly changes the linked-list connections.
- No extra data structure required.
- Efficient and commonly used.
- Handles `left = 1` easily using a dummy node.

Approach 2: Three-Pointer Reversal

- Time: O(n)
- Space: O(1)
- Uses the standard linked-list reversal technique.
- Easy to connect with the normal Reverse Linked List problem.
- Slightly more complicated reconnection logic.

Approach 3: Array / Vector

- Time: O(n)
- Space: O(n)
- Very easy to understand.
- Stores all node values in extra memory.
- Does not actually reverse the node links.
- Not preferred when the problem expects linked-list manipulation.


BEST APPROACH:

Approach 1: Dummy Node + Pointer Manipulation

Why?

- O(n) time.
- O(1) extra space.
- Directly modifies the linked-list pointers.
- Very clean once the pointer movement is understood.
- Handles the important edge case `left = 1`.
- This is an excellent interview approach for this problem.

==================================================

*/