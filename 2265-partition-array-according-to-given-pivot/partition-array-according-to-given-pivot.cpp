class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        list<int> less;
        list<int> equal;
        list<int> greater;

        for (int x : nums) {
            if (x < pivot)
                less.push_back(x);
            else if (x == pivot)
                equal.push_back(x);
            else
                greater.push_back(x);
        }

        // Combine all three lists
        less.splice(less.end(), equal);
        less.splice(less.end(), greater);

        // Convert list to vector
        vector<int> ans(less.begin(), less.end());

        return ans;
    }
};