int singleNonDuplicate(vector<int>& arr)
{
	// Write your code here
	int low = 0;
	int high = arr.size()-2;

	while(low <= high){
		int mid = (low + high) >> 1;

		//First condition is for 1st number as even and 2nd number as odd, 
		// if both fails we are in the opposite side(1st number as odd and 2nd number as even)
		if((mid % 2 != 0 && arr[mid] == arr[mid-1]) || (mid % 2 == 0 && arr[mid] == arr[mid+1])){
			low = mid + 1;
		}else {
			high = mid - 1;
		}

	}

	return arr[low];
}