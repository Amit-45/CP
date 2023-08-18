void recursion(int i, int n)
{
    if(n==i)
    {
        cout<<i;
        return;
    }
    cout<<i<< " ";
    recursion(i+1,n);


}

signed main()
{
    int n;
    cin >> n;

    recursion(1, n);
}
