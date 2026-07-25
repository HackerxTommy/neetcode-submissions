class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left =0, right = heights.size()-1, max_area=0;
        while( left <= right ){
             int area= min(heights[left], heights[right]) * (right-left); // area = min(height) * width
             max_area= max(area, max_area);
             if(heights[left]< heights[right]){
                left++;
             }
             else{
                right--;
             }

        }
        return max_area;
    }
};