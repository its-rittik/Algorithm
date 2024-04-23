#include <iostream>
using namespace std;

int main() {
    int weights[] = {20, 10, 15, 10, 5};
    int values[] = {100, 60, 70, 40, 80};
    int capacity = 50;
    int n = sizeof(weights) / sizeof(weights[0]);

    int valueperweight[n];
    for (int i = 0; i < n; i++) 
        valueperweight[i] = values[i] / weights[i];

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (valueperweight[j] < valueperweight[j + 1]) {
                swap(valueperweight[j], valueperweight[j + 1]);
                swap(weights[j],weights[j + 1]);
                swap(values[j], values[j + 1]);
            }
        }
    }
    int total_value = 0 ;
    int total_weight = 0 ;
    int i = 0 ;
    while(total_weight<capacity){
        if(total_weight+weights[i] <= capacity){
            total_value+=values[i];
            total_weight+=weights[i];
        }
        i++;
    }
    cout << total_value;
    return 0;
}

