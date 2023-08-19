void printSpelling(int n)
{
    char arr [][10] ={"zero","one","two","three", "four", "five", "six", "seven", "eight","nine", "ten"};
    
    //base case 
    if(n==0) return;

    //recursive case 
    printSpelling(n/10);

    //code is present after the function call
    int last_digit=n%10; 
    cout<<arr[last_digit]<<" ";
    return ;
}

void printSpellingReverse(int n)
{
    char arr [][10] ={"zero","one","two","three", "four", "five", "six", "seven", "eight","nine", "ten"};
    
    //base case 
    if(n==0) return;

    //code is present before the function call
    int last_digit=n%10; 
    cout<<arr[last_digit]<<" ";
   

    //recursive case 
    printSpelling(n/10);
    
    return ;
    
}

signed main()
{
    INOUTERR

    int n;
    cin>>n;
   printSpellingReverse(n);

}
