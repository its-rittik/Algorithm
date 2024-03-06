// Palindrome checker 
#include<iostream>
using namespace std;

bool palindrome(string s){
    bool checker = false;

    int high = s.length();
    int low = 0;

    while(low <= high){
        if(s[high--] == s[low++]) checker = true;
        else checker = false ; 
    }
    return checker;
}
int main(){
    string s ;
    cout<<"Enter the string: ";
    getline(cin,s);
    
    if(palindrome(s)==1) cout<<"It's a palindrom."<<endl;
    else cout<<"It's not a palindrom."<<endl;
}