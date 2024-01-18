#include <iostream>
#include<algorithm>
#include<vector>
#include<bits/stdc++.h>

using namespace std;


// Tabulation 
class Solution{   
public:

    bool f(int ind,int target,vector<int>arr,vector<vector<int>>&dp){
        if(target==0) return true;
        if(ind==0) return arr[ind]==target;
        if(dp[ind][target]!=-1) return dp[ind][target];
        
        bool nopick=f(ind-1,target,arr,dp);
        bool pick=false;
        if(target>=arr[ind]){
            pick=f(ind-1,target-arr[ind],arr,dp);
        }
        
        dp[ind][target]=nopick | pick;
        return nopick | pick;
        
    }

    bool isSubsetSum(vector<int>arr, int sum){
        // n*m n=arr.size() (0 to ind-1) m=target
        vector<vector<int>>dp(arr.size(),vector<int>(sum+1,-1));
        for(int i = 0; i < arr.size(); i++) {
            dp[i][0] = 1;
        }
        
        return f(arr.size()-1,sum,arr,dp);
    }
};

// Memoization

   bool isSubsetSum(vector<int>arr, int sum){
        // n*m n=arr.size() (0 to ind-1) m=target+1(target=0 col included)
        vector<vector<bool>>dp(arr.size(),vector<bool>(sum+1,false));
        for(int i = 0; i < arr.size(); i++) {
            dp[i][0] = true;
        }
        if(arr[0]<=sum){
        dp[0][arr[0]]=true;
        }
        for(int i=1;i<arr.size();i++){
            for(int j=1;j<=sum;j++){
                bool nopick=dp[i-1][j];
                bool pick=false;
                if(j>=arr[i]){
                    pick=dp[i-1][j-arr[i]];
                }
                dp[i][j]=nopick | pick;
            }
        }
        
        return dp[arr.size()-1][sum];
    }


