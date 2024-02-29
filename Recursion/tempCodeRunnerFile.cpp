#include<bits/stdc++.h>
using namespace std;

bool plandrom(int arr[] , int i , int n){
    if(arr[i] != arr[n-1+1])
        return false;
    if(i > n/2)
        return true;
    return plandrom(arr , i+1 , n);
}

int main(){
    int n ;
    int arr[n];
    for (int i = 0 ; i < n ; i++) cin>>arr[i];
    cout<<plandrom(arr , 0 , n);
}