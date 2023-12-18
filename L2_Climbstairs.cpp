#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    //memoization
    int solve(int n,vector<int> &dp){
        if(n==1) return n;
        if(n==0) return 1;
        if(dp[n] !=-1) return dp[n];
        int l=solve(n-1,dp);
        int r=solve(n-2,dp);
        dp[n]=l+r;
        return dp[n];
    }
    
    int climbStairs(int n) {
        vector <int> dp(n+1,-1);
        return solve(n,dp);
        //tabulation (space optimized)
        int prev2=1;
        int prev=1;
        for(int i=2;i<=n;i++){
           int curr=prev+prev2;
           prev2=prev;
           prev=curr;
        }
        // return prev;
    }
};
int main(){
    int n;
    cin>>n;
    Solution a;
    cout<<a.climbStairs(n);

}
