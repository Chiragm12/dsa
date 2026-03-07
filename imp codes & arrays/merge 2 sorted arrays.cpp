#include <iostream>
#include <vector>
using namespace std;

vector<int> mergeSortedArrays(vector<int>& a, vector<int>& b) {
    int i=0;
    int j=0;
    int n=a.size();
    int m=b.size();
    vector<int>merged;
    while(i<n&&j<m){
        if(a[i]<b[j]){
            merged.push_back(a[i]);
        i++;
        }
        else{
            merged.push_back(b[j]);
            j++;
        }

    }
    while(i<n){
        merged.push_back(a[i]);
        i++;
    }
    while(j<m){
        merged.push_back(b[j]);
        j++;
    }
    return merged;
}