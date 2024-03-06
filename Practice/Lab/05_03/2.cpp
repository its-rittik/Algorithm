//Character frequency count without using any built in function
#include<bits/stdc++.h>
using namespace std;

void character_frequency(string s){
    vector<int> frequency_arr ;

    int length = s.length();

    for(int i = 0 ;i < length ; i++){
        
        char temp = s[i];
        int current_char_length = 1;
        
        for(int j = i+1 ; j < length ; j++){
            if(temp == s[j] ){
                s.erase(j , 1);
                current_char_length ++;
            }
        }
        frequency_arr.push_back(current_char_length);
        length = s.length();
    }
    
    for(int i = 0 ; i < length ; i++) 
        if(s[i]!=' ')  cout<<"Char : "<<s[i]<<" frequency : "<<frequency_arr[i]<<endl;
}



int main(){
    string s ;
    cout<<"Enter the string: ";
    getline(cin,s);
    character_frequency(s);
}