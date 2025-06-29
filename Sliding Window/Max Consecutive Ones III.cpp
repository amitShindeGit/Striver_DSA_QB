class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0, r = 0;
        int tempK = k;
        int maxLen = 0;

        while (r < n) {
            if (nums[r] == 0) {
                if (tempK == 0) {
                    while (nums[l] != 0) {
                        l++;
                    }
                   l++; //Extra +1 because we don't want to consider the current 0

                } else {
                    tempK--;
                }
            }
            maxLen = max(maxLen, r - l + 1);
            r++;
        }
        return maxLen;
    }
};