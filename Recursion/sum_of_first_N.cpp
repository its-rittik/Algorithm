//using back tracking 

#include<bits/stdc++.h>

using namespace std;

int sum = 0;

void SumFirstN(int i , int n){
    if(i == 0)
        return;
    SumFirstN(i-1,n);

    sum +=i;
    if(i==n)
        cout<<"Sum of fist "<<n<<" is : "<<sum;
}

int main(){

    int n ;
    cout<<"Enter the value of n : ";
    cin>>n ;
    SumFirstN(n,n);

    return 0;
}