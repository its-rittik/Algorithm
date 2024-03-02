#include<bits/stdc++.h>
using namespace std;

void insertion_sort(vector<int>&arr){
    
    for(int i = 1 ; i < arr.size() ; i++){
        int temp = arr[i];
        int j = i ;
        while(j--){
            if(temp<arr[j])  arr[j+1] = arr[j];
            else break;
        }
        swap(arr[j+1] , temp);
    }
}

int main(){
    vector<int>arr ={1,2,4,3,7,6,5};
    insertion_sort(arr);

    for(int i = 0 ; i < arr.size(); i++) cout<<arr[i]<<" ";
    return 0 ;
}