//sort string without using any build in function
#include<bits/stdc++.h>
using namespace std;

void sorting_string(string str){
    for(int i = 0 ; i < str.length()-1 ; i++){
        bool check = false ;
        for(int j = i+1 ; j < str.length() ; j++) 
            if(str[i] > str[j]){
                swap(str[i] , str[j]);
                check = true ;
            }
        if(check== false)  break;
    }

    cout<<"Sorted string : "<<str<<endl;
}

int main(){
    string str;
    cout<<"Enter a string: ";
    getline(cin,str);

    sorting_string(str);
}