class Solution {
    public int removeDuplicates(int[] nums) {
        int left = 0;
        int right = 1;
        int n = nums.length;

        while(right < n){
            if(nums[right] != nums[left]){
                left++;
                nums[left] = nums[right];
            }
            right++;
        }

        return left + 1;
    }
}