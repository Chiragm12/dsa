/*
brute force methrod is use sets, and then 
it'll automatically take only the unique elements
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int index=0;
        set<int>st;
        for(auto x:nums){
            st.insert(x);
        }
        for(int x:st){
            nums[index++]=x;
        }
        return index;
    }
};
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