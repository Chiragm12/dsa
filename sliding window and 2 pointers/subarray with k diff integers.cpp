/*
we find elements that are less than equal to k, and elements less than equal to k-1, and then subtract them asthe.
*/


class Solution {
public:
    int atMostKDistinct(vector<int>& nums, int k) {
        int left = 0, right = 0, count = 0;
        map<int, int> hash;

        for (; right < nums.size(); right++) {
            if (hash[nums[right]] == 0) {
                k--; // use local copy, safe now
            }
            hash[nums[right]]++;

            while (k < 0) {
                hash[nums[left]]--;
                if (hash[nums[left]] == 0) {
                    hash.erase(nums[left]);
                    k++;  // restore one unique element back
                }
                left++;
            }

            count += right - left + 1;
        }

        return count;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMostKDistinct(nums, k) - atMostKDistinct(nums, k - 1);
    }
};
