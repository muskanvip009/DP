#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>

using namespace std;

// memoization
int fib(int n, vector<int> &dp)
{
    if (n <= 1)
    {
        return n;
    }
    if (dp[n] != -1)
        return dp[n];
    return fib(n - 1, dp) + fib(n - 2, dp);
}

// tabulation

int main()
{

    int n;
    cin >> n;
    vector<int> dp(n + 1, -1);
    cout << fib(n, dp) << endl;

    // tabulation
    vector<int> dp2(n + 1, -1);
    dp2[0] = 0;
    dp2[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        dp2[i] = dp2[i - 1] + dp2[i - 2];
    }
    cout << dp2[n] << endl;

    // less space
    int prev2 = 0;
    int prev = 1;
    for (int i = 2; i <= n; i++)
    {
        int curri = prev + prev2;
        prev2 = prev;
        prev = curri;
    }

    cout << prev << endl;
}
