#include<bits/stdc++.h>
using namespace std;


// Time complixity : O(2^n) , Space complixity : O(1) 
//Functional method
int fibonacci(int n){
    if(n <= 1) return n ;
    return fibonacci(n-1)+fibonacci(n-2);
}

//Back Tracking 
int fibonacci_back_tracking(int n){
    if(n<=1) return n;
    int first = fibonacci(n-1);
    int last = fibonacci(n-2);
    
    return first+last;
}

// Time complixity : O(1) , Space complixity : O(1)
int main(){
    int n;
    
    cout<<"Give me the value of n : ";
    cin>>n;
    cout<<"You enter "<<n<<" as the value of n.\n";
    cout<<"\nFibonacci of "<<n<<"th number is "<<fibonacci_back_tracking(n)<<endl;
}