// you have 2 sorted arrays of size n and m
// you need to merge them into a single array, which has all the unique elements from both arrays
//we use 2 pointer methrord.

#include <bits/stdc++.h>
using namespace std;
vector<int> sortedarray(vector<int> a, vector<int> b){
    int n1=a.size(),n2=b.size();
    int i,j=0;
    vector<int> unionarr;
    while(i<n1&&j<n2){
            if(a[i]<b[j]){
                    if(unionarr.size==0 || 
                    unionarr.back!=a[i]){
                        unionarr.push_back(a[i]);
                    }
                i++;
        }
        else{  
                if(unionarr.size==0 || 
                unionarr.back!=b[j]){
                    unionarr.push_back(b[j]);
                }
            j++;

        
    }
}