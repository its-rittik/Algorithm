//Concatenate two string
#include<bits/stdc++.h>
using namespace std;

int main(){
    string str1 , str2 , concatenate_str ;
    cout<<"Enter the first string: ";
    getline(cin,str1);

    cout<<"Enter the second string: ";
    getline(cin,str2);
    
    concatenate_str+=str1;
    concatenate_str+=str2;

    cout<<"concatenate string :"<<concatenate_str<<endl;

    return 0;
}