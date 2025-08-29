#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int right= nums.size()-1;
        int left=0;
        while(left<=right){
            int mid=(left+right)/ 2;
            if( mid == target) return mid;
            else if(mid>target) left= target+1;
            else right=target-1;
        }
        return -1;
    }
}; 