/*
have to return the indexs of the elements in a sorted array equal to sum
so take one pointer in begining and one pointer in the end, and then change
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left=0,sum=0,right=numbers.size()-1;
        int num=0;
        while(left<right){
            num=numbers[left]+numbers[right];
            if(num>target) right--;
            else if(num==target)return{left+1,right+1};
            else left++;
        }
        return{left+1,right+1};
    }
};