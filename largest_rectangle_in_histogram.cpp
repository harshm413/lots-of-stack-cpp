#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;  // Stack to store indices of the histogram bars
        int maxArea = 0;  // Variable to store the maximum area
        int n = heights.size();

        // Traverse each bar in the histogram
        for (int i = 0; i < n; ++i) {
            // While the stack is not empty and the current bar height is less than the bar at the top of the stack
            while (!st.empty() && heights[st.top()] > heights[i]) {
                int height = heights[st.top()];  // The height of the rectangle
                st.pop();  // Pop the top index from the stack
                int width = st.empty() ? i : i - st.top() - 1;  // Width of the rectangle
                maxArea = max(maxArea, height * width);  // Update the maximum area
            }
            st.push(i);  // Push the current index onto the stack
        }

        // After processing all bars, we may still have bars in the stack
        while (!st.empty()) {
            int height = heights[st.top()];  // The height of the rectangle
            st.pop();  // Pop the top index from the stack
            int width = st.empty() ? n : n - st.top() - 1;  // Width of the rectangle
            maxArea = max(maxArea, height * width);  // Update the maximum area
        }

        return maxArea;
    }
};

int main() {
    Solution solution;

    vector<int> heights1 = {2, 1, 5, 6, 2, 3};
    cout << "Max Area: " << solution.largestRectangleArea(heights1) << endl;  // Output: 10

    vector<int> heights2 = {2, 4};
    cout << "Max Area: " << solution.largestRectangleArea(heights2) << endl;  // Output: 4

    vector<int> heights3 = {1};
    cout << "Max Area: " << solution.largestRectangleArea(heights3) << endl;  // Output: 1

    return 0;
}
