// Print the subsequence where sum is k ? 

#include <bits/stdc++.h>
using namespace std;

void subsequence(int index , int k , vector<int>& arr , vector<int>& temp_arr){
    int n = arr.size();
    int sum = 0 ;

    if(index>=n ){
        for(int i = 0 ; i < temp_arr.size() ; i++) sum+=temp_arr[i];
        if(sum==k) {
            cout<<"Sum: ";
            for(int i = 0 ; i < temp_arr.size() ; i++) cout<<temp_arr[i]<<" ";
            cout<<endl;
        }
        return;
    }
    
    //include the element
    temp_arr.push_back(arr[index]);
    subsequence(index+1 , k , arr , temp_arr);
    
    //don't include the element
    temp_arr.pop_back();
    subsequence(index+1 , k , arr, temp_arr);
}

int main(){
    int n;
    cout<<"Enter the value of n : ";
    cin>>n ;

    vector<int> arr(n);
    vector<int> temp_arr ;

    cout<<"Enter the value of array: ";
    for (int i = 0 ; i < n ; i++) cin>>arr[i];

    int k ;
    cout<<"Enter the value of sum : ";
    cin>>k;

    subsequence(0 , k , arr, temp_arr);

    return 0 ;
} 
