Recursion -> Memoization -> Tabulation -> Space optimiszation

Method 1: Recursion 

int recursion(int index, vector<int> &arr) 
{
    if (index == 0) return 0;

    int left = recursion(index - 1, arr) + abs(arr[index ] - arr[index - 1]);
    int right = INT_MAX;
    if(index>1) right = recursion(index - 2, arr) + abs(arr[index ] - arr[index - 2]);
    return min(left , right);

}


int frogJump(int n, vector<int> &heights)
{
   return recursion(n-1,heights);   
}

Method 2: Memoization 

#include<bits/stdc++.h>
int memoization(int index, vector<int> &arr,vector<int> &dp) 
{
    if (index == 0) return 0;

    if(dp[index]!=-1) return dp[index];
    int left = memoization(index - 1, arr,dp) + abs(arr[index ] - arr[index - 1]);
    int right = INT_MAX;
    if(index>1) right = memoization(index - 2, arr,dp) + abs(arr[index ] - arr[index - 2]);
    
    
    return dp[index] =  min(left , right);

}

int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n+1,-1);
    return memoization(n-1,heights,dp);   
}



Method 3: Tabulation

#include<bits/stdc++.h>
using namespace std;

int tabulation(int index, vector<int> &arr, vector<int> &dp) 
{
    dp[0] = 0; 

    for (int i = 1; i <= index; i++) 
    {
        int left = dp[i - 1] + abs(arr[i] - arr[i - 1]);
        int right = INT_MAX;
        if(i > 1) right = dp[i - 2] + abs(arr[i] - arr[i - 2]);
        
        dp[i] = min(left, right);
    }

    return dp[index];
}

int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n + 1, -1);
    return tabulation(n-1, heights, dp); 
}

Method 4: Space optimization

#include<bits/stdc++.h>
using namespace std;

int spaceOptimization(int index, vector<int> &arr, vector<int> &dp) 
{
    int prev1 = 0;
    int prev2 = 0; 

    for (int i = 1; i <=index; i++) 
    {
        
        int left = prev1 + abs(arr[i] - arr[i - 1]);
        int right = INT_MAX;
        if(i > 1) right = prev2 + abs(arr[i] - arr[i - 2]);
        
        int curr = min(left, right);
        prev2=prev1 ;
        prev1=curr;

        
    }

    return prev1;
}

int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n-1, -1);
    return spaceOptimization(n-1, heights, dp); 
}

