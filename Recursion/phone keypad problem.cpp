class Solution {
public:
    void recursion(string s, string &digits, map<char, string> &m, vector<string> &result) {
        if (s.size() == digits.size()) {
            result.push_back(s);
            return;
        }

        int index = s.size();
        string characters = m[digits[index]];

        for (int i = 0; i < characters.size(); i++) {
            string newString = s + characters[i];
            recursion(newString, digits, m, result);
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return {};
        }

        map<char, string> m;
        m['2'] = "abc";
        m['3'] = "def";
        m['4'] = "ghi";
        m['5'] = "jkl";
        m['6'] = "mno";
        m['7'] = "pqrs";
        m['8'] = "tuv";
        m['9'] = "wxyz";

        vector<string> result;
        recursion("", digits, m, result);

        return result;
    }
};
