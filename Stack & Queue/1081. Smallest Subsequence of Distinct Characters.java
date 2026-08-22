class Solution {
    public String smallestSubsequence(String s) {
        Stack<Character> st = new Stack<>();
        int n = s.length();

        //a,b,c,...z wise array
        boolean[] taken = new boolean[26];
        int[] lastIndex = new int[26];

        for (int i = 0; i < n; i++) {
            char ch = s.charAt(i);
            lastIndex[ch - 'a'] = i;
        }

        for (int i = 0; i < n; i++) {
            int idx = s.charAt(i) - 'a';
            char currCh = s.charAt(i);

            if (taken[idx])
                continue;

            while (!st.empty() && currCh < st.peek() && lastIndex[st.peek() - 'a'] > i) {
                taken[st.pop() - 'a'] = false;
            }

            st.push(currCh);
            taken[idx] = true;
        }

        StringBuilder res = new StringBuilder();
        while (!st.empty()) {
            res.append(st.pop());
        }

        return res.reverse().toString();
    }

}