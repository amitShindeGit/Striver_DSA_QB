int upper_bound (vector<int> &arr   , int x, int n) {
    int low = 0, high = n-1;
    int ans = n;
    while(low <= high){

    int mid = (low + high) / 2;

    if(arr[mid] > x){
        ans = mid;
        high = mid - 1;
    }else{
        low = mid + 1;
    }
    }

    return ans;
}

int countSmall (vector<vector<int>> &matrix, int n, int m, int x) {
    int count = 0;
    for(int i=0;i<n;i++){
        count += upper_bound(matrix[i], x,m);
    }

    return count;
}

int median(vector<vector<int>> &matrix, int m, int n) {
    // Write your code here.
    int low = INT_MIN;
    int high = INT_MAX;

    n = matrix.size();
    m = matrix[0].size();

    // for(int i=0; i<n;i++){
    //     low = min(low, matrix[i][0]);
    //     high = max(high, matrix[i][m-1]);
    // }

    int req = (n * m)/ 2;
    while(low <= high){
       int  mid = (high + low) / 2;
       int smallEqual = countSmall(matrix, n,m, mid);

       if(smallEqual <= req){
           low = mid + 1;
       }else{
           high= mid - 1;
       }

    }

    return low;
}