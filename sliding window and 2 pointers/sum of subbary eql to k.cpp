/*
we need to find number of subarry equal to k, using 2 pointer and sliding window, and its only binary numbers,
so what we do it we find the total number of subarrys <= k, and <=k-1, and hence if we subtract them we find total subarray equal to k
very smart way
*/

//*******subarrys <= k, and <=k-1, and hence if we subtract them we find total subarray equal to k********** */

#include <iostream>
#include <vector>
#include <algorithm>


class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atmost(nums,goal)-atmost(nums,goal-1);
    }
private:
    int atmost(vector<int>& nums, int S){
        if(S<0) return 0;
        int left=0,res=0,sum=0;
        for(int right=0;right<nums.size();right++){
            sum+=nums[right];
            while(sum>S){
                sum-=nums[left];
                left++;
            }
            res+=right-left+1; // total number of subarrays possiblew within 2 points
        }
        return res;
    }
};