#include <iostream>
#include <vector>
using namespace std;

void swapping(int i, int arr[], int n) {
    if (i >= n / 2) return;
    swap(arr[i], arr[n - i - 1]);
    swapping(i + 1, arr, n);
}

int main() {
    int n;
    cin >> n;
    cout << "You entered n = " << n << endl; // Debug line
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    swapping(0, arr.data(), n); // arr.data() gives int* pointer to array inside vector

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
