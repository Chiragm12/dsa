#include <vector>


class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> lastseen(3, -1);
        int count = 0;
        for (int i = 0; i < s.length(); i++) {
            lastseen[s[i] - 'a'] = i;
            if (lastseen[0] != -1 && lastseen[1] != -1 && lastseen[2] != -1) {
                int minLast = min({lastseen[0], lastseen[1], lastseen[2]});
                count += minLast + 1; // we add everything from the left so if its bbabce, and a is the least assume, then ull include b, thenb
                // then everything along with the 2 bs, hence ull add that extra 1, so index=2 , + 1 hence.
            }
        }
        return count;
    }
};