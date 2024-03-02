#include<bits/stdc++.h>
using namespace std;

int binary_search(vector<int>&arr ,int key){
    int low = 0 , high = arr.size()-1; 
    while(low <= high){
        int mid = low+(high-low)/2;
        if(arr[mid] == key) 
            return low;
        if(arr[mid] > key ) high = mid-1;
        if(arr[mid] < key ) low = mid +1 ; 
    }
    return -1;
}

int main(){
    vector<int>arr = {9,8,4,2,1,10};
    int key = 19;
    int result = binary_search(arr , key);

    if(result != -1) cout<<"key : "<<key<<" found on index :" <<result<<endl;
    else cout<<key<<" doesn't exist in this array!"<<endl;
}