class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> mono_st; // monotonic stack
        vector<int> ans;
        unordered_map<int, int> mp;
        vector<int> nge(nums2.size(), -1);

        for (int i = nums2.size() - 1; i >= 0; i--) {
           while(!mono_st.empty() && mono_st.top() <= nums2[i]){
                mono_st.pop();
            }
            if(!mono_st.empty()){
                nge[i] = mono_st.top();
            }
            mono_st.push(nums2[i]);
        }

        for (int i = 0; i < nge.size(); i++) {
            cout << nge[i] << " ";
        }

        for(int i=0;i<nums2.size();i++){
            mp[nums2[i]] = i;
        };

        for(int i=0;i<nums1.size();i++){
            int indexToFind = nums1[i];
            int indexIs = mp[indexToFind];
            ans.push_back(nge[indexIs]);
        }

        return ans;
    }
};class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> mono_st; // monotonic stack
        vector<int> ans;
        unordered_map<int, int> mp;
        vector<int> nge(nums2.size(), -1);

        for (int i = nums2.size() - 1; i >= 0; i--) {
           while(!mono_st.empty() && mono_st.top() <= nums2[i]){
                mono_st.pop();
            }
            if(!mono_st.empty()){
                nge[i] = mono_st.top();
            }
            mono_st.push(nums2[i]);
        }

        for (int i = 0; i < nge.size(); i++) {
            cout << nge[i] << " ";
        }

        for(int i=0;i<nums2.size();i++){
            mp[nums2[i]] = i;
        };

        for(int i=0;i<nums1.size();i++){
            int indexToFind = nums1[i];
            int indexIs = mp[indexToFind];
            ans.push_back(nge[indexIs]);
        }

        return ans;
    }
};