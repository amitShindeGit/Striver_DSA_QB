class Solution {
    public int majorityElement(int[] nums) {
        // Moore's vote algorithm
        int count = 0;
        int ele = Integer.MAX_VALUE;
        int n = nums.length;

        for(int i=0; i<n; i++){
            if(count == 0){
                ele = nums[i];
                count++;
            }else if(nums[i] == ele){
                count++;
            }else{
                count--;
            }
        }

        return ele;
    }
}