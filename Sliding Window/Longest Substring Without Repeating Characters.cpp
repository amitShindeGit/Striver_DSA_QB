class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0){
            return 0;
        }

        int n = s.size(); //Since 0-256 is all char range in ascii
        vector<int> map(256, -1);

        int l = 0;
        int r = 0; //left, right
        int maxLen = 0;

        while(r < n){

            if(map[s[r]] != -1){
                l = max(map[s[r]] + 1, l);
            }

            map[s[r]] = r;
            maxLen = max(maxLen, r - l + 1);
            r++;
        }

        return maxLen;
    }
};