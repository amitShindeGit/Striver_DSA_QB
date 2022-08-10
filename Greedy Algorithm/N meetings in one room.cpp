//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    // Greedy Approach    
    struct meeting{
        int start;
        int end;
        int position;
    };
    
    static bool comparator(struct meeting m1, meeting m2){
        if(m1.end < m2.end) return true;  //comparator fn working:- if we want to swipe then return false
        else if(m1.end > m2.end) return false;
        else if(m1.position < m2.position) return true;
        return false;
    }
    
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        struct meeting meet[n];
        
        for(int i=0; i<n; i++){
            meet[i].start = start[i];
            meet[i].end = end[i];
            meet[i].position = i+1;
        }
        
        sort(meet, meet+n, comparator);
        
        vector<int> answer;
        int limit = meet[0].end;
        answer.push_back(meet[0].position);
        
        for(int i=1; i<n; i++){
            if(meet[i].start > limit){
                limit = meet[i].end;
                answer.push_back(meet[i].position);
            }
        }
        
        return answer.size();
        
        
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends