class Solution {
public:


   int solve( int i, int j, string &s1, string &s2, vector<vector<int>> &dp){

     //base case
     if ( i < 0 || j <0) return 0;

    //calculated check 
     if ( dp[i][j]!=-1) return  dp[i][j];

     //condition check 
     int take =0, skip=0;
     if ( s1[i] == s2[j]){
     take = 1+ solve( i-1, j-1, s1,s2,dp);
     };
     
        skip = max (solve(i-1, j, s1, s2, dp) ,  solve(i, j-1, s1,s2,dp));

     
     return dp[i][j] = max ( skip, take);

   }
    int longestCommonSubsequence(string s1, string s2) {
    
        int n = s1.size();
        int m = s2.size();

        vector<vector<int>> dp ( n+1, vector<int>(m+1, -1)); 
         return solve( n-1, m-1,s1, s2, dp );
        
    }
};
