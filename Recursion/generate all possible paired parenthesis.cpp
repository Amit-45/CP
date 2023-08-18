#include <bits/stdc++.h>
using namespace std;
void recursion(string s, int n)
{
    if (s.size() == 2 * n)
    {
        cout << s << endl;
        return;
    }
    string open = s + '(';
    string closed = s + ')';

    recursion(open, n);
    recursion(closed, n);
}

signed main()
{
    int n;
    cin >> n;
    string s;

    recursion(s, n);
}
