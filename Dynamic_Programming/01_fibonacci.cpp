#include<bits/stdc++.h>
using namespace std;

// recursive approach

// int fibonacci(int n){
//     if(n == 0 || n == 1){
//         return n;
//     }

//     return fibonacci(n-1) + fibonacci(n-2);
// }


// Memoization approach
// int fibonacci(int n, vector<int>& dp){
//     if(n <= 1){return n;}
//     if(dp[n] != -1){return dp[n];}
//     return dp[n] = fibonacci(n-1, dp) + fibonacci(n-2, dp);
    
// }


// Tabulation approach


int main(){
    int n = 9;
    // vector<int>dp(n+1, -1);
    // cout << fibonacci(n, dp) << endl;

    // tabulation
    // vector<int> dp(n+1, -1);
    // dp[0] = 0;
    // dp[1] = 1;
    // for(int i=2;i<=n;i++){
    //     dp[i] = dp[i-1]+dp[i-2];
    // }
    // cout << dp[n];


    // space optimization
    int prev2 = 0;
    int prev1 = 1
    ;
    for(int i=2;i<=n;i++){
        int curri = prev2 + prev1;
        prev2 = prev1;
        prev1 = curri;
    }
    cout << prev1;
    return 0;
}


