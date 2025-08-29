#include<map>


class Solution {
public:
    int longestKSubstr(string &s, int k) {
        int max_len = -1, left = 0;
        map<char, int> hash;
        
        for (int right = 0; right < s.length(); right++) {
            hash[s[right]]++;
            
            while (hash.size() > k) {
                hash[s[left]]--;
                if (hash[s[left]] == 0) hash.erase(s[left]); 
                left++; //we do the above as itll store as a->0, but instead we want 
                // to delete it completely and not have it in the map when its not in substring
            }
            
            if (hash.size() == k) {
                max_len = max(max_len, right - left + 1);
            }
        }
        
        return max_len;
    }
};

