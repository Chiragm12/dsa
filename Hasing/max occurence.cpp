#include <bits/stdc++.h>

using namespace std;

// Class to count frequencies using unordered_map (hash table)
class FrequencyCounter {
public:
    void Frequency(int arr[], int n){
        unordered_map<int,int> map;
        for(int i=0;i<n;i++){
            map[arr[i]]++;
        }
        int max_ele=0,min_ele=0,max_freq=0;
        int min_freq=n; //we do this deliberately so that whatever value comes we will switch to that, just check below
        
        for(auto it:map){
            int ele=it.first;
            int count=it.second;

            if(count>max_freq){
                max_freq=count;
                max_ele=ele;
            }
            if(count<min_freq){
                min_freq=count;
                min_ele=ele;
            }
        }
    }
}