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




O(n) : DP approach
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


O(n) : Space optimised approach

int fib(int n)
{
    if(n<=1) return n;

    int prev=0;
    int curr=1;

    for(int i=2;i<=n;i++)
    {
        int temp = curr;
        curr = prev+temp;
        prev=temp;
        
    }
    return curr;
    
}

void solve()
{
    int n;
    cin>>n;
    cout<<fib(n);
}
