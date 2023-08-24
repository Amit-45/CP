O(2^n) : Recursive appproach


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




O(n) time and  O(n) space of stack : DP approach (memoization) 
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


O(n) time  and O(1) space : Space optimised approach

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
