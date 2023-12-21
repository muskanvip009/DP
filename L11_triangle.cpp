#include <iostream>
#include<algorithm>
#include<vector>

using namespace std;



//memoization

class Solution {
public:
    int solve(int i,int j,vector<vector<int>>&dp,vector<vector<int>>triangle){
        if(i == triangle.size()-1){
            return triangle[triangle.size()-1][j];
        }
        if(dp[i][j] != -1) return dp[i][j];
        int down=triangle[i][j] + solve(i+1,j,dp,triangle);
        int diag=triangle[i][j] +solve(i+1,j+1,dp,triangle);
        dp[i][j]=min(down,diag);
        return min(down,diag);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        int m=triangle[0].size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return solve(0,0,dp,triangle); //tle
    }
};



//tabulation
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        int m=triangle[0].size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        for(int j=n-1;j>=0;j--){
            dp[n-1][j]=triangle[n-1][j];
        }

        for(int i=n-2;i>=0;i--){
            for(int j=i;j>=0;j--){
                int down=triangle[i][j] + dp[i+1][j];
                int diag=triangle[i][j] + dp[i+1][j+1];
                dp[i][j]=min(down,diag);
            }
        }
        return dp[0][0];
    }



//space optimization

    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        int m=triangle[0].size();
        // vector<vector<int>> dp(n,vector<int>(n,-1));
        vector<int> prev(n,0);
        // return solve(0,0,dp,triangle); TLE
        
        for(int j=n-1;j>=0;j--){
            prev[j]=triangle[n-1][j];
        }

        for(int i=n-2;i>=0;i--){
            vector <int> curr(n,0);
            for(int j=i;j>=0;j--){
                int down=triangle[i][j] + prev[j];
                int diag=triangle[i][j] + prev[j+1];
                curr[j]=min(down,diag);
            }
            prev=curr;
        }
        return prev[0];
    }




