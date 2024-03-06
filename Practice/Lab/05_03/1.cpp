//Write a c program that will takes a string input from the user and calculates the length of the string without using the built-in strlen() function
#include<bits/stdc++.h>
using namespace std;

int get_string(string s){
    int length = 0;
    for(int i = 0 ; s[i]!='\0' ;i++) if(s[i]!= ' ') length+=1;
return length;
}

int main(){
    string s ;
    cout<<"Enter the string: ";
    getline(cin,s);
    cout<<"Length of the string : "<<get_string(s);
}