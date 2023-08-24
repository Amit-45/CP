Climbind stairs : https://leetcode.com/problems/climbing-stairs/description/
Recursion -> Memoization -> Tabulation -> Space optimiszation

Method 1: Recursion -> O(2^n) 

class Solution {
public:
    int recursion(int index)
    {
        if(index==0) return 1;
        if(index==1) return 1;

        int left = recursion(index-1);
        int right = recursion(index-2);
        
        return left + right; 
    }
    int climbStairs(int n) {
        return recursion(n);
    }
};



Method 2: Memoization

class Solution {
public:
    int memoization(int index, vector<int> &dp)
    {
        if(index==0) return 1;
        if(index==1) return 1;

        if(dp[index]!=-1) return dp[index];

        int left = memoization(index-1,dp);
        int right = memoization(index-2,dp);
        
        return dp[index]= left + right; 
    }
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return memoization(n,dp);
    }
};



Method 3: Tabulation

  class Solution {
public:
    int tabulation(int index, vector<int> &dp)
    {
        dp[0]=1;
        dp[1]=1;

        if(dp[index]!=-1) return dp[index];

        for(int i=2;i<=index;i++)
        {
            dp[i] = dp[i-1]+dp[i-2];      
        }        
        return dp[index];
    }
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return tabulation(n,dp);
    }
};

Method 4: Space Optimization

class Solution {
public:
    int spaceOptimization(int index, vector<int> &dp)
    {
       int prev1=1;
       int prev2=1;

        if(dp[index]!=-1) return dp[index];

        for(int i=2;i<=index;i++)
        {
            dp[i] = dp[i-1]+dp[i-2]; 
            int curr=prev1+prev2;
            prev2=prev1;
            prev1=curr;     
        }        
        return prev1;
    }
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return spaceOptimization(n,dp);
    }
};

  
