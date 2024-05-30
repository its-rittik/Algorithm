#include<bits/stdc++.h>

using namespace std;

/*
// Brut forces

int fibo(int n){
    if(n<=2) return 1;
    return fibo(n-1)+fibo(n-2);
}
*/

/*
//dp recurtion
int dp_fibo(int n , vector<int> &dp){
    if(n<=2) return 1;

    if(dp[n]!=-1) return dp[n];

    return dp[n] = fibo(n-1 , dp) + fibo(n-2 , dp);
} 
*/

//dp iteration

/*
void dp_fibo(int n){
    vector<int> dp(n+1,-1);

    dp[1] = 1 , dp[2] = 1;

    for(int i = 3 ; i <= n ; i++) dp[i] = dp[i-1]+dp[i-2];

    cout<<dp[n]<<endl;
}
*/

//space optimization

void dp_space_optimised_fibo(int n){
    int prev1 = 1 , prev2 = 1 , current = 0;
    for(int i = 2 ; i <= n ; i++){
        current = prev1+prev2;
        
        prev2 = prev1;
        prev1 = current;
    }
    cout<<current<<endl;
}

int main(){
    int n;
    vector<int> dp(n+1,-1);
    cin>>n;

    dp_space_optimised_fibo(n);

    return 0;
}