#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cmath>
#include <stdio.h>
#include<map>
using namespace std;
// 1. two sum on leetcode

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> num_to_index; // value -> index
        for (int i = 0; i < nums.size(); i++) {
            int remaining = target - nums[i];
            // check if complement exists
            if (num_to_index.count(remaining)) { //to check if the map contains the remaining number
                return {num_to_index[remaining], i};  // return indices
            }
            // store current number with its index
            num_to_index[nums[i]] = i;
        }
        return {}; // return empty vector if no solution
    }
};
