class Solution {
    private boolean canAccomodateCows(int gap, int[] stalls, int k){
        int cowCount = 1;
        int currentCow = stalls[0];
        int n = stalls.length;
        
        for(int i=1; i<n; i++){
            if(stalls[i] - currentCow >= gap){
                cowCount++;
                currentCow = stalls[i];
            }
            
            if(cowCount == k){
            return true;
            }
        }
        
        return false;
    }
    public int aggressiveCows(int[] stalls, int k) {
        // code here
        int n = stalls.length;
        Arrays.sort(stalls);
        int low = 1;
        int high = stalls[n-1] - stalls[0];
        int res = -1;
        
        while(low <= high){
            int mid = (low + high) >> 1;
            
            if(canAccomodateCows(mid, stalls, k)){
                res = mid;
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
        
        return res;
        
        
    }
}