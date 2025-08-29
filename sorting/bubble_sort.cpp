#include <iostream>
#include <vector>
using namespace std;
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> arr = {29, 10, 14, 37, 13, 5, 8, 3, 9, 25};
    int n = arr.size();

    for (int i = 0; i < n - 1; i++) {
        int did_swap = 0;
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                did_swap = 1;
            }
        }
        if(did_swap==0){
            break;
        }
    }

    // Output the sorted array
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
