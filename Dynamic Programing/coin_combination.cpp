//https://cses.fi/problemset/task/1635
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n , x; 
    cin>>n>>x;
    const int mod = 1e9+7;

    vector<int>dp(x+1,0);
    vector<int>coins(n);

    for(int i = 0 ; i < n ; i++) cin>>coins[i];

    dp[0]= 1;
    for(int i = 1 ; i<=x ; i++){
        for(int j = 0 ; j < n ; j++){
            if(coins[j]<=i){
                dp[i] = (dp[i] + dp[i-coins[j]]) % mod;
            }
        }
    }
    cout<<dp[x];
}