class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> mergedInterval;
        sort(intervals.begin(), intervals.end());
        vector<int> tempVec = intervals[0];
        
        for(auto it : intervals){
            if(it[0] <= tempVec[1]){
                tempVec[1] = max(it[1], tempVec[1]);
            }
            else{
               mergedInterval.push_back(tempVec);
                tempVec = it;
            }
        }
        mergedInterval.push_back(tempVec);
        
        
        return mergedInterval;
    }
};