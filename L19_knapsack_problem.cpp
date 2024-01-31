//{ Driver Code Starts
#include <iostream>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <bits/stdc++.h>
#include <string.h>
#include <bits/stdc++.h>
using namespace std;



int f(int index,int w,vector<int>wt,vector<int>val,vector<vector<int>>&dp){
    //base case
    if(index==0){
        if(wt[0]<=w) return val[0];
        else return 0;
    }

    //no take
    if(dp[index][w]!=-1) return dp[index][w];
    int notake=f(index-1,w,wt,val,dp);

    int take=INT_MIN;
    if(wt[index]<=w){
        take=val[index]+f(index-1,w-wt[index],wt,val,dp);
    }
    return dp[index][w]=max(take,notake);
}

int main(){
    vector<int> wt = {1, 2, 4, 5};
    vector<int> val = {5, 4, 8, 6};
    int W = 5;
    int n = wt.size();

    vector<vector<int>>dp(wt.size(),vector<int>(W+1,-1));
    cout << "The Maximum value of items the thief can steal is " << f(n-1, W,wt,val,dp);


    
    vector<vector<int>>dp(n,vector<int>(W+1,0));
    //   return f(n-1, W,wt,val,dp);
       for(int i=wt[0];i<=W;i++) dp[0][i]=val[0];
       for(int i=1;i<n;i++){
           for(int j=0;j<=W;j++){
                int notake=0+dp[i-1][j];
                int take=INT_MIN;
                if(wt[i]<=j){
                    take=val[i]+dp[i-1][j-wt[i]];
                }
                dp[i][j]=max(take,notake);               
           }
       }
       
       return dp[n-1][W];

}

