encoded = "5#Hello5#World"
decoded as hello world

class Solution {
public:
    string encode(vector<string>& s) {
        string encoded = "";
        for (string i : s) {
            encoded += to_string(i.size()) + "#" + i;
        }
        return encoded;
    }

    vector<string> decode(const string& s) {
        vector<string> result;
        int i = 0;

        while (i < s.size()) {
            int j = i;
            // Find position of '#'
            while (s[j] != '#') j++;

            int length = stoi(s.substr(i, j - i));  // Get the number before '#'
            string word = s.substr(j + 1, length);  // Extract that many characters

            result.push_back(word);

            i = j + 1 + length;  // Move to the next encoded string
        }

        return result; // ✅ Correct place
    }
};
