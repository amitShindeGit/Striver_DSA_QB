class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        string a = strs[0];
        string b = strs[strs.size()-1];
        string ans;
        
        if(strs.size() == 0 || strs[0] == ""){
            return "";
        }
        
        int i=0;
        while(i < a.size() && a[i] == b[i]){
                ans += a[i];
                i++;
        }
                    
        return ans;
    }
};