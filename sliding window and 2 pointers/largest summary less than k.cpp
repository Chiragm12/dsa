/*
Here the question is to find the largest subarray with sum less than k
so [2,5,6,1,8] k=14
   so in 2 pointers, take left and right, so here left is 0 and right is 0
   so sum is 2, next left will be at 2 only but right will be at 1, which is 5, sum is 7, like that keep going 
   till u get a sum greater than k, then from then onwards, move the left pointer to the next index of the previous left pointer thats all.
so the largest subarray with sum less than k is [2,5,6]
so the answer is 3
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
while(r<n){
    sum=sum+arr[r];
    while(sum>k){
        sum=sum-arr[l];
        l++;
    }
    if(sum<=k){
        ans=max(ans,r-l+1);
    }
    r++;
}

// but in 2 pointers way, why do we need to decremenet the left once we have max, like if one of the max is 3, 
// then why reduce the value of l to inside, hence do this

while(r<n){
    sum=sum+arr[r];
    if(sum>k){  //changed from while to if
        sum=sum-arr[l];
        l++;
    }
    if(sum<=k){
        ans=max(ans,r-l+1);
    }
    r++;
}