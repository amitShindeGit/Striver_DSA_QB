vector<int> Solution::solve(vector<int> &A, vector<int> &B, int C) {
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    priority_queue<pair<int , pair<int, int>>> maxHeap;
    set<pair<int, int>> pairSet;
    
    int n = A.size();
    maxHeap.push(make_pair(A[n-1] + B[n-1], make_pair( n-1, n-1 )));
    pairSet.insert(make_pair(n-1, n-1));
    
    vector<int> ans;
    
    while(C--){
        auto top = maxHeap.top();
        maxHeap.pop();
        ans.push_back(top.first);
        int L = top.second.first;
        int R = top.second.second;
        
        if(L > 0 && R > 0 && pairSet.find(make_pair(L-1, R)) == pairSet.end()  ){
            pairSet.insert(make_pair(L-1, R));
            maxHeap.push(make_pair(A[L-1] + B[R], make_pair( L-1, R )));
        }
        
         if(L > 0 && R > 0 && pairSet.find(make_pair(L, R-1)) == pairSet.end()  ){
            pairSet.insert(make_pair(L, R-1));
            maxHeap.push(make_pair(A[L] + B[R-1], make_pair( L, R-1 )));
        }
    }
    
    return ans;
}
