class Solution {
    public int trap(int[] height) {
        int leftMax = 0;
        int rightMax = 0;
        int ans = 0;
        int n = height.length;
        if(n == 0){
            return 0;
        }

        int left = 0;
        int right = n - 1;

        while(left != right){
            if(height[left] <= height[right]){
                if(leftMax > height[left]){
                    ans += leftMax - height[left];
                }
                leftMax = Math.max(leftMax, height[left]);
                left++;
            }else{
                if(rightMax > height[right]){
                    ans += rightMax - height[right];
                }
                rightMax = Math.max(rightMax, height[right]);
                right--;
            }
        }

        return ans;
    }
}