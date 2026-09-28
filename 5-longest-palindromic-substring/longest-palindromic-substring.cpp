class Solution {
public:
    string longestPalindrome(string s) {
        int maxl = 1;
        int start = 0;

        for (int i = 0; i < s.length(); i++) {
            int x = i;
            int y = i;

            while (x >= 0 && y < s.length() && s[x] == s[y]) {
                if (y - x + 1 > maxl) {
                    start = x;
                    maxl = y - x + 1;
                }
                x--;
                y++;
            }

            x = i;
            y = i + 1;

            while (x >= 0 && y < s.length() && s[x] == s[y]) {
                if (y - x + 1 > maxl) {
                    start = x;
                    maxl = y - x + 1;
                }
                x--;
                y++;
            }
        }

        return s.substr(start, maxl);
    }
};