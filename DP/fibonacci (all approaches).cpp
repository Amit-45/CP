Recursion -> Memoization -> Tabulation -> Space optimiszation

Method 1: Recursion -> O(2^n) 


int fib(int n)
{
    if(n<=1) return n;

    return fib(n-1) + fib(n-2);
}
void solve()
{
    int n;
    cin>>n;

    cout<<fib(n);
}


 
Method 2: Memoization ->O(n) time and  O(n) space 


int fib(int n,vector<int> &dp)
{
    if(n<=1) return n;

    if(dp[n]!=-1) return dp[n];

    return dp[n]=fib(n-1,dp)+fib(n-2,dp);
}
void solve()
{
  int n;
  cin>>n;
  vector<int> dp(n+1,-1);
  cout<<fib(n, dp);

}

Method 3: Tabulation ->O(n) time and  O(n) space 

int fib(int n,vector<int> &dp)
{
    if(n<=1) return n;

    dp[0]=0;
    dp[1]=1;

    for(int i=2;i<=n;i++)
    {
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
    
}

void solve()
{
    int n;
    cin>>n;
    vector<int> dp(n,-1);
    cout<<fib(n,dp);
}

Method 4:  Space optimisation -> O(n) time and  O(1) space 

int fib(int n)
{
    if(n<=1) return n;

    int prev2=0;
    int prev1=1;

    for(int i=2;i<=n;i++)
    {
       
        int curr = prev1 + prev2;
        prev2=prev1;
        prev1=curr;
        
    }
    return prev1;
    
}

void solve()
{
    int n;
    cin>>n;
    cout<<fib(n);
}
