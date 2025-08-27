class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        int n = nums.length;

        Set<List<Integer>> st = new HashSet<>();
        for(int i=0; i<n; i++){
            Set<Integer> hashSet = new HashSet<>();
            for(int j=i+1; j<n; j++){
                int third = -(nums[i] + nums[j]);

                if(hashSet.contains(third)){
                    List<Integer> list = new ArrayList<>();
                    list.add(nums[i]);
                    list.add(nums[j]);
                    list.add(third);

                    Collections.sort(list);
                    st.add(list);
                }

                hashSet.add(nums[j]);
            }
        }

        List<List<Integer>> ans = new ArrayList(st);

        return ans;
    }
}