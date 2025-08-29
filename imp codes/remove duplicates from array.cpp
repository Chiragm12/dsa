/*
brute force methrod is use sets, and then 
it'll automatically take only the unique elements
index=0
for(auto it:st){
arr[index]=it;
index++;
}
time complexity is nlogn
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
     int i=0;
     for(int j=1;j<nums.size();j++){
        if(nums[i]!=nums[j]){
            nums[i+1]=nums[j];
            i++;
        }
     }
     return i+1;
    }
};