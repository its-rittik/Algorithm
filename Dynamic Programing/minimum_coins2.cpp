//https://codeforces.com/problemset/problem/189/A

#include<bits/stdc++.h>

using namespace std;
int main(){
    int n , a , b, c;
    cin>>n>>a>>b>>c;

    vector<int>dp(n+1,INT_MIN);
    vector<int>arr ={a,b,c};


    dp[0]=0;
    for(int i = 1 ; i <=n ; i++){
        for(int j = 0 ; j <3 ; j++){
            if(arr[j] <=i) 
                dp[i] = max(dp[i] , dp[i-arr[j]]+1);
        }
    }
    cout<<dp[n];

}
