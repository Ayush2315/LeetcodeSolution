class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> set;
        
        int left = 0;
        int right = 0;
        int maxLength = 0;

        while (right < s.length()) {
            // If character is not in the current window
            if (set.find(s[right]) == set.end()) {
                set.insert(s[right]);

                maxLength = max(maxLength, right - left + 1);

                right++;
            }
            // Duplicate found
            else {
                set.erase(s[left]);
                left++;
            }
        }

        return maxLength;
    }
};