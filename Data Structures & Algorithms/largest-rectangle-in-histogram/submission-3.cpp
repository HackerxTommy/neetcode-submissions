class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        // Number of bars in the histogram
        int n = heights.size();

        // Monotonic Increasing Stack
        // Stores indices, NOT heights.
        // Heights corresponding to these indices are always in increasing order.
        stack<int> st;

        // Stores the maximum rectangle area found so far
        int max_area = 0;

        // Traverse every bar of the histogram
        for (int i = 0; i < n; i++) {

            // If current height is smaller than stack top,
            // then current bar becomes the Next Smaller Element (NSE)
            // for all taller bars in the stack.
            while (!st.empty() && heights[st.top()] > heights[i]) {

                // Bar whose maximum rectangle we're calculating
                int element = st.top();
                st.pop();

                // Current index is the Next Smaller Element
                int nse = i;

                // After popping,
                // stack top becomes Previous Smaller Element.
                // If stack becomes empty, there is no smaller element on left.
                int pse = st.empty() ? -1 : st.top();

                // Width of rectangle =
                // indices between Previous Smaller and Next Smaller
                int width = nse - pse - 1;

                // Area formed using current height
                int area = heights[element] * width;

                // Update answer
                max_area = max(max_area, area);
            }

            // Push current index.
            // Stack always stores indices of increasing heights.
            st.push(i);
        }

        // Process remaining bars in stack.
        // Their Next Smaller Element doesn't exist,
        // so assume NSE = n (outside the array).
        while (!st.empty()) {

            int element = st.top();
            st.pop();

            int nse = n;

            // Previous Smaller Element
            int pse = st.empty() ? -1 : st.top();

            int width = nse - pse - 1;
            int area = heights[element] * width;

            max_area = max(max_area, area);
        }

        // Return largest rectangle area
        return max_area;
    }
};
 