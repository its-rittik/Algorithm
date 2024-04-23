#include<iostream>
using namespace std;

int main() {
    int arr[] = {1, 5, 10, 25};
    int n = sizeof(arr) / sizeof(arr[0]);
    int given_tk;
    cout << "Given tk in dollar: ";
    cin >> given_tk;
    int purchased_value;
    cout << "Purchased value: ";
    cin >> purchased_value;

    int return_value = (given_tk * 100) - purchased_value;

    int count_coin = 0;

    for (int i = n - 1; i >= 0; i--) {
        while (arr[i] <= return_value) {
            return_value -= arr[i];
            count_coin += 1;
        }
    }

    cout << "Total number of coins: " << count_coin << endl;

    return 0;
}
