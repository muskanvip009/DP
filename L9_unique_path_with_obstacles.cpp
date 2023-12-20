#include <iostream>
#include<algorithm>
#include<vector>

using namespace std;




// MEMOIZATION 
class Solution {
public:
    int solve(int i,int j,vector<vector<int>> &dp,vector<vector<int>> &mat){
        if(i>=0 && j>=0 && mat[i][j]==-1){
            return 0;
        }
        if(i==0 && j==0){
            return 1;
        }
        if(i<0 || j<0){
            return 0;
        }
        if(dp[i][j] !=-1){
            return dp[i][j];
        }

        int up=solve(i-1,j,dp,mat);
        int left=solve(i,j-1,dp,mat);

        dp[i][j]=up+left;
        return up+left;
    }
    int uniquePaths(int m, int n,vector<vector<int>> &mat) {
       vector<vector<int>> dp(m,vector<int>(n,-1));
       return solve(m-1,n-1,dp,mat);        
          
    }

};

//TABULATION 

    int uniquePaths(int m, int n,vector<vector<int>> &mat) {
       vector<vector<int>> dp(m,vector<int>(n,-1));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==-1){
                    dp[i][j]=0;
                }
                else if(i==0 && j==0){
                   dp[i][j]=1;
                }
                else{
                int up=0;
                int left=0;
                if(i>0)  up=dp[i-1][j];
                if(j>0)  left=dp[i][j-1];
                dp[i][j]=up+left;
                }
            } 
       }
       return dp[m-1][n-1];              
    }

// space optimization
    int uniquePaths(int m, int n,vector<vector<int>>mat) {
       vector<int> prev(n,0);
        for(int i=0;i<m;i++){
            vector<int> curr(n,0);
            for(int j=0;j<n;j++){
                if(mat[i][j]==-1){
                    curr[j]=0;
                }
                else if(i==0 && j==0){
                   curr[j]=1;
                }
                else{
                int up=0;
                int left=0;
                if(i>0)  up=prev[j];
                if(j>0)  left=curr[j-1];
                curr[j]=up+left;
                }
            } 
            prev=curr;
       }
       return prev[n-1];              
    }


