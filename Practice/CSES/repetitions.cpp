#include<bits/stdc++.h>
using namespace std;

int main(){
    string dna;
    getline(cin , dna);

    char temp = dna[0];
    int count = 0 , height_count = 0;

    for(int i = 0 ; i < dna.length() ; i++){
        if(dna[i] == temp){
            count++;
            if(count > height_count)
                height_count = count;
        }else{
            temp = dna[i];
            count = 1;
        }
    }

    cout<<height_count<<endl;
}