#include<bits/stdc++.h>
using namespace std;

int main(){
    int n , x;
    const int mod = 1e9+7;
    cin>>n>>x;
    
    vector<int> coins(n);
    for(int i = 0 ; i<n ; i++) cin>>coins[i];

    vector<vector<int>> dp(n+1 , vector<int> (x+1));

    //base case
    for(int i = 0 ; i<n;i++) dp[i][0] = 1;

    //state
    for(int i = n-1 ; i >=0 ; i--){
        for(int sum = 1 ; sum <= x ; sum++){
            int skipped = dp[i+1][sum];
            int picked =0;

            if(coins[i]<= sum ) picked = dp[i][sum-coins[i]];

            //Transtion
             dp[i][sum] = (skipped+picked) % mod ; 
        }
       
    }
    //fianl problem
    cout<<dp[0][x]<<endl;
}