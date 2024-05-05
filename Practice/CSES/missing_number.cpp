#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> arr(n-1);
    vector<int> arr2(n);

    for(int i = 0 ; i < n-1 ; i++){
        int t;
        cin>>t;
        arr.push_back(t);
    } 

    for(int i= 0 ; i < n; i++) arr2.push_back(i+1);

    int approx_sum = accumulate(arr.begin() , arr.end() ,0); 
    int total_sum = accumulate(arr2.begin(),arr2.end(),0);

    cout<<total_sum-approx_sum<<endl;
}