/*Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, 
return the area of the largest rectangle in the histogram.*/

// Solution :- 

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int maxArea = 0;

        for (int i = 0; i <= n; ++i) {
            // Use 0 height at the end (i == n) to flush out remaining items in stack
            int currentHeight = (i == n) ? 0 : heights[i];

            while (!st.empty() && currentHeight < heights[st.top()]) {
                int h = heights[st.top()];
                st.pop();

                // If stack is empty, it means the popped height extends all the way to index 0
                int width = st.empty() ? i : (i - st.top() - 1);
                
                maxArea = max(maxArea, h * width);
            }

            st.push(i);
        }

        return maxArea;
    }
};
