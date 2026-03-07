class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mp;
        for(string s:strs){
            string key=s;
            sort(key.begin(),key.end());
            mp[key].push_back(s);
        }
        //This is how it looks
        //         mp = {
        //   "aet": ["eat", "tea", "ate"],
        //   "ant": ["tan", "nat"],
        //   "abt": ["bat"]
        // }

        vector<vector<string>> result;
        for(auto&entry:mp){
            result.push_back(entry.second);
        }
        return result;
    }
};