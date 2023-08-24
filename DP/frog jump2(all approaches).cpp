Method 1: Recursion  TC: O(k^n) SC: O(n)+ O(n) stack space
int recursion(int index, vector<int> &arr,int k) 
{
    if (index == 0) return 0;
    int miniSteps = INT_MAX;

    for(int j=1;j<=k;j++)
    {
        if(index-j>=0)
        {
           int jump = recursion(index - j, arr,k) + abs(arr[index ] - arr[index - j]);
            miniSteps= min(miniSteps , jump);
        }

    }
    return miniSteps;

}


int frogJump(int n, vector<int> &heights,int k)
{
   return recursion(n-1,heights,k);   
}

int main()
{
    int n;int k; cin>>n>>k;
    vector<int> heights(n);
    for (int i = 0; i < n; ++i) cin>>heights[i];
    cout<<frogJump(n,heights,k);
}

Method 2: Memoization  TC: O(n)*k SC: O(n)+ O(n) stack space

int memoization(int index, vector<int> &arr,int k,vector<int> &dp) 
{
    if (index == 0) return 0;

    if(dp[index]!=-1) return dp[index];
    int miniSteps = INT_MAX;

    for(int j=1;j<=k;j++)
    {
        if(index-j>=0)
        {
           int jump = memoization(index - j, arr,k,dp) + abs(arr[index ] - arr[index - j]);
            dp[index]= min(miniSteps , jump);
        }

    }
    return dp[index];

}

int frogJump(int n, vector<int> &heights,int k)
{
   vector<int> dp(n+1,-1);
   return memoization(n-1,heights,k,dp);   
}

int main()
{
    int n;int k; cin>>n>>k;
    vector<int> heights(n);
    for (int i = 0; i < n; ++i) cin>>heights[i];
    cout<<frogJump(n,heights,k);
}
  
