#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>

using namespace std;
#include <bits/stdc++.h> 

int solve(int n,vector<int> heights,vector<int> &dp){
    if(n==0){
        return 0;
    }
    if(dp[n]!=-1) return dp[n];
    int left= solve(n-1,heights,dp) + abs(heights[n] -heights[n-1]);
    int right=INT_MAX;
    if(n>1) right=solve(n-2,heights,dp) + abs(heights[n]-heights[n-2]);
    dp[n]=min(left,right);
    return dp[n];
}


int frogJump(int n, vector<int> &heights)
{
vector<int> dp(n,-1);
//n size 0 -> 1 stair 1-> 2 stair etc nth stair -> n+1 stair total n stair (0...n-1)stair based on indexing so n size is sufficeint to store it 
// return solve(n-1,heights,dp);

dp[0]=0;
for(int i=1;i<dp.size();i++){
    int left=dp[i-1]+abs(heights[i] -heights[i-1]);
    int right=INT_MAX;
    if(i>1) right=dp[i-2]+abs(heights[i] -heights[i-2]);
    dp[i]=min(left,right);
}
return dp[n-1];
}