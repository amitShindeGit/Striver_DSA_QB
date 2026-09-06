class Solution {
    public int firstStableIndex(int[] nums, int k) {
        int n = nums.length;
        int[] rightMin = new int[n];
        int min = nums[n-1];
        int maxL = Integer.MIN_VALUE;
        int ans = -1;


        for(int i=n-1; i>=0; i--){
            min = Math.min(nums[i], min);
            rightMin[i] = min;
        }


        for(int i=0; i<n; i++){

            maxL = Math.max(nums[i], maxL);
            int minR = rightMin[i];

            if(maxL - minR <= k){
                ans = i;
                break;
            }

        }

        return ans;
    }
}