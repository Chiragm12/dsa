/*
so in his algo, negative numbers if we encounter we assume them to be the max initally, cause if array contains only 1 number,
then that will be the max, and for the rest, we keep adding them, and we initally keep the array number as max, and add
the next ele in the list, and once we encouncter a number greater than the sum, we update the array.
*/
//maxiumum subarray in array

#include <vector>
#include <climits>  // for INT_MIN
using namespace std;
class Solution {
public:
    int maxSubarraySum(std::vector<int> &arr) {
        int n = arr.size();
        int sum = 0;
        int maxSum = INT_MIN;

        for(int i = 0; i < n; i++) {  // start from 0
            sum += arr[i];
 
            if(sum > maxSum)
                maxSum = sum;

            if(sum < 0)
                sum = 0;
        }

        return maxSum;  // return the maximum subarray sum
    }
};

//to print the elements in the list,

#include <vector>
#include <climits>  // for INT_MIN

class Solution {
public:
    int maxSubarraySum(std::vector<int> &arr) {
        int n = arr.size();
        int sum = 0;
        int maxSum = INT_MIN;
        int start;
        int ans_start=-1,ans_end=-1;
        for(int i = 0; i < n; i++) {  // start from 0, as the starting digit starts from 0.
            if(sum==0) start=i;

            sum += arr[i];

            if(sum > maxSum)
                maxSum = sum;
                ans_start=start; ans_end=i;

            if(sum < 0)
                sum = 0;
        }

        return maxSum;  // return the maximum subarray sum
    }
};

//this is using the bruteforce methord, 
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        
        int summ=0,ans=INT_MIN;
        for(int i=-1;i<n;i++){
            summ=0;
            for(int j=i+1;j<n;j++){
                summ=summ+nums[j];
                ans=max(ans,summ);
            }
            
        }
        return ans;
    }
};