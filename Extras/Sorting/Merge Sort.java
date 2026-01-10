import java.util.List;
import java.util.ArrayList;

public class Solution {

	private static void sortAndMerge(int[] arr,int low, int mid, int high ){
		int left = low;
		int right = mid+1;
		List<Integer> tempArr = new ArrayList<>();

		while(left <= mid && right <= high){
			if(arr[left] <= arr[right]){
				tempArr.add(arr[left]);
				left++;
			}else{
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

		for(int i = 0; i < tempArr.size(); i++){
			// You must copy the values back starting at index low
			arr[low + i] = tempArr.get(i);
		}

	}

	private static void merge(int[] arr, int low, int high){
		if(low >= high) return;

		int mid = (low + high) / 2;

		merge(arr, low, mid);
		merge(arr, mid+1, high);

		sortAndMerge(arr, low, mid,high);
	}

	public static void mergeSort(int[] arr, int n) {
		// Write your code here.
		merge(arr,0,n-1);
	}
}