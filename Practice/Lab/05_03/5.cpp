//Substring finder
#include<bits/stdc++.h>
using namespace std;

int main(){
    string str1 , str2 ;
    cout<<"Enter the main string: ";
    getline(cin,str1);

    cout<<"Enter the sub string: ";
    getline(cin,str2);
    
    int index = 0;
    int count = 0;
    bool checker = false;

    for(int i = 0 ; i < str1.length() ; i++){
        if(count == str2.length()){
            checker = true;
            break;
        }
        if(str1[i] == str2[index++]) count++;
        else {
            count = 0;
            index = 0;
        }
    }
    if(checker) cout<<"Sub string present in the main string.";
    else cout<<"Sub string doesn't present in the main string.";
    
    return 0;
}