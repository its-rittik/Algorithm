//https://vjudge.net/contest/356290#problem/I
#include<bits/stdc++.h>
using namespace std;

int main(){
    int team;
    cin>>team;
    team*=2;
    vector<int>arr(team);

    for(int i = 0 ; i < team-1 ; i+=2) cin>>arr[i]>>arr[i+1];
    int count = 0 ;
    for(int i = 0 ; i < team ; i+=2) 
        for(int j = 1 ; j < team ; j+=2) if(arr[i]==arr[j]) count++;
    cout<<count<<endl;

    return 0 ;
}