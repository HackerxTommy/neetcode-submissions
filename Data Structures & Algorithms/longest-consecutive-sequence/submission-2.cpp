class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if ( nums.empty()) return 0;
        int n= nums.size();
         int longest =1;
         int curr=1;
         sort( nums.begin(), nums.end());
         for(int i=0; i<n-1;i++){
            if( nums[i]== nums[i+1]) continue;
            if( nums[i+1]== nums[i]+1){
                curr++;
                

            }
            else{
                curr=1;
            }

        
            longest = max( longest, curr);
            
         }
         return longest;
    
        
    }
};

