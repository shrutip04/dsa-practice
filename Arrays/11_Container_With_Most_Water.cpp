/*
==================================================

Problem: 11. Container With Most Water
LeetCode: Medium

Approach 1: Brute Force
Time: O(n²)
Space: O(1)

-Try every possible pair of vertical lines.
-For every pair of indices i and j, calculate the
area of water that can be stored between them.
-Width = j - i
-Height = min(height[i], height[j])
-Area = width * height
-Store the maximum area found.

ALGORITHM:
1.Pick the first line i.
2.Pick every possible line j after i.
3.Calculate:
    width = j - i
    containerHeight = min(height[i], height[j])
    area = width * containerHeight
4.Update maxArea.
5.Return maxArea.

Problem:
O(n²) is too slow when n can be 10^5.
Therefore, we use the Two Pointer approach.

--------------------------------------------------

Approach 2: Two Pointers (Optimal)
Time: O(n)
Space: O(1)

-Idea:
Start with two pointers:
    left = 0
    right = n - 1

-This gives us the maximum possible width.
-For every pair of pointers, calculate:
    area = (right - left)
           * min(height[left], height[right])
-Update the maximum area.
-Key Observation:
The amount of water is limited by the SHORTER line.
Therefore:
    height = min(height[left], height[right])
-Always move the pointer pointing to the shorter
line.

-Why?
Suppose:
    height[left] < height[right]
The current container is limited by height[left].
If we move right:
    width decreases
    height[left] still limits the container
So we cannot get a better container by keeping the
shorter left line.
Instead, move left and look for a taller line.

Therefore:
    If height[left] < height[right]:
        left++
    Else:
        right--
-Continue until left >= right.

ALGORITHM:
1.Initialize:
    left = 0
    right = n - 1
    maxArea = 0
2.While left < right:
    a.Calculate width:
        width = right - left
    b.Calculate container height:
        min(height[left], height[right])
    c.Calculate area:
        area = width * containerHeight
    d.Update maxArea.
    e.Move the pointer with the smaller height:
        If height[left] < height[right]:
            left++
        Else:
            right--
3.Return maxArea.

EXAMPLE:

height = [1,8,6,2,5,4,8,3,7]
Initially:
left = 0
right = 8
height[left] = 1
height[right] = 7
width = 8
height = min(1,7) = 1
area = 8 * 1 = 8
Since the left line is shorter:
left++

Now:
left = 1
right = 8
height[left] = 8
height[right] = 7
width = 7
height = min(8,7) = 7
area = 7 * 7 = 49
maxArea = 49
Continue moving the shorter pointer.
Final answer = 49

IMPORTANT:

The shorter line determines the height of the
container.
Therefore, always move the pointer with the
smaller height.

==================================================
*/

// ---------- Approach 1 : Brute Force ----------

class Solution1 {
public:
    int maxArea(vector<int>& height) {

        int maxArea = 0;
        int n = height.size();

        for(int i = 0; i < n; i++) {

            for(int j = i + 1; j < n; j++) {

                int width = j - i;

                int containerHeight =
                min(height[i], height[j]);

                int area =
                width * containerHeight;

                maxArea =
                max(maxArea, area);
            }
        }

        return maxArea;
    }
};

// ---------- Approach 2 : Two Pointers (Optimal) ----------

class Solution {
public:
    int maxArea(vector<int>& height) {

        int left = 0;
        int right = height.size() - 1;

        int maxArea = 0;

        while(left < right) {

            int width = right - left;

            int containerHeight =
            min(height[left], height[right]);

            int area =
            width * containerHeight;

            maxArea =
            max(maxArea, area);

            // Move the shorter line
            if(height[left] < height[right]) {
                left++;
            }
            else {
                right--;
            }
        }

        return maxArea;
    }
};

