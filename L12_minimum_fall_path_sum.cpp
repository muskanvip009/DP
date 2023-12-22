#include <iostream>
#include<algorithm>
#include<vector>
#include<bits/stdc++.h>

using namespace std;



class Solution {
public:
    int solve(int i,int j,vector<vector<int>>&dp,vector<vector<int>>& matrix){
        int n=matrix.size();
        int m=matrix[0].size();
        
        if(j<0 || j==n) return INT_MAX;
        if(i==n-1) return matrix[i][j];
        if(dp[i][j] != -1 ) return dp[i][j];

        int l=solve(i+1,j-1,dp,matrix);
        int c=solve(i+1,j,dp,matrix);
        int r=solve(i+1,j+1,dp,matrix);
        return dp[i][j]=matrix[i][j] + min(l,min(c,r));

    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();

        vector<vector<int>>dp(n,vector<int>(n,-1));
        int mini=INT_MAX; 
        for(int i=0;i<n;i++){
            int val=solve(0,i,dp,matrix);
            mini=min(val,mini);                                                  
        }

    }
};



//TABULATION 
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();

        vector<vector<int>>dp(n,vector<int>(n,-1));
        int mini=INT_MAX; 
    
        //copying the first row of the matrix the dp matrix as base case
        dp[0]=matrix[0];

        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                int l=1e9,c=1e9,r=1e9;
                if(j>0) l=dp[i-1][j-1];
                c=dp[i-1][j];
                if(j+1<n) r=dp[i-1][j+1];
                dp[i][j]=matrix[i][j] +min(l,min(c,r));
            }
        }

        for(int i=0;i<n;i++){
            mini=min(mini,dp[n-1][i]);
        }
        return mini;



    }
};