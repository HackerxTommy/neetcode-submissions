class Solution {
public:

   int ispalindrome( int i, int j, string &s, vector<vector<int>> &dp){

    //bc
    if ( i>=j) return 1;
    //calculated check
    if ( dp[i][j]!=-1) return dp[i][j];
    //condition check
    if ( s[i] == s[j]){
        return dp[i][j]= ispalindrome( i+1, j-1, s,dp);
    }
    else{
        return dp[i][j] =0;
    }

   }

    string longestPalindrome(string s) {
        int n = s.size();
        if ( n<=1) return s;
        vector<vector<int>> dp ( n, vector<int>(n,-1));
        int start =0, max_length =1;
        for ( int i=0; i<n;i++){
            for ( int j=i; j<n;j++){
                if ( ispalindrome( i,j,s,dp)){
                    int len= j-i+1;
                    if  ( len > max_length){
                          max_length = len;
                         start =i;
                    }
                }
            }
        }
        return s.substr(start, max_length);
        
    }
};
