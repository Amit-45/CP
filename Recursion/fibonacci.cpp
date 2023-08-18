int fibo(int n)
{
    if(n<=1)
    {
        return n;
    }

    int res1= fibo(n-1);
    int res2=fibo(n-2);
    return res1+res2;


}

signed main()
{
    int n;
    cin >> n;

    cout<<fibo(n);
}
