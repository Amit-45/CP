
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
