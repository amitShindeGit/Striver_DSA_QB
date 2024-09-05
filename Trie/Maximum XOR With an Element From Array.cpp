struct Node {
    Node* links[2];

    bool containsKeys(int bit) { return (links[bit] != NULL); }

    Node* get(int bit) { return links[bit]; }

    void put(int bit, Node* node) { links[bit] = node; }
};

class Trie {
    private:
    Node* root;

    public:
    Trie(){
        root = new Node();
    }

    void insert(int num){
        Node *node = root;
        for(int i=31; i>=0; i--){
            long long bit = (num >> i) & 1;
            if(!node->containsKeys(bit)){
                node->put(bit, new Node());
            }
            node = node->get(bit);
        }

    }

    int getMax(long long int num){
        Node* node = root;
        long int maxNum = 0;
        for(int i=31;i>=0;i--){
            long long int bit = (num >> i) & 1;

            if(node->containsKeys(1 - bit)){
                maxNum = maxNum | (1 << i);
                node = node->get(1-bit);
            }else{
                node = node->get(bit);
            }
        }

        return maxNum;
    }


};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> ans(queries.size(), -1);
        sort(nums.begin(), nums.end());

        vector<pair<int, pair<int, int>>> oQ; // oQ = Offline Queries
        int qSize = queries.size();
        int numsSize = nums.size();
        for (int i = 0; i < qSize; i++) {
            oQ.push_back({queries[i][1], {queries[i][0], i}});
        }
        sort(oQ.begin(), oQ.end());

        int currentIndex = 0;
        Trie trie;
        for (int i = 0; i < qSize; i++) {
            int mi = oQ[i].first;
            int xi = oQ[i].second.first;
            int qIndex = oQ[i].second.second;

            while (currentIndex < numsSize && nums[currentIndex] <= mi) {
                trie.insert(nums[currentIndex]);
                currentIndex++;
            }
    cout << currentIndex << " " << xi << " " << mi;
            if (currentIndex == 0) {
                ans[qIndex] = -1;
            } else {
                ans[qIndex] = trie.getMax(xi);
            }
        }

        return ans;
    }
};