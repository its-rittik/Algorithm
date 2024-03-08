//https://vjudge.net/contest/356290#problem/G
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t ;
    cin>>t ;
    int count = 1;
    while(t--){
        int n ;
        cin>>n;
        vector<int> arr(n);
        for(int i = 0 ; i<n; i++) cin>>arr[i];
        sort(arr.begin() , arr.end());
        cout<<"Case "<<count++ <<": "<<arr[n-1]<<endl;
    }
    return 0 ;
}