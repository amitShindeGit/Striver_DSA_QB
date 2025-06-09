class Solution {
private:
    int count(long curr, long next, int n){
        long steps = 0;
        while(curr <= n){
            steps += (next - curr);
            curr *= 10;
            next *= 10;
            next = min(next, long(n+ 1));
        }

        return steps;
    } 

public:
    int findKthNumber(int n, int k) {
        long curr = 1;
        k--;

        while(k > 0){
            long steps = count(curr,curr + 1, n);
            if(steps <= k){
                //We have to skip this series
                curr += 1;
                k -= steps;
            }else{
                // we have to go deeper in this series
                curr *= 10;
                k -= 1;
            }
        } 

        return curr;  


    }
};