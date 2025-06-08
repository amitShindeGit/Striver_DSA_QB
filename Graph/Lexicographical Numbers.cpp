class Solution {
private:
    void dfsSolve(int currNum, vector<int>& ans, int n) {
        if (currNum > n) {
            return;
        }

        ans.push_back(currNum);

       for (int i = 0; i <= 9; ++i) {
            int next = currNum * 10 + i;
            
            dfsSolve(next, ans,n);
        }
    }

public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans;

        for (int i = 1; i <= 9; i++) {
            dfsSolve(i, ans, n);
        }

        return ans;
    }
};