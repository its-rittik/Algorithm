#include<bits/stdc++.h>
using namespace std;

int main(){
    string str;
    cout<<"Enter a string: ";
    getline(cin,str);

    int count = 0 ;

    for(int i = 0 ; i < str.length() ; i++){
        for(int j = i+1 ; j<str.length() ; j++) if(str[i] != str[j]) count++;
    }

    cout<<"Unique characters : "<<count<<endl;
}