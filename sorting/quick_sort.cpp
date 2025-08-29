/*
select a pivot element from the array, then partion the array such that take
one element form the left and right, and from left, select the ele which is greater than the pivot, and from right, select the ele which is less than the pivot

qs(arr,low,high){
if(low<high){

    }
}

*/

#include<bits/stdc++.h>
using namespace std;

//check this code

vector<int> quick_sort(vector<int> arr,int low,int high){
    if(low<high){
        int pivot=partition(arr,low,high);
        quick_sort(arr,low,pivot-1);
        quick_sort(arr,pivot+1,high);
    }
    return arr;
}

int partition(vector<int> arr,int low,int high){
    int pivot=arr[high];
    int i=low-1;
    for(int j=low;j<high;j++){
        if(arr[j]<=pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[high]);
    return i+1;
}