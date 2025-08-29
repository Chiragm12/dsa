/* 
to find the second largest ele in the array, no need to sort the array, just find the largest ele, then again do it and print 
that ashte
*/
#include<bits/stdc++.h>
#include<vector>
using namespace std;

class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        // code here
        int largest=arr[0];
        int slargest=-1;
        int n=arr.size();
        for(int i=1;i<n;i++){
            if(arr[i]>largest){
                slargest=largest;
                largest=arr[i];
            }
            else if(arr[i]<largest && arr[i]>slargest){
                slargest=arr[i];
            }
            
        }
        return slargest;
    
    }
};