class Solution {
public:
    int maxDepth(string s) {
        int n = 0;
        int maxdepth = 0;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                n += 1;
            }

            if (s[i] == ')') {
                n -= 1;
            }

            if (maxdepth < n) {
                maxdepth = n;
            }
        }

        return maxdepth;
    }
};