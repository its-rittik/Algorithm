//https://cses.fi/problemset/task/1633
#include<bits/stdc++.h>
using  namespace std;

/*
int main(){
    const int mod = 1000000007  ;

    int n;
    cin>>n;

    vector<int>dp(n+1,0);

    dp[0]=1;
    
    for(int k = 0 ; k <= n ; k++){
        for(int j = 1 ; j <= 6 ; j++){
            if(k>=j)
                dp[k] = (dp[k]+dp[k-j]) % mod ;

        }
    }
    cout<<dp[n]<<endl;
}
*/

//space optimised solution
int main(){
    const int mod =1e9+7;
    int n;
    cin>>n;

    vector<int> previous = {1};

    for(int i = 1; i <= n ; i++){
        int current = 0 ;
        
        for(int j : previous) current = (current+j) % mod ;
        
        previous.push_back(current);
        if(previous.size()>6) previous.erase(previous.begin());
    }
    cout<<previous.back()<<endl;
}