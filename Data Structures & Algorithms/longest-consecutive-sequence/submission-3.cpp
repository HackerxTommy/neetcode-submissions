class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if ( nums.empty()) return 0;
        int n= nums.size();
         int longest =1;
         int curr=1;
         sort( nums.begin(), nums.end()); // sabse pahle sort karo
         for(int i=0; i<n-1;i++){
            if( nums[i]== nums[i+1]) continue;   // agar  same hain dono 
            if( nums[i+1]== nums[i]+1){          // agar difference 1 hai dono mai
                curr++;

            }
            else{
                curr=1;
            }

        
            longest = max( longest, curr);     // length of longest common sequence
            
         }
         return longest;
    
        
    }
};

