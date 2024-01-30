#include <iostream>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <bits/stdc++.h>
#include <string.h>
#include <bits/stdc++.h>
using namespace std;
using namespace std;

    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));

        for(int i=0;i<=n;i++) dp[i][0];
        for(int j=0;j<=m;j++) dp[0][j];

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(text1[i-1]==text2[j-1]) dp[i][j]=1+dp[i-1][j-1];
                else dp[i][j]=0+max(dp[i-1][j],dp[i][j-1]);
            }
        }

        int len=dp[n][m];
        string ans="";
        for(int i=0;i<len;i++){
            ans+='$';
        }
        int index=len-1;
        int i=n;
        int j=m;
        while(i>0 && j>0){
            if(text1[i-1]==text2[j-1]){
                ans[index]=text1[i-1];
                index--;
                i--;
                j--;
            }
            else if(dp[i-1][j]>dp[i][j-1]) i--;
            else j--;
        }
        cout<<ans;
    }

    int main(){
        string text1="abcde";
        string text2="ace";
        longestCommonSubsequence(text1,text2);


    }