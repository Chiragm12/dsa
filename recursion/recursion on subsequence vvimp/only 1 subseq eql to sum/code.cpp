#include <vector>
#include <iostream>
using namespace std;

bool prints(int ind, vector<int> &ds, int s, int sum, int arr[], int n) {

    if(ind == n){
        if(s == sum){
            for(auto it : ds) cout << it << " ";
            cout << endl;
            return true;
        }
        else return false;
    }

    // pick the element
    ds.push_back(arr[ind]);
    s += arr[ind];

    if(prints(ind+1, ds, s, sum, arr, n) == true)
        return true;

    // backtrack
    s -= arr[ind];
    ds.pop_back();

    // not pick
    if(prints(ind+1, ds, s, sum, arr, n) == true)
        return true;

    return false;
}