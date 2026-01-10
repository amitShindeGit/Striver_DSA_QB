import java.util.* ;
import java.io.*; 
public class Solution {
    static long ans = 0;

    private static void sortAndMerge(long arr[], int low, int mid, int high){
        int left = low;
        int right = mid+1;
        List<Long> tempArr = new ArrayList<>();

        while(left <= mid && right <= high){
            if(arr[left] <= arr[right]){
                tempArr.add(arr[left]);
                left++;
            }else{
                //We want this combo
                // For each index,if arr[left] > arr[right], we should get all pairs
                ans += (mid - left + 1);
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

    private static void mergeSort (long arr[], int low, int high){
        if(low >= high) return;

        int mid = (low + high) / 2;

        mergeSort(arr, low, mid);
        mergeSort(arr, mid+1, high);

        sortAndMerge(arr, low, mid, high);

    }

    public static long getInversions(long arr[], int n) {
        // Write your code here.
        mergeSort(arr,0, n-1);

        return ans;
    }
}