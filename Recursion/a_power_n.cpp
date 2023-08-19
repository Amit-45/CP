
//O(n) approach

int power(int a, int n) {
    if (n == 0) {
        return 1;
    }
    return a * power(a, n - 1);
}


//O(log n) approach
int aPwernRecursive(int a, int n)
{
    if (n == 0) return 1;

    int small_ans = aPwernRecursive(a, n / 2); //store it before muliplying. It reduces TC from [O(n) = 2 * O(n/2) + O(1)]    --->       [ O(n) = O(n/2) + O(1)]
    small_ans *= small_ans; 

    if (n % 2 == 1)
    {
        return small_ans * a;
    }

    return small_ans;
}
