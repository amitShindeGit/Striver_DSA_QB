#include <bits/stdc++.h> 

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	// Write your code here
	//Submitted on Coding Ninja- Test Cases passed 10/11 
    long long int sum = (n * (n+1))/2;
    long long int squareSum = (n * (n+1) * ((2*n)+1))/6;
    pair<long long int, long long int> ans;
        
    int XMinusY=sum;
    int X2MinusY2=squareSum;

    for(int i=0; i<n; i++){
        XMinusY -= (long long int)arr[i];
        X2MinusY2 -= ((long long int)arr[i] * (long long int)arr[i]);
    }
    
    int XPlusY = (X2MinusY2) / (XMinusY);
    
    ans.first = (XPlusY + XMinusY) / 2;
    ans.second = abs(XPlusY - ans.first );
   
    return ans;
    
}
