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


class Solution{

	public:
	int f(int index,int sum,vector<int>arr,vector<vector<int>>dp){
	    if(index==0){
	        if(sum==0 && arr[index]==0) return 2;
	        if(sum==0 || sum==arr[0]) return 1;
	        return 0;
	    }
	    if(dp[index][sum]!=-1) return dp[index][sum];
	    int nopick=f(index-1,sum,arr,dp);
	    int pick=0;
	    if(arr[index]<=sum){
	        pick=f(index-1,sum-arr[index],arr,dp);
	    }
	    dp[index][sum]=pick+nopick;
	    return pick+nopick;
	}
	
	int cntPartiton(vector<int>arr ,int d)
	{
        int n=arr.size();
        int tarsum=0;
        for(auto&a:arr){
             tarsum+=a;
        }

        int target=(tarsum-d)/2;
	    vector<vector<int>>dp(n,vector<int>(target+1,0));

        
        if((tarsum-d)<0 || tarsum%2==0) return false;
         return f(arr.size()-1,target,arr,dp);

    


// ````````````````````````
        int sum=target;
	    vector<vector<int>>dp(n,vector<int>(sum+1,0));
	   // return f(n-1,sum,arr,dp);
        // Base cases
        int mod = 1e9 + 7;

        if (arr[0] == 0) {
            dp[0][0] = 2;  // Two possibilities: include or exclude the 0
        } else {
            dp[0][0] = 1;  // Only one possibility: exclude the first element
        }

        if (arr[0] != 0 && arr[0] <= sum) {
            dp[0][arr[0]] = 1;  // One possibility: include the first element
        }
	   
        for (int index = 1; index < n; index++) {
            for (int j = 0; j <= sum; j++) {
                int notPick = dp[index - 1][j] % mod;
                int pick = 0;
                if (arr[index] <= j) {
                    pick = (dp[index - 1][j - arr[index]]) % mod;
                }
                dp[index][j] = (pick + notPick) % mod;
            }
        }
	   int ans=(dp[n-1][sum]) ;
	   return ans;
	}
	  
};

//{ Driver Code Starts.
// int main() 
// {
   	
   
//    	int t;
//     cin >> t;
//     while (t--)
//     {
//         int n, sum;

//         cin >> n >> sum;

//         int a[n];
//         for(int i = 0; i < n; i++)
//         	cin >> a[i];

       

// 	    Solution ob;
// 	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
//     }
//     return 0;
// }

// } Driver Code Ends