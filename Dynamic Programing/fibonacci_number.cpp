#include<bits/stdc++.h>
using namespace std;

int main(){
    int n ;
    cin>>n;
    
    //TC:O(N)  SC:O(N)
    // vector<int>dp(n);

    // dp[0] =0 , dp[1]= 1;
    // for(int i = 2 ; i<=n ; i++) dp[i] = dp[i-1]+dp[i-2];
    
    // cout<<n<<"th fibo number : "<<dp[n]<<endl;

    //TC:0(N) DC:O(1)
    int previous = 1 , previous2=0;
    
    for(int i = 2; i<=n; i++){
        int current = previous + previous2;
        previous2 = previous;
        previous = current;
    }
    cout<<n<<"th fibo number :b"<<previous<<endl;

    return 0 ;
}