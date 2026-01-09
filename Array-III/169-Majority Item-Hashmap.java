class Solution {
    public int majorityElement(int[] nums) {
        HashMap<Integer, Integer> mp = new HashMap<>();

        for(int i=0; i<nums.length; i++){
            mp.put(nums[i], mp.getOrDefault(nums[i], 0) + 1 );
        }

        int maxKey = mp.entrySet().stream().max(Map.Entry.comparingByValue()).get().getKey();

        return maxKey;

    }
}