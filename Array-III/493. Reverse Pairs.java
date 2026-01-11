class Solution {
    private void sortAndMerge(int[] arr, int low, int mid, int high){
        int left = low;
        int right = mid+1;
        List<Integer> tempArr = new ArrayList<>();

        while(left <= mid && right <= high){
            if(arr[left] <= arr[right]){
                tempArr.add(arr[left]);
                left++;
            }else{
                // arr[left] > arr[right]
                tempArr.add(arr[right]);
                right++;
            }
        }

        while(left <= mid){
            tempArr.add(arr[left]);
            left++;
        }

        while(right <= high){
            tempArr.add(arr[right]);
            right++;
        }

        for(int i=0; i<tempArr.size(); i++){
            arr[i + low] = tempArr.get(i);
        }
    }

    private int countPairs(int[] arr, int low, int mid, int high){
        int count = 0;
        int right = mid+1;
        for(int i=low; i<=mid;i++){
            // Since nums[i] can be large, it's good to convert to long so that the multiplies number doesn'e overflow
            while(right <= high && (arr[i] > (2L * arr[right]))){
                right++;
             }

             count += (right - (mid + 1));
        }

        return count;
        
    }

    private int mergeSort(int[] nums, int low, int high){
        int count = 0;  
        if(low >= high) return count;

        int mid = (high + low) /2;

        count += mergeSort(nums, low, mid);
        count += mergeSort(nums, mid+1,high);
        count += countPairs(nums, low, mid, high);
        sortAndMerge(nums, low, mid, high);

        return count;
    }

    public int reversePairs(int[] nums) {
        int n = nums.length;
        
        return mergeSort(nums, 0, n-1);
    }
}