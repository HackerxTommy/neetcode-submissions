class Solution {
public:
    int search(vector<int>& nums, int target) {
        //sorted array mai do half bante hain 
        // in rotated sorted array either left half is sorted or right half is sorted must 
        int low = 0, high = nums.size()-1;
        while(low <=high){
            int mid = low + (high-low)/2;
            if (nums[mid]== target) return mid; //mil gaya 

            // left part is sorted 
            if ( nums[low]<= nums[mid]){ // matlab left part sorted 
                if (nums[low]<= target && target< nums[mid] ){
              
                     high = mid-1; 
            }
                else{
                low = mid+1;
            }
            }

            // right half is sorted 
            else{
             if ( target > nums[mid] && target <= nums[high]){
              
                low = mid +1;
             }
             else{
                high = mid -1;
             }
            }
            
        }
        
        return -1;

    }
};
