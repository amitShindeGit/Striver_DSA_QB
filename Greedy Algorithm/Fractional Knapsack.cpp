//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    static bool comparator(Item a, Item b){
        double r1 = (double)a.value / (double)a.weight;
        double r2 = (double)b.value / (double)b.weight;
        return (r1 > r2);
    }
    
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        // for(int i=0; i<n; i++){
        //     arr[i].value = (double)arr[i].value / (double)arr[i].weight;
        //     // cout << arr[i].value << endl;
        // }
        
        sort(arr, arr+n, comparator);
       
        double totalWeight = 0;
        // int currWeight = 0;
        double totalValue = 0.0;
        int i=0;
        
            for( i=0; i<n; i++){
                if( totalWeight + arr[i].weight <= W){
                    
                        totalValue +=  arr[i].value;
                        totalWeight += arr[i].weight;
                }else{
                    int remainWt = W - totalWeight;
                    totalValue +=  (arr[i].value / (double)arr[i].weight) * (double)remainWt;
                    break;
                }
            }

        return totalValue;
    }
        
};


//{ Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends