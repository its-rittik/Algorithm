#include<bits/stdc++.h>
using namespace std;

int main() {
    int arr[] = {2, 5, 4, 7, 1, 3, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    int bin_capacity = 10;
    int bin_count = 0;

    sort(arr, arr + n); 
    int left = 0, right = n - 1;
    while (left <= right) {
        int current_weight = 0;
        while (left <= right && current_weight + arr[left] <= bin_capacity) {
            current_weight += arr[left];
            left++;
        }
        bin_count++;
    }

    cout << "Number of bins required: " << bin_count << endl;

    return 0;
}
