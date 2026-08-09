class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size()-1, lmax=0, rmax=0, water=0;
        while( left<right){
            if ( height[left]< height[right]){
                //left side chalenge 
               lmax = max(lmax, height[left]); // updating max left height
               water += lmax - height[left];
               left ++;
            }
            
            else{
               rmax = max(rmax, height[right]); // updating max right height
               water += rmax - height[right];
               right --;
            }
        }
        return water;
    }
};
