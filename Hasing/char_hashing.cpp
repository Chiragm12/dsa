#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cmath>
#include <stdio.h>

using namespace std;
//here we store the frequency of each character in the string, using their ascii value  
// so we'll do charecter -'a', and we can get the index, as a starts from 97, then b is 98, and so on

int main(){
    string s;
    cin>>s;
    //precompute the hash
    int hash[26]={0};
    for(int i=0;i<s.size();i++){
        hash[s[i]-'a']+=1; // as 'b'-'a' = 1, so we'll get the index of the character
    }
    int q;
    cin>>q;
    while(q--){
        char c;
        cin>>c;
        cout<<hash[c-'a']<<endl;
    }
}
