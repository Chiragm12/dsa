// Hashing
// 10^8-> 1s, 10^10 takes 100s, when calculating for all the numbers in the range, it will be O(Q x n), or just n
// so if it runs 10^10 times,it will be 100s.

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cmath>
#include <stdio.h>

using namespace std;
/*this is how it works, so for numbers, if we have it like 1 3 3 4 2,
we'll make a hash table like this 
hash[1]=1, hash[2]=1, hash[3]=2, hash[4]=1, as hash[arr[i]]+=1, andrai it just gives that number and we store in hash arr/table
so if we wanna know the frequency of 3, we'll just look at hash[3]
and we'll get 2*/

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    //precompute the hash
    int hash[13]={0}; //max we can declare is hash[10^7], or 10^8 if we decare this line globally asthe
    for(int i=0;i<n;i++){
        hash[v[i]]+=1;
    }
    //enter the number whos frequency u wanna know
    int q;
    cin>>q;
    while(q--){
        int number;
        cin>>number;
        cout<<hash[number]<<endl;
    }
}
