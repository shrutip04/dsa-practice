/*
==================================================

Problem: 141. Linked List Cycle

LeetCode: Easy

==================================================


==================================================

Approach 1: Hash Set

Time: O(n)
Space: O(n)

Idea:
- Traverse the linked list.
- Store every visited node in a hash set.
- Before visiting a node, check if it is already
  present in the set.
- If it is already present, a cycle exists.
- If we reach NULL, there is no cycle.

Important:

- Store the node pointer, not node->val.
- Two different nodes can have the same value.

Algorithm:

1. Create an empty unordered_set of ListNode pointers.
2. Start from head.
3. While current is not NULL:
   - If current is already in the set, return true.
   - Insert current into the set.
   - Move current to current->next.
4. Return false.

Code:
*/
class Solution {
public:
    bool hasCycle(ListNode *head) {

        unordered_set<ListNode*> visited;

        ListNode* current = head;

        while (current != NULL) {

            if (visited.find(current) != visited.end()) {
                return true;
            }

            visited.insert(current);

            current = current->next;
        }

        return false;
    }
};



/*
==================================================

Approach 2: Floyd's Cycle Detection

Time: O(n)
Space: O(1)

Idea:

- Use two pointers: slow and fast.
- slow moves one node at a time.
- fast moves two nodes at a time.
- If there is a cycle, fast will eventually meet slow.
- If there is no cycle, fast will reach NULL.

Algorithm:

1. Initialize slow = head.
2. Initialize fast = head.
3. While fast != NULL and fast->next != NULL:
   - Move slow one step.
   - Move fast two steps.
   - If slow == fast, return true.
4. Return false.

Code:
*/
class Solution {
public:
    bool hasCycle(ListNode *head) {

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL && fast->next != NULL) {

            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                return true;
            }
        }

        return false;
    }
};



/*
==================================================

Approach 3: Mark Visited Nodes
Time: O(n)
Space: O(1)

Idea:
- Traverse the linked list.
- Mark each visited node by modifying its pointer
  or some part of the node.
- If we encounter an already marked node, there
  is a cycle.

However, this approach modifies the original
linked list.
Because of this, it is generally NOT recommended
for LeetCode or interviews unless modification
of the linked list is explicitly allowed.

Algorithm:
1. Traverse the linked list.
2. Mark each visited node.
3. If a marked node is encountered again,
   return true.
4. If NULL is reached, return false.

Code:
// Not recommended because it modifies the
// original linked list structure.
*/
class Solution {
public:
    bool hasCycle(ListNode *head) {

        ListNode* current = head;

        while (current != NULL) {

            // Modification of the node would be
            // required to mark it as visited.

            current = current->next;
        }

        return false;
    }
};



/*
==================================================

COMPARISON

Approach 1: Hash Set

- Easy to understand
- Stores visited nodes
- O(n) extra space
- Does not modify the linked list


Approach 2: Floyd's Cycle Detection

- Uses slow and fast pointers
- No extra data structure
- O(1) extra space
- Does not modify the linked list
- Best for interviews
- Satisfies the follow-up requirement


Approach 3: Mark Visited Nodes

- Uses O(1) extra space
- Modifies the original linked list
- Not recommended
- Can destroy the original list structure


BEST APPROACH:

Approach 2: Floyd's Cycle Detection

Why?

- Clean
- Easy to explain once understood
- Does not modify the linked list
- O(n) time
- O(1) space
- Satisfies the follow-up question


==================================================

*/