class Solution {
    public List<Integer> majorityElement(int[] nums) {
        List<Integer> ans = new ArrayList<>();
        
        int count1 = 0;
        int count2 = 0;
        int ele1 = Integer.MAX_VALUE;
        int ele2 = Integer.MAX_VALUE;
        int n = nums.length;

        if(n <= 1){
            return Arrays.stream(nums).boxed().collect(Collectors.toList());
        }

        for(int i=0; i<n; i++){
            if(count1 == 0 && nums[i] != ele2){
                count1++;
                ele1 = nums[i];
            }else if(count2 == 0 && nums[i] != ele1){
                count2++;
                ele2 = nums[i];
            }else if(nums[i] == ele1){
                count1++;
            }else if(nums[i] == ele2){
                count2++;
            }else{
                count1--;
                count2--;
            }
        }

        count1 = 0;
        count2 = 0; 
        for(int i=0; i<n; i++){
            if(nums[i] == ele1){
                count1++;
            }

            if(nums[i] == ele2){
                count2++;
            }
        }

        if(count1 > (n/3) && ele1 != Integer.MAX_VALUE){
            ans.add(ele1);
        }

        if(count2 > (n/3) && ele2 != Integer.MAX_VALUE){
            ans.add(ele2);
        }

        return ans;

    }
}