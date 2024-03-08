//https://vjudge.net/contest/356290#problem/H
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n ;
        cin >>n;
        vector<int>arr(n);
        for(int i = 0 ; i < n ; i++) cin>>arr[i];

        sort(arr.begin() , arr.end());

        int walk = 0 ;

        for(int i = 0 ; i< n-1 ; i++) walk+=(arr[i+1]-arr[i]);

        walk+=(arr[n-1]-arr[0]);

        cout<<walk<<endl;
    }
    return 0 ;
}