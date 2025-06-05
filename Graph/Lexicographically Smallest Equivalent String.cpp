class Solution {
private:
    char dfs(char current_ch, vector<vector<char>> &adjLs, vector<int> &vis){
        int idx = current_ch - 'a';

        char current_min_ch = current_ch;

        for(char &ch: adjLs[idx]){
            int next_idx = ch - 'a';
            if(!vis[next_idx]){
                vis[next_idx] = 1;
                char res = dfs(ch,adjLs,vis);
                current_min_ch = min(current_min_ch,res);
            }
        }

        return current_min_ch;
    }    
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n = s1.length();
        int m = baseStr.length();

        vector<vector<char>> adjLs(26);

        for (int i = 0; i < n; i++) {
            char u = s1[i];
            char v = s2[i];

            adjLs[u - 'a'].push_back(v);
            adjLs[v - 'a'].push_back(u);
        }

        string result;
        

        for(int i=0; i<baseStr.length(); i++){
            vector<int> vis(26,0);
            result += dfs(baseStr[i], adjLs,vis);
        }

        return result;
    }
};