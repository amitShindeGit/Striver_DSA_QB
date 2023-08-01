class Solution {
private:
    void findCombination(vector<vector<int>> &ans, vector<int>& candidates, vector<int>& ds, int index, int target ){
        if(target == 0){
            ans.push_back(ds);
            return;
        }

        for(int i=index; i<candidates.size(); i++){
            if(i>index && candidates[i] == candidates[i-1]) continue;
            if(candidates[i] > target) break;

            ds.push_back(candidates[i]);
            findCombination(ans, candidates, ds, i+1, target - candidates[i] );
            ds.pop_back();
        }
    }    
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(candidates.begin(), candidates.end());
        findCombination(ans, candidates, ds, 0, target);

        return ans;
    }
};