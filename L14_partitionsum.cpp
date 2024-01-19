#include <iostream>
#include<algorithm>
#include<vector>
#include<bits/stdc++.h>

using namespace std;

//Memoization 
class Solution {
public:
    int f(int ind,int target,vector<int>arr,vector<vector<int>>&dp){
        if(target==0) return true;
        if(ind==0) return arr[ind]==target;

        if(dp[ind][target]!=-1) return dp[ind][target];
        int notake=f(ind-1,target,arr,dp);
        int take=false;
        if(target>=arr[ind]){
            take=f(ind-1,target-arr[ind],arr,dp);
        }
        dp[ind][target]=take|notake;
        return dp[ind][target];
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(sum%2!=0) return false;  
        vector<vector<int>>dp(n,vector<int>((sum/2)+1,-1));

        return f(n-1,sum/2,nums,dp);   
    }
};


//Tabulation 

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(sum%2!=0) return false;  
        vector<vector<bool>>dp(n,vector<bool>((sum/2)+1,false));
        
        
        for(int i=0;i<n;i++) dp[i][0]=true;  //target
        if(nums[0]<=sum/2) dp[0][nums[0]]=true;        

        for(int i=1;i<n;i++){
            for(int j=1;j<=sum/2;j++){
                int notake=dp[i-1][j];
                int take=false;
                if(j>=nums[i]){
                    take=dp[i-1][j-nums[i]];
                }
                dp[i][j]=take|notake;
            }
        }
        return dp[n-1][sum/2];   
    }
};


