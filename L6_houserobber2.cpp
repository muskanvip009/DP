#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>

using namespace std;
class Solution {
public:
    
    int f(int index,vector<int> nums,vector<int> & dp,int end){
        if(index==0 && end==1){
            return nums[index];
        }
        if(index==0 && end==0){
            return 0;
        }
        
        if(index<0) return 0;
        if(dp[index] != -1) return dp[index];
        int take=nums[index] + f(index-2,nums,dp,end);
        int notake=0 + f(index-1,nums,dp,end);
        dp[index]=max(take,notake);
        return dp[index];
    }

    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        
        if(nums.size()==1) return nums[0];
        int ans1= f(nums.size()-1,nums,dp,0);
        
        vector<int> dp2(nums.size(),-1);
        int ans2=f(nums.size()-2,nums,dp2,1);
        cout<<ans1<<" "<<ans2;
        return max(ans1,ans2);
    }
};