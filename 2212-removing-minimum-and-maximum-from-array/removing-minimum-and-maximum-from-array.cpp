class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        int minIndex = 0;
        int maxIndex = 0;

        // Find positions of minimum and maximum
        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[minIndex]) {
                minIndex = i;
            }

            if (nums[i] > nums[maxIndex]) {
                maxIndex = i;
            }
        }

        if (minIndex > maxIndex) {
            swap(minIndex, maxIndex);
        }

        int deleteLeft = maxIndex + 1;
        int deleteRight = n - minIndex;
        int deleteBoth = (minIndex + 1) + (n - maxIndex);

        return min({deleteLeft, deleteRight, deleteBoth});
    }
};