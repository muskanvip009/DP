#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    
    int f(int index,vector<int> nums,vector<int> & dp){
        if(index==0) return nums[index];
        if(index<0) return 0;
        if(dp[index] != -1) return dp[index];
        int take=nums[index] + f(index-2,nums,dp);
        int notake=0 + f(index-1,nums,dp);
        dp[index]=max(take,notake);
        return dp[index];
    }
    
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return f(nums.size()-1,nums,dp);
        
    }
};