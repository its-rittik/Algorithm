//https://cses.fi/problemset/task/1634
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n , x;
    cin>>n>>x;

    vector<int> coins(n);
    for(int i = 0 ; i <n ; i++) cin>>coins[i];

    //dp[i] means minimum coins to generate sum of i
    vector<int> dp (x+1,1e9);

    dp[0] = 0;
    
    for(int i = 1 ; i<=x ; i++){
        for(int j = 0 ; j < n ; j++){
            if(coins[j] <= i ) dp[i] = min(dp[i] , dp[i-coins[j]]+1);
        }
    }
    cout<<(dp[x] < 1e9 ? dp[x] : -1)<<endl;
    
    return 0;
}
