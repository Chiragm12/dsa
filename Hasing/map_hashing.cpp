#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cmath>
#include <stdio.h>
#include<map>
using namespace std;

//so here we store it using map, so in array we need to declare the size of the array,
//and memory will be allocated for the array, but for maps, only the ele we need to store is allocated
//time complexity is O(logn)
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    //precompute 
    map<int,int> hashh;//key,value pair
    
    for(int i=0;i<n;i++) { 
        hashh[arr[i]]+=1;
    } 

    //printing/iterating the map
    for(auto it :hashh){
        cout<<it.first<<"->"<<it.second<<endl;
    }

    int q;
    cin>>q;
    while(q--){
        int number;
        cin>>number;
        cout<<hashh[number]<<endl;
    }
}