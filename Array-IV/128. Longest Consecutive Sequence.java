//TC: O(n)
//SC: O(n)
class Solution {
    public int longestConsecutive(int[] nums) {
        Set<Integer> st = new HashSet<>();
        int n = nums.length;
        int longest = 1;

        if(n == 0) return 0;

        for(int i=0; i<n; i++){
            st.add(nums[i]);
        } 

        for(Integer ele : st){
            if(st.contains(ele-1)){
                continue;
            }else if(!st.contains(ele-1)){
                int count = 0;
                int currentEle = ele;
                while(st.contains(currentEle)){
                    currentEle += 1;
                    count += 1;
                }

                longest = Math.max(count, longest);
            }
        }

        return longest;
    }
}