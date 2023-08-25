House robber problem 1: 

1. Recursion
  
int f(int ind, const vector<int> &arr) {
    if (ind == 0) return arr[ind];
    if (ind < 0) return 0;
    
    int pick = arr[ind] + f(ind - 2, arr);
    int notPick = f(ind - 1, arr);
    
    return max(pick, notPick);
}

2. Memoization
  
int f(int ind, const vector<int> &arr,vector<int> &dp) {
    if (ind == 0) return arr[ind];
    if (ind < 0) return 0;
    
    if(dp[ind]!=-1) return dp[ind]; 
    
    int pick = arr[ind] + f(ind - 2, arr,dp);
    int notPick = f(ind - 1, arr,dp);
    
    return dp[ind] = max(pick, notPick);
}

int maxSumNonAdjacent(const vector<int> &arr) {
    int n=arr.size();
    vector<int> dp(n+1,-1);
    return f(n-1, arr,dp);
}

3.Tabulation
  
#include <bits/stdc++.h>

using namespace std;

int f(int ind, const vector<int> &arr, vector<int>& dp){
    
    dp[0]= arr[0];
    
    for(int i=1 ;i<ind; i++){
        int pick = arr[i];
        if(i>1)
            pick += dp[i-2];
        int nonPick = 0+ dp[i-1];
        
        dp[i]= max(pick, nonPick);
    }
    
    
    return dp[ind-1];
}

int maxSumNonAdjacent(int n, vector<int>& arr){
    vector<int> dp(n,-1);
    return f(n, arr, dp);
}

4. Space optimization

int f(int ind, vector<int>& arr){
    int prev = arr[0];
    int prev2 =0;
    
    for(int i=1; i<ind; i++){
        int pick = arr[i];
        if(i>1)
            pick += prev2;
        int nonPick = 0 + prev;
        
        int cur_i = max(pick, nonPick);
        prev2 = prev;
        prev= cur_i;
        
    }
    return prev;
}

int maxSumNonAdjacent(int n, vector<int>& arr){
    return f(n, arr);
}


