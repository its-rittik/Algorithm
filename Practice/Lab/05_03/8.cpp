//Encode a string based on their frequency .For example 'a' and 'b' present in one string . soer them accoring to the frequency and code the evey unique character

#include<bits/stdc++.h>
using namespace std;

void printBinary(char c, int position, int bit_size) {
    string binary;
    for (int i = bit_size - 1; i >= 0; --i) {
        binary += to_string((position >> i) & 1);
    }
    cout << "Character: " << c << ", Binary code: " << binary << endl << endl;
}

// Generate code for every unique character with minimum bit size
void generate_code(vector<pair<char,int>>& frequency){
    
    int bit_size=1;

    for(;;){
        if(pow(2,bit_size) <= frequency.size()) bit_size++;
        else break;
    }

    for(int i = 0 ; i < frequency.size();i++){
        printBinary(frequency[i].first,i, bit_size);
    }
}

//sort character according to the frequency
void sort_the_char(vector<pair<char,int>>& frequency){
    
    for(int i = 0 ; i < frequency.size();i++){
        for(int j = i+1 ;j < frequency.size() ; j++){
            if(frequency[i].first > frequency[j].first)
                swap(frequency[i].first , frequency[j].first);
        }
    }
    generate_code(frequency);
}

//Count unique character and their frequency
void count_frequency_of_unique_char(const string& str) {
    vector<pair<char, int>> frequency;

    for (char c : str) {
        bool found = false;
        for (auto& pair : frequency) {
            if (pair.first == c) {
                pair.second++;
                found = true;
                break;
            }
        }
        if (!found) {
            frequency.push_back(make_pair(c, 1));
        }
    }

    sort_the_char(frequency);
}


int main(){
    string str;
    cout<<"Enter a string: ";
    getline(cin,str);
    
    count_frequency_of_unique_char(str);

    return 0 ;
}