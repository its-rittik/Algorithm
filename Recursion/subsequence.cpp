#include<bits/stdc++.h>
using namespace std;

int subsequence_number = 1 ;

//Time complixity : O(2^n) ; Space complixity : O(n)
void SubSequence(int index , vector<int>&arr ,vector<int>&temp_arr){
    
    int n = arr.size();
    
    //Time complixity : O(n) ; Space complixity : O(n)
    if(index >= n) {
        cout<<"Sub-sequence "<<subsequence_number++<<" : ";
        for(int i = 0 ; i < temp_arr.size() ;i++) cout<<temp_arr[i]<<" ";
        cout<<endl;
        return;
    }

    //Time complixity : O((2^n) * n) ; Space complixity : O(n+n) = O(n)

    //take or pick the particular index into this subsequence
    temp_arr.push_back(arr[index]);
    SubSequence(index+1 , arr, temp_arr);

    // not take or pick the particular index into this subsequence    
    temp_arr.pop_back();
    SubSequence(index+1 , arr, temp_arr);

}

//Time complixity : O(n) ; Space complixity : O(n)
int main(){
    int n ;
    cout<<"Enter the value of n : ";
    cin>>n;
  
    vector<int>arr(n);
    vector<int>temp_arr;

    for(int i = 0 ; i <n ; i++) cin>>arr[i];
    SubSequence(0 , arr , temp_arr);

    return 0 ;
}