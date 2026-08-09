class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;

        while (low < high) {
            int mid = low + (high - low) / 2;

            // If nums[mid] > nums[high],
            // mid lies in the left sorted portion.
            // Minimum must be on the right side.
            if (nums[mid] > nums[high]) {
                low = mid + 1;
            }

            // Otherwise, the right half is sorted and
            // the minimum could be at mid or to its left.
            else {
                high = mid;
            }
        }

        // When low == high, only one element remains.
        // That element is the minimum.
        return nums[low];
    }
};