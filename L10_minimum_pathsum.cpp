#include <iostream>
#include<algorithm>
#include<vector>

using namespace std;


class Solution {
public:
    //memoization
    int solve(int i,int j,vector<vector<int>>&dp,vector<vector<int>>& grid){
        
        if(i==0 && j==0) return grid[i][j];
        if(i<0 || j<0 ) return 1e9;
        if(dp[i][j] !=-1) return dp[i][j];

        int up=solve(i-1,j,dp,grid)+grid[i][j];
        int left=solve(i,j-1,dp,grid)+grid[i][j];

        dp[i][j]=min(up,left);

        return dp[i][j];
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));

        // return solve(m-1,n-1,dp,grid);
        
        //tabulation 
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0){
                    dp[i][j]=grid[0][0];
                }
                else{
                int u=1e9;
                int l=1e9;
                if(i>0) u= dp[i-1][j] + grid[i][j];
                if(j>0) l=dp[i][j-1] +grid[i][j];
                dp[i][j]=min(u,l);
                }
            }
        }
        return dp[m-1][n-1];

    }
};