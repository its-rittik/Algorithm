#include<bits/stdc++.h>
using namespace std;

void Reverse(int arr[] , int start , int end){
    if(start > end)
        return;
    swap(arr[start],arr[end]);
    return Reverse(arr , start+1 , end-1);
}

int main(){
    int arr[] ={1,2,3,4,5};
    Reverse(arr,0,4);

    for(int i = 0 ; i < 5 ; i++)
        cout<<arr[i]<<" ";
}