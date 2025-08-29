
// select the first ele and swap it with the smallest ele, then go to second ele, and swap it with the second smallest ele
#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Initialize vector with some values to sort
    vector<int> arr = {29, 10, 14, 37, 13, 5, 8, 3, 9, 25};

    for (int i = 0; i < 10; i++) {
        int minIndex = i;  // index of the smallest element so far
        for (int j = i + 1; j < 10; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // Swap the found minimum element with element at i
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }

    // Output sorted array
    for (int i = 0; i < 10; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
