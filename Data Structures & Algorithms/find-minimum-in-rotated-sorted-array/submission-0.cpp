class Solution {
public:
    int findMin(vector<int> &nums) {
        int n= nums.size()-1;
        int low =0, high= n;
        while( low <high){
            int mid = low + (high-low)/2;
            // to right side mai min milega
            if (nums[mid] > nums[high]){ 
                low = mid+1;


            }
            else{  // to left side mai min milega and mid bhi ho sakta hai
                   high = mid;
            }
        }
         return nums[low];
        
       
    }
};
