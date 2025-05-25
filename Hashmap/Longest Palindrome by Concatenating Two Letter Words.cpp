class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> mp;
        int ans = 0;

        for(auto &word: words){
            string reveresedWord = word;
            swap(reveresedWord[0],reveresedWord[1]);

            //If reverse exists, then reduce count and add 4 to length
            if(mp[reveresedWord] > 0){
                ans += 4;
                mp[reveresedWord]--;
            }else{
            //Else just increase word count
                mp[word]++;
            }
        }


        //Only check for same char words i.e for e.g aa,bb,etc
        for(auto &it: mp){
            string word = it.first;
            int count = it.second;

            if(word[0] == word[1] && count > 0){
                ans += 2;
                break;
            }
        }

        return ans;
    }
};