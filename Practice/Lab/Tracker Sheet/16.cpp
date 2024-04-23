#include<bits/stdc++.h>
using namespace std;

int main(){
    int test;
    cin>>test;
    
    int gap = 0 ;
    int count = 1;

    while(test--){
        int n ;
        cin>>n ;
        vector<int> arr ;
        for(int i = 0 ; i < n ; i++){
            int temp;
            cin>>temp;
            arr.push_back(temp);
        }
        
        for(int i = 0;i<n-1;i++) if(abs(arr[i]-arr[i+1]) > gap) gap = abs(arr[i] -arr[i+1]);
        cout<<"Case "<<count++<<": "<<gap<<endl;
    }
    return 0;
}