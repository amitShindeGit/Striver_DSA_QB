class Solution {
private:
    void swapArray (vector<int> &arr,int index1, int index2) {
        int temp = arr[index1];
        arr[index1] = arr[index2];
        arr[index2] = temp;
    }    
public:
    void getPermutations (vector<int>& nums, vector<vector<int>> &ans, int index) {
        if(index == nums.size()-1){
            ans.push_back(nums);
            return;
        }

        for(int i=index; i<nums.size(); i++){
            swapArray(nums, index, i);
            getPermutations(nums, ans, index+1);
            swapArray(nums, index, i);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        getPermutations(nums, ans, 0 );
        return ans;
    }
};