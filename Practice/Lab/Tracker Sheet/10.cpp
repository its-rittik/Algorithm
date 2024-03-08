//https://vjudge.net/contest/356290#problem/J
#include<bits/stdc++.h>
using namespace std;


int main(){
    int n, k , count = 0 ;
    cin>>n>>k;

    vector<int>arr(n);
    for(int i = 0 ; i < n ;i++) cin>>arr[i];
    int temp = arr[k-1];
    sort(arr.begin() , arr.end());

    for(int i = 0 ; i< n ; i++){
        if(arr[i] == temp && temp != 0){
            count = n-i;
            break;
        }
        if(temp == 0 && arr[i] != 0){
            count = n-i;
            break;
        }
    }
    cout<<count<<endl;
    
    return 0 ;
}