class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        if (s.size() <= 1) {
            return false;
        }

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                st.push(s[i]);
            } else {
                if (st.empty()) {
                    return false;
                }

                if (s[i] == ')' && st.top() == '(') {
                    st.pop();
                } else if (s[i] == ']' && st.top() == '[') {
                    st.pop();
                } else if (s[i] == '}' && st.top() == '{') {
                    st.pop();
                } else {
                    st.push(s[i]);
                }
            }
        }

        return st.empty();
    }
};