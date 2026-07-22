class Solution {
public:
    int ispalindrome(int i,int j, string &s, vector<vector<int>>&dp){

       //base case 
       if ( i>=j) return true; //single character or empty strings are palindrome

        //calculated check 
        if (dp[i][j]!=-1) return dp[i][j];

        //condition check
        if (s[i]==s[j]){
              return dp[i][j]= ispalindrome(i+1,j-1,s,dp);
            
        }
             return dp[i][j] = false;
        
    
    }
    
    int countSubstrings(string s) {
        int n= s.size();
        int count =0;
       
        vector<vector<int>>dp(n,vector<int>(n,-1));
        for (int i=0;i<n;i++){ //for all substrings check
            for (int j=i;j<n;j++){
                if (ispalindrome (i,j,s,dp)){
                 count++;
                }

            }
        }
         return count;
    }
   
};
