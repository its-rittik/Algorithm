//https://cses.fi/problemset/task/1638
#include<bits/stdc++.h>
using namespace std;

int main(){
    const int mod = 1e9+7;
    int n;
    cin>>n;
    string grid[n];
    for(int  i = 0; i < n ; i++) 
        cin>>grid[i];

    vector<vector<int>> dp(n , vector<int>(n+1));
    //number of ways to go from (i , j ) to (n-1 , n-1)
    
    //base case
    if(grid[n-1][n-1] == '.') 
        dp[n-1][n-1] = 1;
    else 
        dp[n-1][n-1] = 0;

    for(int i = n-1 ; i>=0 ; i--){
        for(int j = n-1; j>=0 ; j--){
            
            if(i == n-1 && j == n-1) continue;
            if(grid[i][j] == '*') dp[i][j] = 0;
            else{
                //if you are not in last row
                int ans1 = i < n-1 ? dp[i+1][j] : 0 ;
                //if you are not in last coloum
                int ans2 = j < n-1 ? dp[i][j+1] : 0;

                dp[i][j] = (ans1 + ans2) % mod;
            }
        }
    }
    cout<<dp[0][0];
}