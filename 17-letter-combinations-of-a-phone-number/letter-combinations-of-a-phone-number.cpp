class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        vector<string> mp = {
            "", "", "abc", "def", "ghi",
            "jkl", "mno", "pqrs", "tuv", "wxyz"
        };

        vector<string> ans;
        string current;

        function<void(int)> solve = [&](int index) {
            // We have picked one character for every digit
            if (index == digits.size()) {
                ans.push_back(current);
                return;
            }

            string letters = mp[digits[index] - '0'];

            // Try every character of this digit
            for (char ch : letters) {
                current.push_back(ch);

                // Move to the next digit
                solve(index + 1);

                // Remove the character and try the next one
                current.pop_back();
            }
        };

        solve(0);

        return ans;
    }
};