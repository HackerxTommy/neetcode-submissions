class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int max_area =0;
        for ( int i=0; i<n; i++){

         while( !st.empty() && heights[st.top()]> heights[i]){
            int element = st.top();
            st.pop();
            int nse= i;
            int pse = st.empty() ?-1: st.top();
             max_area = max( max_area, heights[element] * ( nse-pse-1));
            
         }
         st.push(i);
        }
         while( !st.empty()){
            int element =st.top();
            st.pop();
            int  nse = n;
            int  pse = st.empty() ? -1: st.top();
            max_area = max( max_area, heights[element]*(nse-pse-1));

         }

        
        return max_area;
        
    }
};
 