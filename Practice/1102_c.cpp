#include <iostream>
#include<math.h>


using namespace std;

int main(){
    int n , x, y;
    cin>>n>>x>>y;

    int arr[n];
    for(int i = 0 ; i < n ; i++)
        cin>>arr[i];
    
    sort(arr,arr+n);
    
    int sum = 0;
    sum = accumulate(arr,arr+n,sum);
    int temp = sum;

    int count = 0 ;
    int result = 0 ;

    while(temp!=0 || sum == temp){
        sum = accumulate(arr,arr+n,sum);

        if(arr[count] <=x )
            arr[count]= max(0,arr[count]-x);
        if(arr[count]!=0)
            arr[count]+=y;
        else   
            result++;
        count++;
        temp = accumulate(arr,arr+n,temp);
        cout<<result;
    
    }
    cout<<"result "<<result;

    return 0;
}