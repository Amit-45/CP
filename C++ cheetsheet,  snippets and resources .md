# C++ cheetsheet and snippets

[https://www.quora.com/Competitive-Programming/What-are-some-cool-C++-tricks-to-use-in-a-programming-contest](https://www.quora.com/Competitive-Programming/What-are-some-cool-C++-tricks-to-use-in-a-programming-contest)

# BIT MANIPULATION

**1 ) Printing the binary representation of any Number.**

```cpp
//METHOD 1: BIT MANIPULATION
void pr_binary(int num){
    for(int i=10;i>=0;i--) cout<<((num>>i)&1);
    cout<<endl;
}

//METHOD 2: Sunyul Bhaiya bit manipulation video

vector<int> convertToBinary(int n) {
    vector<int> ans;
    while (n > 1) {
        ans.push_back(n % 2);
        n = n >> 1;
    }
    ans.push_back(n);
    return ans;
}

int main() {
    INOUTERR
    int n;
    cin >> n;
    
    vector<int> binaryDigits = convertToBinary(n);
    
    for (int index = binaryDigits.size() - 1; index >= 0; index--) {
        cout << binaryDigits[index];
    }
    
    cout << endl;
    return 0;
}

//METHOD 3: Similar to method 2

vector<int> decimalToBinary(int decimal) {
    vector<int> binary;
    
    if (decimal == 0) {
        binary.push_back(0);
    } else {
        while (decimal > 0) {
            binary.push_back(decimal % 2);
            decimal /= 2;
 
        }
    }
 
    return binary;
}

int main() 
{
    INOUTERR
    int t;
    cin >> t;
 
    vector<vector<int>> binaryResults; // we store the results as vector in this vector 
 
    while(t--) {
        int decimal;
        cin >> decimal;
 
        vector<int> binary = decimalToBinary(decimal);
        binaryResults.push_back(binary);
    }
 
    for (int i = 0; i < binaryResults.size(); ++i) { // we print each result here 
        for (int j = binaryResults[i].size() - 1; j >= 0; --j) {
            cout << binaryResults[i][j];
        }
        cout << endl;
    }
 
    return 0;
}

```

**2 ) checking if the ith bit is set or not.**

```cpp
if((num&(1<<i))!=0) cout<<"set"<<endl;
  // check if set or not;
  else cout<<"Not set"<<endl;

```

**3 ) Counting the number of set bits**

```cpp
  int count=0,num=15;
  for (int i=31; i>=0;--i)
  if((num&(1<<i))!=0) count++;

  //OR

  cout<<__builtin_popcount(n); -> if n is integer

  cout<<__builtin_popcountll(n); -> if n is long long

```

**4) How to check if a given number is a power of 2 ?**

```cpp
Properties for numbers which are powers of 2, is that they have one and only
one bit set in their binary representation.
If the number is neither zero nor a power of two, it will have 1 in more than
one place. So if x is a power of 2 then x & (x-1) will be 0.
eg.-> 16-> 10000 and 15 -> 1111
16&15==0

 bool isPowerOfTwo(int x)
  {
      return (x && !(x & (x - 1)));
  }

```

**5) Dividing or multiplying any number by two**

```cpp
 //Although the arithmetic operations are fast ,but by bits manipulation
// we can make them  more faster.
  int n=5;
  n=n>>1;
 // divide by two
  n=n<<1;
 // multiply by two

```

**6 ) Some cool operations and playing with Characters**

```cpp
Difference between upper case letter and lower case letter binary is that
 In upper case letter 5th bit!=1;
 In lower case letter 5th bit =1;
 cout<<char('A'|(1<<5))<<endl;     //Convert Char to lower case;
 cout<<char('a'&(~(1<<5)))<<endl;    //Convert Char to upper case;

 Actually char of 1<<5 is _(space);
 Take any upper case letter and its |(or) with space will get the corresponding lower case letter;

 cout<<char('C'|' ')<<endl;   // will make it small c

Take any lower case letter and its &(and) with _(underscore) will get the corresponding upper //case letter;`

 cout<<char('c'&'_')<<endl;   // will make it capital C

Find a letter’s position in alphabet
We can easily find a letter’s position [1-26] in the
alphabet by taking its bitwise AND with ASCII 31 (00011111 in binary).
The case of the letter is irrelevant here.

 eg.
 (‘A’ & 31) returns position 1
 (‘c’ & 31) returns position 3

```

**7 ) Swap with XOR.**

```cpp
  int a=4;
  int b=5;
  a=a^b;
  b=b^a;
  a=a^b;
  // cout<<a<<" "<<b;

```

**8 ) For clearing the set bits upto ith bit**

```cpp
 int i=4;
//clearing upto 5 the place;
int a=59;
int b=(a&(~((1<<(i+1))-1)));
//clearing the lsb upto ith bit;

i=3;
int c=(a&((1<<(i+1))-1));
//clearing the msb upto ith bit;
```

**9) Binary number to grey code**

```cpp
Binary Number to gray Code
 vector<int> grayCode(int n)
   {
      vector<int>v;
      for(int i=0 ;i<(1<<n);i++)
      v.push_back(i^(i>>1));
      return v;
   }
```

**10)Grey code to binary number**

```cpp
int rev_grayCode (int g) {
 int n = 0;
 for (; g; g >>= 1)
   n ^= g;
 return n;
}
```

**11)Check if number is power of 2**

```cpp

  bool isPowerOfTwo(int n) {
      if (n<=0) return false;
      return !(n & (n - 1)) ;
  }
```

**12)Check if number is power of 4**

```cpp
Q ) Check if a number is a power of 4 or not  ?
The given number n is a power of 4 if it is a power of 2 and
its remainder is 1 when it is divided by 3.

bool isPowerOfFour(int n) {
        if (n<=0) return false;
         return !(n & (n - 1))&& (n % 3 == 1);
    }
```

**13)Check if number is power of 3**

```cpp
class Solution {
public:
// The value 1162261467 is (3^19), which is the largest power of three possible for a 32-bit signed integer. So if you mod this value by any power of 3 there will be no remainder.
    bool isPowerOfThree(int n) {  
        if (n<=0) return false;
        return n > 0 && 1162261467 % n == 0;
    }  
};
```

**14) Imp  properties in bit manipulation**

```cpp
1.We can find the minimum XOR of two elements in an array just by
sorting the array and taking the minimum of XOR-s of neighboring elements.
2.To find the maximum XOR of two elements we can use the trie data structure. [How?]
And One other Method i have discussed above
3.We can use bitmasks to solve problems related to the inclusion-exclusion principle

1) xor of a same number with itself is zero, i.e A ^ A = 0
2) xor is commutative that means a ^ b = b ^ a.
3) xor of any number with zero is the number itself i.e A ^ 0 = A.

x&1 gives the lowest bit(helps in finding whether number is even or odd
i.e if last bit is 0 then it is even otherwise odd)
x & (x-1) will clear the lowest set bit of x
x & ~(x-1) extracts the lowest set bit of x (all others are clear). 
Pretty patterns when applied to a linear sequence.
x & (x + (1 0<< n)) = x, with the run of set bits (possibly length 0) starting at bit n cleared.
x & ~(x + (1 << n)) = the run of set bits (possibly length 0) in x, starting at bit n.
x | (x + 1) = x with the lowest cleared bit set.
x | ~(x + 1) = extracts the lowest cleared bit of x (all others are set).
x | (x - (1 << n)) = x, with the run of cleared bits (possibly length 0) starting at bit n set.
x | ~(x - (1 << n)) = the lowest run of cleared bits (possibly length 0) in x, starting at bit n are the only clear bits.

Set union A | B
Set intersection A & B
Set subtraction A & ~B
Set negation ALL_BITS ^ A or ~A
Set bit A |= 1 << bit
Clear bit A &= ~(1 << bit)
Test bit (A & 1 << bit) != 0
Extract last bit A&-A or A&~(A-1) or x^(x&(x-1))
Remove last bit A&(A-1)
Get all 1-bits ~0==-1
----------------------------------------------------------------------------
Some properties of bitswise operators:

a. Addition:

1.  a+b = a|b + a&b
Now this is a very basic thing.
But how did we get this? Suppose we have two binary numbers 1010 and 0101, there is no chance of any carry in binary addition.In that case we can write :
a+b =a|b
But when we have carry, suppose we have : 1101(a) and 0101(b) then a & b works as the carry which we add further and the equation turns into :

a+b=a|b + a&b

2. a+b=a⊕b+2(a&b)
It comes from the first equation that I described.But now let's break a & b here and bring xor into action:

We can express a | b as a⊕b + a&b which brings the equation :

a+b=a⊕b+2(a&b)

Here  is above explained Addition props:
1. (a|b) = (a+b) - (a&b)    
 This is helpful when we want to related AND/OR operations with sum.

2. (a+b) = (a^b) + 2*(a&b)  
 This one is a very special relation which can be used to solve some seemingly
 very tough questions.
b. Subtraction:

a-b = (a⊕(a&b))-((a|b)⊕a)
a-b = ((a|b)⊕b)-((a|b)⊕a)
a-b = (a⊕(a&b))-(b⊕(a&b))
a-b = ((a|b)⊕b)-(b⊕(a&b))
c. More Operations

a|b = a⊕b + a&b
a⊕(a&b) = (a|b)⊕b
b⊕(a&b) = (a|b)⊕a
(a&b)⊕(a|b) = a⊕b

```

**15) Max xor of two numbers is array** 

```cpp
/* 
Logic: for a 32 bit number we have 32 bits in memory, so in order to
find the largest possible value of an XOR operation, the value of XOR
should have most of the bits set (i.e. 1) starting from the left to right
*/

void solve(int target,vector<int>&nums,int &ans)
    {
        unordered_set<int>s;
        for(auto dig:nums)
        {  
             auto digit=((target&dig));
            if(s.count(digit^target)!=0)
            { 
               ans=target;   
               return ;
             }
              s.insert(digit);
        }
    }
    int findMaximumXOR(vector<int>& nums) 
    {
      int ans=0;
      for(int i=31;i>=0 ;i--)
      solve((ans| (1<<i)),nums,ans);
      return ans;
     
    }
```

**15) Playing with kth bit**

```cpp
//Print the kth bit 
//or
//Position of kth bit (from last)
int printKthBit(int n, int k) {
    return (n >> (k - 1)) & 1;
}

//Turn off k’th bit in a number (**kth from last** )
//Clear the k'th bit in a number 
//If there is 0 leave it otherwise if there is 1 change it to 0
int turnOffKthBit(int n, int k) {
    return n & ~(1 << (k - 1));
}

//Turn On k’th bit in a number (**kth from last** )
//Set k'th bit in a number 
//If there is 1 leave it otherwise if there is 0 change it to 1
int turnOnKthBit(int n, int k) {
    return n | (1 << (k - 1));
}

//Check if k’th bit is set for a number (**kth from last** )
bool isKthBitSet(int n, int k) {
    return (n & (1 << (k - 1))) != 0;
}

//Toggle the k’th bit
int toggleKthBit(int n, int k) {
    return n ^ (1 << (k - 1));
}

//Clear last k bits
void ClearLastKBits()
 {
      int n,k;
      cin>>n>>k;
      cout<< ((n>>k)<<k);
      
 }

//clear bits between range i to j (from last)
int performCalculation(int j, int i, int n) {
    int x = (~0) << j;
    int y = (1 << (i - 1)) - 1;
    int z = x | y;
    return (n & z);
}

int main() {
    INOUTERR
    int j, i, n;
    
    cin >> n;
    cin >> i;
    cin >> j;

    // Call the calculation function and output the result
    int result = performCalculation(j, i, n);
    cout << "Result: " << result << endl;

    return 0;
}

//Replace Bits using bitwise operator
int performCalculation(int j, int i, int n,int m) {
    int x = (~0) << j;
    int y = (1 << (i - 1)) - 1;
    int z = x | y;
    int a = (m & z);
    int b = n<<(i-1);
    return a | b;
}

int main() {
    INOUTERR
    int j, i, n, m;

    cin >> m;
    cin >> n;
    cin >> i;
    cin >> j;

    
    int result = performCalculation(j, i, n, m);
    cout << "Result: " << result << endl;

    return 0;
}

```

**16) Find the position of the rightmost set bit**

```cpp
int positionOfRightmostSetBit(int n)
{
    // if the number is odd, return 1
    if (n & 1) {
        return 1;
    }
 
    return log2(n & -n) + 1;
}
Note: If (n & -n) == n, then the positive integer n is a power of 2.
```

17)**count set bits in an integer(Brian Kernighan’s Algorithm)**

```cpp
The expression n & (n-1) can be used to turn off the rightmost set bit of a number n. 
This works as the expression n-1 flips all the bits after the rightmost set bit of n,
including the rightmost set bit itself. Therefore, n & (n-1) 
results in the last bit flipped of n.

int countSetBits(int n)
{
    // `count` stores the total bits set in `n`
    int count = 0;
 
    while (n)
    {
        n = n & (n - 1);    // clear the least significant bit set
        count++;
    }
 
    return count;
}
```

18) **Find minimum or maximum of two integers using bit manipulation**

```cpp
int findMin(int x, int y) {
    return y ^ ((x ^ y) & -(x < y));
}
 
int findMax(int x, int y) {
    return x ^ ((x ^ y) & -(x < y));
}
```

**19) In an array nums every element appears *twice* except for one. Find that single one.(XOR method)**

```cpp
Single Number 1
//Leetcode link:  https://leetcode.com/problems/single-number/
int singleNumber(vector<int>& nums) 
{
         int n=nums.size();
         int ans = 0;
        for(int i=0; i<n; i++){
            ans ^= nums[i];
        }
        return ans;
 }
```

20)**Given an integer array `nums` where every element appears three times except for one, which appears exactly once. *Find the single element and return it*.**

```cpp
Single Number 2
//Leetcode link: https://leetcode.com/problems/single-number-ii/description/
int singleNumber(vector<int>& nums) {
    int ones = 0, twos = 0;
    
    for (int num : nums) {
        ones = (ones ^ num) & ~twos;
        twos = (twos ^ num) & ~ones;
    }
    
    return ones;
   }
```

21) Generate subsets using bit manipulation

```cpp
#include <iostream>
#include <vector>

using namespace std;

int power_solve(int base, int power) {
    int ans = 1;
    while (power > 0) {
        if (power % 2) {
            ans = ans * base;
            power--;
        } else {
            base = base * base;
            power /= 2;
        }
    }
    return ans;
}

int main() {
    string s;
    cin >> s;
    int N = s.length();
    int end = power_solve(2, N) - 1;
    vector<string> ans;
    
    for (int num = 1; num <= end; num++) {
        int cur_pos = 0;
        string temp = "";
        int number = num;
        while (number > 0) {
            if ((number & 1) > 0) {
                temp += s[cur_pos];
            }
            cur_pos++;
            number = number >> 1;
        }
        ans.push_back(temp);
    }

    for (auto it : ans) {
        cout << it << endl;
    }

    return 0;
}
```

# BIT MANIPULATION ENDS HERE

```cpp
//Method 1: Factorial of large numbers( according to github repo )

#define MOD 1000000007
const int maxN = 1e6;

auto factorial = [](int n) {
    vector<int> fact(maxN + 1, 1), inv(maxN + 1, 1);

    for (int z = 2; z <= maxN; z++) {
        inv[z] = (MOD - (MOD / z) * 1LL * inv[MOD % z] % MOD) % MOD;
        fact[z] = (1LL * z * fact[z - 1]) % MOD;
        inv[z] = (1LL * inv[z] * inv[z - 1]) % MOD;
    }

    return fact[n];
};
int main() {
    
    ll n;
    cin>>n;
 
    cout <<factorial(n) ;  

}

//Method 2: Sunyul bhaiya method
vector<int> solve(string a, int b) {
    int carry = 0;
    vector<int> ans;
    int i = a.size() - 1;
    
    while (i >= 0) {
        ans.push_back(((a[i] - '0') * b + carry) % 10);
        carry = ((a[i] - '0') * b + carry) / 10;
        i--;
    }
    
    while (carry != 0) {
        ans.push_back(carry % 10);
        carry /= 10;
    }
    
    reverse(ans.begin(), ans.end());
    
    return ans;
}

int main() 
{
    int n;
    cin >> n;

    string a = "1";
    int b = 1;
    vector<int> ans;
    
    while (b <= n) {
        ans = solve(a, b);
        a = "";
        b++;
        
        for (auto it : ans) {
            a += to_string(it);
        }
    }

    for (auto it : ans) {
        cout << it;
    }

    return 0;
}

```

```cpp
//Sum of two large numbers
vector<int> solve(string a, string b) {
    int i = a.size() - 1;
    int j = b.size() - 1;
    int carry = 0;
    vector<int> ans;

    while (i >= 0 || j >= 0) {
        int sum = carry;
        
        if (i >= 0) {
            sum += a[i] - '0';
            i--;
        }
        if (j >= 0) {
            sum += b[j] - '0';
            j--;
        }
        
        ans.push_back(sum % 10);
        carry = sum / 10;
    }

    if (carry != 0) {
        ans.push_back(carry);
    }

    reverse(ans.begin(), ans.end());

    return ans;
}

int main() {
    string a, b;
    cin >> a >> b;

    vector<int> ans = solve(a, b);

    for (auto it : ans) {
        cout << it;
    }
    cout << endl;

    return 0;
}
```

Taking a matrix input :

```cpp
int numRows, numCols;
    cin >> numRows >> numCols;
 
    Matrix A(numRows, vector<int>(numCols));
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numCols; ++j) {
            cin >> A[i][j];
        }
    }
 
    Matrix B(numRows, vector<int>(numCols));
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numCols; ++j) {
            cin >> B[i][j];
        }
    }
 
    Matrix result = addMatrices(A, B, numRows, numCols);
 
    // Printing the summation result
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numCols; ++j) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
 
  return 0;
```

If u dont want space after the last output value:

```cpp

if (t > 0) 
  cout << '\n';
else 
  cout.flush();
```

Exact value of pi:

```cpp
void solve() {
    int N;
    cin >> N;
 
    string pi_str = "3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679";
    string pi = pi_str.substr(0, N+2);
 
    cout << pi << endl;
}
```

# Sheet #1 (Data type - Conditions)

→Take input as string integer  and store into a vector as integers

```cpp
string s;
    cin >> s;
 
    vector<int> ans;
    for (int i = 0; i < s.size(); ++i)
    {
        int int_val = s[i] - '0';
        ans.push_back(int_val);
    }
```

→ Spliiting a string within a vector  as characters

```cpp
vector<char> v(s.begin(), s.end());
```

1. Typecasting to long long →

```cpp
long long int add = (long long)a+b;
```

1. Difference between products

```cpp
long long res = (long long)((a * b) - (c * d));
```

1. Area of circle using setprecision

```cpp
double r;
cin>>r;
    
    double ans= (double)(3.141592653*r*r);
    cout<<fixed<<setprecision(9);
    cout<<ans<<endl;

//input
2.00
//output
12.566370612
```

1. Sum of the last digits

```cpp
long long int a,b;
cin>>a>>b;
    
    long long int ld1=a%10;
    long long int ld2=b%10;
    
    cout<<ld1+ld2<<endl
//input
13 12 
//output
5
```

1. Sum of 1 to N

```cpp
ll res= a*(a+1)/2;
```

1. Floor ceil and round

```cpp
#define ll double  
   ll floorValue=floor (a/b);
   ll ceilValue = ceil (a/b);
   ll roundVAlue = round(a/b);
   
   cout<<"floor "<<a<<" / "<<b<<" = "<<floorValue<<endl;
   cout<<"ceil "<<a<<" / "<<b<<" = "<<ceilValue<<endl;
   cout<<"round "<<a<<" / "<<b<<" = "<<roundVAlue<<endl;
```

1. . Print "Multiples" if *A* is **multiple** of *B* or **vice versa**. Otherwise print "No Multiples".

```cpp
   if(a%b==0 || b%a==0) 
    cout<<"Multiples"<<endl;
   else
    cout<<"No Multiples"<<endl;
```

1. Max and min between 3 numbers a,b,c

```cpp
//normal method
ll max,min;
if(a>=b && a>=c) max =a;
else if (b>=a && b>=c) max =b;
else if (c>=a && c>=b) max =c;
 
if(a<=b && a<=c) min =a;
else if (b<=a && b<=c) min =b;
else if (c<= a && c<=b) min =c;
 
cout<<min<< " "<< max<<endl;

//using vector
	vector<int> v;
	int a,b,c;
	cin>>a>>b>>c;
	v.push_back(a);
	v.push_back(b);
	v.push_back(c);
 

  int maxi = INT_MIN;
  int mini = v[0];
  
    for(int i=0;i<v.size();i++)
    {
        
            if(maxi<v[i]) 
              maxi= v[i];
            if(mini>v[i]) 
              mini= v[i];
    }
  cout<<mini<<" "<<maxi<<endl;
```

1. The two persons are brothers if they **share the same second name**.

```cpp
    //taking 2 lines as input and separating strings 
    int t=1;
    while(t--)
    {
    string s1,s2;
    getline(cin,s1);
    getline(cin,s2);
    istringstream iss1(s1);
    istringstream iss2(s2);
    
  
    
      string firstWord1, secondWord1,firstWord2,secondWord2;
      iss1 >> firstWord1 >> secondWord1;
      iss2 >> firstWord2>> secondWord2;
 
    
      if(secondWord1==secondWord2 )
      {
         cout<<"ARE Brothers"<<endl;
         
      }
      
      else 
      {
      cout<<"NOT"<<endl;   
      }
// direct taking input first and second name and comparing the second name
		 string first1, second1, first2, second2;
		 cin >> first1 >> second1;
		 cin >> first2 >> second2;

      if(second1==second2 )
      { 
      cout<<"ARE Brothers"<<endl;
       }
      else
      {
           cout<<"NOT"<<endl;  
      }
```

1. Rough range of data types

![Screenshot 2023-07-17 at 9.55.12 AM.png](C++%20cheetsheet%20and%20snippets%20f60519c49fd14ea1ad0494cd5122d83e/Screenshot_2023-07-17_at_9.55.12_AM.png)

1. Calculations between 2 or more data types

![Screenshot 2023-07-17 at 9.57.07 AM.png](C++%20cheetsheet%20and%20snippets%20f60519c49fd14ea1ad0494cd5122d83e/Screenshot_2023-07-17_at_9.57.07_AM.png)

1. ASCII values
    
    ![Screenshot 2023-07-17 at 10.04.20 AM.png](C++%20cheetsheet%20and%20snippets%20f60519c49fd14ea1ad0494cd5122d83e/Screenshot_2023-07-17_at_10.04.20_AM.png)
    
2. Determine whether *X* is Digit or Alphabet and if it is Alphabet determine if it is **Capital Case** or **Small Case**.

```cpp
    char c;
    cin >> c;
    int res=(int)c;
    
    if(res>=48 && res<=57) 
        cout<<"IS DIGIT"<<endl;
    if(res>=65 && res <=90) 
    {
        cout<<"ALPHA"<<endl;
        cout<<"IS CAPITAL";   
    }
 
    if(res>=97 && res<=122) 
    {
        cout<<"ALPHA"<<endl;
        cout<< "IS SMALL"; 
    }
//Input 
A
//Output
ALPHA
IS CAPITAL
```

1. converting it from **lowercase letter to uppercase letter and vice versa**

```cpp
    
    char toUpper(char c)
    {
    return 'A' + (c - 'a');
    }
    
    char toLower(char c)
    {
    return 'a' + (c - 'A');
    }

   
	if(res>=97 && res<=122)
    {
        cout<<toUpper(c);
    }
    else if(res>=65 && res <=90)
    {
        cout<<toLower(c);
    }
```

1.  Calculate the result of these :     𝐴+𝐵 ,   𝐴−𝐵 ,  𝐴∗𝐵 and 𝐴/𝐵.

```cpp
//taking expression as input  directly as character  
int a,b;
    char oper;
    cin>>a>>oper>>b;
    switch(oper)
    {
        case '+': 
        cout<<(int)a+b;
        break;
        
        case '-': 
        cout<<(int)a-b;
        break;
        
        case '*': 
        cout<<(int)a*b;
        break;
        
        case '/': 
        cout<<(int)a/b;
        break;    
        
    }
```

1. Print "EVEN" if the first digit of X is **even number**. Otherwise print "ODD"

```cpp
string a;
    cin>>a;
    char first_letter=a[0];
    int res=(int)first_letter; //converting character to integer
    if(res%2==0) 
        cout<<"EVEN"<<endl;
    else 
        cout<<"ODD"<<endl;
```

1. Check which quadrant does the point lie ?

```cpp
	  double xCordi, yCordi;
    cin>>xCordi>>yCordi;
    
    if(xCordi>0 && yCordi>0) cout<<"Q1"<<endl; //quadrants
    if(xCordi<0 && yCordi>0) cout<<"Q2"<<endl;
    if(xCordi<0 && yCordi<0) cout<<"Q3"<<endl;
    if(xCordi>0 && yCordi<0) cout<<"Q4"<<endl;
    
    if(xCordi>=0 && yCordi==0) cout<<"Eixo X"<<endl; // on x and y axis
    if(xCordi==0 && yCordi<=0) cout<<"Eixo Y"<<endl;
    
    if(xCordi==0 && yCordi==0) cout<<"Origem"<<endl; //origin
```

1. Covert to year, month days 

```cpp
  int yr = n/365;
 int rem1 = n%365;
 
 int mo = rem1/30;
 int rem2 =rem1%30;
 
 int day = rem2;
 
 cout<<yr<<" years"<<endl;
 cout<<mo<<" months"<<endl;
 cout<<day<<" days"<<endl;

//input
 800
//Output
2 years
2 months
10 days
```

19 .Sort 3 numbers a,b,c

```cpp
ll A,B,C;
 
 cin>>A>>B>>C;
 
 ll maxi= max(A,max(B,C));
 ll mini;
 
 if(A<=B && A<=C) mini =A;
 else if(B<=A && B<=C) mini=B;
 else mini=C;
 
  //  373644 373644 454379
  ll rem = (ll)((A+B+C)-(mini+maxi));
 
  cout<<mini<<endl << rem<<endl<<maxi<<endl ;
  cout<<endl;
  
  cout<<A<<endl << B<<endl<<C ;
```

1. 
- If N is **float number** then print "**float**" followed by the **integer** part followed by **decimal** part separated by space.
- If N is **integer number** then print "**int**" followed by the **integer** part separated by space.
    
    ```cpp
        double number; 
        cin >> number;
     
        // Get the fractional and interger part of the number
        double fractionalPart = number - static_cast<int>(number);
        int integerPart = static_cast<int>(number);
        if(fractionalPart==0)
        {
            cout<<"int "<< integerPart<<endl;
        }
        else
        {
            cout<<"float "<<integerPart<<" "<< fractionalPart<<endl;;
        }
     
        return 0;
    
    //input
    534.958
    //output
    float 534 0.958
    ```
    
1. *A* < *B*, *A* > *B*, *A* = *B comparisons Right or Wrong* 

```cpp
int a, b;
    char dummy;
 
    scanf("%d %c %d", &a, &dummy, &b); //taking expressios as input
    
    bool result;
    switch(dummy)
    {   
        case '<':
         result = (a<b);
        break;
        
        case '>':
         result = (a>b);
        break;
        
        case '=':
         result = (a==b);
         break;
        
    }
    
    // cout<<result<<endl;
     if(result==true) cout<<"Right"<<endl;
     else cout<<"Wrong"<<endl;
```

1. Given the boundaries of **2** intervals. Print the boundaries of their **intersection**.
    
    ![Screenshot 2023-07-17 at 10.28.37 AM.png](C++%20cheetsheet%20and%20snippets%20f60519c49fd14ea1ad0494cd5122d83e/Screenshot_2023-07-17_at_10.28.37_AM.png)
    
    ```cpp
    int a, b, c, d;
        cin >> a >> b >> c >> d;
     
        int start = max(a, c);
        int end = min(b, d);
     
        if (start <= end) {
            cout << start << " " << end << endl;
        } else {
            cout << "-1" << endl;
        }
     
        return 0;
    ```
    
    1. Print last 2 digits of their multiplication(large numbers)
    
    ```cpp
    //soutik bhaiya code 
    int main()
       {
        long long a,b,c,d;
        cin >> a >> b >> c >> d;
        vector<long long>A = {a,b,c,d};
        sort(A.rbegin(),A.rend());
        long long peek = A[0]*A[1];
        a%=100;
        b%=100;
        c%=100;
        d%=100;
        int x = a*b*c*d;
        int last = x%10;
        x/=10;
        if(peek > 10) {
         cout << x%10;
        }
        cout << last;
      }
    
    //using binary multiplication
    typedef long long ll;
    const int M = 1e9 + 7;
     
    ll binMultiply(ll a, ll b) {
        ll ans = 0;
        a %= M;
        while (b > 0) {
            if (b & 1) {
                ans = (ans + a) ;
            }
            a = (a + a) ;
            b >>= 1;
        }
        return ans;
    }
     
    int main() {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
     
        // Calculate the product of all four numbers
        ll product = binMultiply(a, b);
        product = binMultiply(product, c);
        product = binMultiply(product, d);
     
        // Output the last two digits
        
        
        if (product >= 1000000000) {
            cout << "00" << endl;
        }
        else
        {
            cout << (product % 100) << endl;
        }
     
     
        return 0;
    }
    
    //using modulo property for multiplication
    #include <iostream>
    using namespace std;
    
    int moduloMultiply(int a, int b, int mod) {
        long long result = ((long long)a % mod) * (b % mod);
        return result % mod;
    }
    
    int last_two_digits_of_multiplication(int A, int B, int C, int D) {
        const int MOD = 100;
        int AB = moduloMultiply(A, B, MOD);
        int CD = moduloMultiply(C, D, MOD);
        int product = moduloMultiply(AB, CD, MOD);
        return product;
    }
    
    int main() {
        int A, B, C, D;
        cin >> A >> B >> C >> D;
    
        // Calculate and print the last two digits of the multiplication
        int result = last_two_digits_of_multiplication(A, B, C, D);
        cout << result << endl;
    
        return 0;
    }
    
    ```
    
    1. Given a,b,c,d .Print yes if `A power B`> `C power D`
    
    ```cpp
    long long a, b, c, d;
        cin >> a >> b >> c >> d;
     
        double val1 = b * log(a);
        double val2 = d * log(c);
     
        if (val1 > val2)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
     
        return 0;
    ```
    
    ## Contest 1 problems
    
    1. X=the discount percentage, 
    
         P= the price of the T-shirt after the discount.
    
        Print the price of the T-shirt before the discount rounded up to **two decimal places**.
    
    ```cpp
    #include <bits/stdc++.h>
     
    using namespace std;
     
    int main() {
        int X, P;
        cin >> X >> P;
     
        // Calculate the original price before the discount
        double originalPrice = P / (1 - static_cast<double>(X) / 100);
     
        // Round up the price to two decimal places
        originalPrice = ceil(originalPrice * 100) / 100;
     
        // Output the result with two decimal places
        cout << fixed << setprecision(2) << originalPrice << endl;
     
        return 0;
    }
    ```
    
    1. Memo and momo 
    
    ```cpp
    //
    If both 𝑎
     and 𝑏
     are divisible by 𝑘
    , both of them win and you should print "Both".
    If 𝑎
     is divisible by 𝑘
     but 𝑏
     isn't, Memo wins and you should print "Memo".
    If 𝑏
     is divisible by 𝑘
     but 𝑎
     isn't, Momo wins and you should print "Momo".
    If both 𝑎
     and 𝑏
     are not divisible by 𝑘
    , no one wins and you should print "No One".    
    
    ll a,b,k;
        cin>>a>>b>>k;
        
        if((a%k==0) && (b%k==0)) cout<<"Both"<<endl;
        if((a%k==0) && (b%k!=0)) cout<<"Memo"<<endl;
        if((a%k!=0) && (b%k==0)) cout<<"Momo"<<endl;
        if((a%k!=0) && (b%k!=0)) cout<<"No One"<<endl;
    
    ```
    
    1. Next alphabet 
    
    ```cpp
        char a;
        cin>>a;
        
        int asciiValue=(int)a+1; //converting character to ASCII value 
        
        if(asciiValue==123) 
        {
            cout<<"a"<<endl;
        }
        else
        {
        
        char character = static_cast<char>(asciiValue);  //ASCII value to character 
        cout<<character<<endl;
            
        }
    ```
    
    1. Ali Baba and Puzzle
    
    ![Screenshot 2023-07-17 at 10.48.55 AM.png](C++%20cheetsheet%20and%20snippets%20f60519c49fd14ea1ad0494cd5122d83e/Screenshot_2023-07-17_at_10.48.55_AM.png)
    
    Print "YES" (without quotes) if you get the fourth number using arithmetic operators, otherwise, print "NO" (without quotes).
    
    ```cpp
    		ll  a,b,c,d;
        cin>>a>>b>>c>>d;
    
        
        bool res2= (a + b - c == d);
        bool res3= (a + b * c == d);
        bool res4= (a - b + c == d);
        bool res6= (a - b * c == d);
        bool res7= (a * b + c == d);
        bool res8= (a * b - c == d);
        
        if((res2==true) ||(res3==true) ||(res4==true) ||(res6==true) ||(res7==true) ||(res8==true))
        {
            cout<<"YES"<<endl;
        } 
        else
        {
            cout<<"NO"<<endl;
        }
    ```
    
    1. Given two numbers a,b . You have to answer with "YES" if there is **a non-empty interval(unique)**
    
    ![Screenshot 2023-07-17 at 10.53.28 AM.png](C++%20cheetsheet%20and%20snippets%20f60519c49fd14ea1ad0494cd5122d83e/Screenshot_2023-07-17_at_10.53.28_AM.png)
    
    ```cpp
    string is_valid_interval(int a, int b) {
        if (a == 0 && b == 0) {
            return "NO";
        } else if (abs(a - b) <= 1) {
            return "YES";
        } else {
            return "NO";
        }
    }
    ```
    
    1. Adding 2 numbers bitwise 
        
        ![Screenshot 2023-07-17 at 10.56.24 AM.png](C++%20cheetsheet%20and%20snippets%20f60519c49fd14ea1ad0494cd5122d83e/Screenshot_2023-07-17_at_10.56.24_AM.png)
        
    
    ```cpp
    void full_adder(int a, int b, int& sum, int& carry) {
        sum = a ^ b ^ carry;
        carry = (a & b) | (carry & (a ^ b));
    }
     
    int main() {
        int a, b;
        cin >> a >> b;
     
        int sum = 0;
        int carry = 0;
     
        int bits = sizeof(int) * 8; // Number of bits in an integer
     
        for (int i = 0; i < bits; i++) {
            int bit_a = (a >> i) & 1;
            int bit_b = (b >> i) & 1;
            int bit_sum, bit_carry;
     
            full_adder(bit_a, bit_b, bit_sum, bit_carry);
     
            sum |= (bit_sum << i);
            carry = bit_carry;
        }
     
        cout  << sum << endl;
     
        return 0;
    }
    ```
    
    1. Largest number of Karyoshkas(statue) with eyes,body,mouth(unique)
        
        ![Screenshot 2023-07-17 at 10.57.49 AM.png](C++%20cheetsheet%20and%20snippets%20f60519c49fd14ea1ad0494cd5122d83e/Screenshot_2023-07-17_at_10.57.49_AM.png)
        
    
    ```cpp
        long long n, m, k, counter = 0, check;
        cin >> n >> m >> k;
        if (n == 0)
            cout << "0";
        else if (n == 1)
            cout << "1";
        else
        {
            check = min(n, min(m, k));
            counter += check;
            n -= check;
            m -= check;
            k -= check;
            n /= 2;
            check = min(n, k);
            counter += check;
            cout << counter;
        }
    ```
    
    32. Guess the data type
    
    ![Screenshot 2023-07-17 at 11.01.53 AM.png](C++%20cheetsheet%20and%20snippets%20f60519c49fd14ea1ad0494cd5122d83e/Screenshot_2023-07-17_at_11.01.53_AM.png)
    
    ```cpp
    int main() 
    {
        double num1, num2, num3;
        cin >> num1 >> num2 >> num3;
     
        double result = (num1 * num2) / num3;
        long long myNumber = result;
        double myRes = result - myNumber;
     
        if (myRes > 0) {
            cout << "double" << endl;
        } else if (myNumber <= 2147483647) {
            cout << "int" << endl;
        } else {
            cout << "long long" << endl;
        }
     
        return 0;
    }
    ```
    
    # PATTERNS
    
    Default pattern
    
    ```cpp
    //Square pattern
    #include <iostream>
    using namespace std;
    int main()
    {
        int n;
        cin >> n;
    
        int i = 0;
        while (i < n) // rows
        {
            int j = 0;
            while (j < n)
            {
                cout << "*";
                j = j + 1;
            }
            cout << endl;
            i = i + 1;
        }
    }
    
    *****
    *****
    *****
    *****
    *****
    ```
    
    ```cpp
    
    //Square pattern with numbers 
    #include <iostream>
    using namespace std;
    
    int main() {
        int n;
        cin >> n;
    
        int i = 1;            //i started from 1
        while (i <= n) {      // <=n
            int j = 1;        //j started from 1
            while (j <= n) {
                cout << i;    //cout<<i
                j = j + 1;
            }
            cout << endl;
            i = i + 1;
        }
    
        return 0;
    }
    
    // 11111
    // 22222    
    // 33333
    // 44444
    // 55555
    ```
    
    ```cpp
    
    #include <iostream>
    using namespace std;
    
    int main() {
        int n;
        cin >> n;
    
        int i = 1;            
        while (i <= n) {     
            int j = 1;        
            while (j <= n) {
                cout << n-j+i;    //cout<<n-j+i
                j = j + 1;
            }
            cout << endl;
            i = i + 1;
        }
    
        return 0;
    }
    // 54321
    // 54321
    // 54321    
    // 54321
    // 54321
    ```
    
    ```cpp
    #include <iostream>
    using namespace std;
    
    int main() {
        int n;
        cin >> n;
    
        int i = 1; 
        int count=1;   // int count =1(outside while loop of i)
        while (i <= n) {     
            int j = 1;        
            while (j <= n) {
                cout <<count;    // cout<<count;(inside while loop of j)
                count =count +1; //  count=count +1;
                j = j + 1;
            }
            cout << endl;
            i = i + 1;
        }
    
        return 0;
    }
    
    // 5
    // 1 2 3 4 5        --> int count =1(outside while loop of i)
    // 6 7 8 9 10
    // 11 12 13 14 15       cout<<count;(inside while loop of j)
    // 16 17 18 19 20       count=count +1;
    // 21 22 23 24 25
    ```
    
    ```cpp
    #include <iostream>
    using namespace std;
    
    int main() {
        int n;
        cin >> n;
    
        int i = 1; 
        int count=1;  
        while (i <= n) {     
            int j = 1;        
            while (j <= i) { // while(j<=i)
                cout <<"* ";     // cout<<"* "
                count =count +1; 
                j = j + 1;
            }
            cout << endl;
            i = i + 1;
        }
    
        return 0;
    }
    
    // 5
    // *
    // * *             -->while(j<=i)
    // * * *
    // * * * *            cout<<"* "
    // * * * *  *
    ```
    
    ```cpp
    #include <iostream>
    using namespace std;
    
    int main() {
        int n;
        cin >> n;
    
        int i = 1; 
        int count=1;  
        while (i <= n) {     
            int j = 1;        
            while (j <= i) { //while(j<=i)
                cout <<i;    // cout<<i;
                count =count +1; 
                j = j + 1;
            }
            cout << endl;
            i = i + 1;
        }
    
        return 0;
    }
    // 4
    // 1               -->while(j<=i)
    // 22                 cout<<i;
    // 333
    // 4444
    ```
    
    ```cpp
    #include <iostream>
    using namespace std;
    
    #include <iostream>
    using namespace std;
    
    int main() {
        int n;
        cin >> n;
    
        int i = 1; 
        int count=1;   //int count =1(outside while loop of i)
        while (i <= n) {     
            int j = 1;        
            while (j <= i) { //while(j<=i)
                cout <<count;    // cout<<count;
                count =count+1;  // count=count +1;
                j = j + 1;
            }
            cout << endl;
            i = i + 1;
        }
    
        return 0;
    }
    // 4
    // 1               --> int count =1(outside while loop of i)
    // 2 3                 while(j<=i)
    // 4 5 6               cout<<count;(inside while loop of j)
    // 7 8 9 10            count=count +1;
    ```
    
    ```cpp
    
    #include <iostream>
    using namespace std;
    
    int main() {
        int n;
        cin >> n;
    
        int i = 1; 
        while (i <= n) {     
            int j = 1;
            int count = i; // Initialize count to the current row number
            while (j <= i) {  // while(j<=i)
                cout << count << " ";  //cout<<count;
                count = count + 1; // count=count +1;
                j = j + 1;
            }
            cout << endl;
            i = i + 1;
        }
    
        return 0;
    }
    //   6
    //   1
    //   2 3
    //   3 4 5       -->int count = i;(outside while loop of j) [Exception_1]
    //   4 5 6 7        while(j<=i)
    //   5 6 7 8 9      cout<<count;(inside while loop of j)
    //   6 7 8 9 10 11  count=count +1;
    ```
    
    ```cpp
    
    #include <iostream>
    using namespace std;
    
    int main() {
        char count = 'A';
        int n;
        cin >> n;
    
        int i = 1;
        while (i <= n) {
            int j = 1;
            while (j <= n) {
                cout << count;
                count = count + 1;
                j = j + 1;
            }
            cout << endl;
            i = i + 1;
        }
    
        return 0;
    }
    
    // ABCDE     -->char count ='A';(outside i)
    // FGHIJ        cout<<count;
    // KLMNO        count=count+1;
    // PQRST
    // UVWXY
    ```
    
    ```cpp
    #include <iostream>
    using namespace std;
    
    int main() {
        char count = 'A';
        int n;
        cin >> n;
    
        int i = 1;
        while (i <= n) {
            int j = 1;
            while (j <= n) {
                char ch = count + i - 1; // Calculate the character to be printed
                cout << ch;
                j = j + 1;
            }
            cout << endl;
            i = i + 1;
        }
    
        return 0;
    }
    4
    //A A A A     -->char count ='A';(outside j)[Exception_2]
    //B B B B        cout<<count+i-1;(store in another char before print)
    //C C C C
    //D D D D
    ```
    
    ```cpp
    
    #include <iostream>
    using namespace std;
    
    int main() {
        char count = 'A';
        int n;
        cin >> n;
    
        int i = 1;
        while (i <= n) {
            int j = 1;
            while (j <= n) {
                cout << static_cast<char>(count + i + j - 2); // Cast the value to char
                j = j + 1;
            }
            count = count + 1; // Increment count to get the next character
            cout << endl;
            i = i + 1;
        }
    
        return 0;
    }
    // 5
    // A B C D E -->char count ='A';(outside i)
    // B C D E F    cout<<count+i+j-2; (store in another char before print)
    // C D E F G
    // D E F G H
    // E F G H I
    ```
    
    ```cpp
    #include <iostream>
    using namespace std;
    
    int main() {
        char count = 'A';
        int n;
        cin >> n;
    
        int i = 1;
        while (i <= n) {
            int j = 1;
            while (j <= i) {
                cout << static_cast<char>(count + i - 1); // Cast the value to char
                j = j + 1;
            }
            cout << endl;
            i = i + 1;
        }
    
        return 0;
    }
    // 5
    // A
    // BB  -->char count ='A'(outside i)
    // CCC    while(j<=i)
    // DDDD   cout<<count+i-1;(store in another char before print)
    // EEEEE
    ```
    
    ```cpp
    
    #include <iostream>
    using namespace std;
    
    int main() {
        char count = 'A'; // Step 1: Set count to 'A'
        int n;
        cin >> n;
    
        int i = 1;
        while (i <= n) { // Step 2: Start the outer loop
            int j = 1;
            while (j <= i) { // Step 3: Start the inner loop
                char c = count + i - 1; // Step 4: Calculate the character to be printed
                cout << c; // Step 5: Print the character
                j = j + 1;
            }
            count = count + 1; // Step 6: Increment count to get the next character
            cout << endl; // Step 7: Move to the next line after each row
            i = i + 1; // Step 8: Move to the next row
        }
    
        return 0;
    }
    // 5
    // A
    // BB  -->char count ='A'(outside i)
    // CCC    while(j<=i)
    // DDDD   cout<<count+i-1;(store in another char before print)
    // EEEEE
    ```
    
    ```cpp
    #include <iostream>
    using namespace std;
    
    int main() {
        char count = 'A';
        int n;
        cin >> n;
    
        int i = 1;
        while (i <= n) {
            int j = 1;
            while (j <= i) {
                cout << count;
                count++;
                j = j + 1;
            }
            cout << endl;
            i = i + 1;
        }
    
        return 0;
    }
    // 4
    // A
    // BC   -->char count ='A'(outside i)
    // CDE     while(j<=i)
    // DEFG    cout<<count+i+j-2;(store in another char before print)
    ```
    
    ```cpp
    #include <iostream>
    using namespace std;
    
    int main()
    {
        int n = 4;
    
        int i = 1;
        while (i <= n)
        {
            int space = n - i;
            while (space)
            {
                cout << " ";
                space = space - 1;
            }
    
            int j = 1;
            while (j <= i)
            {
                cout << "*";
                j = j + 1;
            }
    
            cout << endl;
            i = i + 1;
        }
    
        return 0;
    }
    
       *
      **
     ***
    ****
    ```
    
    ```cpp
    #include <iostream>
    using namespace std;
     
    int main()
    {
        int n ;
        cin>>n;
        int i = 1;
        while (i <= n)
        {
            int space = n - i;
            while (space)
            {
                cout << " ";
                space = space - 1;
            }
     
            int j = 1;
            while (j <= 2 * i - 1)
            {
                cout << "*";
                j = j + 1;
            }
     
            cout << endl;
            i = i + 1;
        }
     
        return 0;
    }
    	 *
      * *
     * * *
    * * * *
    ```
    
    ```cpp
    #include <iostream>
    using namespace std;
    
    int main()
    {
        int n = 4;
    
        int i = n;
        while (i >= 1)
        {
            int j = 1;
            while (j <= i)
            {
                cout << "* ";
                j = j + 1;
            }
    
            cout << endl;
            i = i - 1;
        }
    
        return 0;
    }
    
    * * * * 
    * * * 
    * * 
    *
    ```
    
    # Input types(Taking inputs)
    
    ```cpp
    #include <iostream>
    #include <vector>
    
    using namespace std;
    
    int main() {
        int a,b,c;
         c=1;
        while (scanf("%d %d", &a, &b) != EOF)
        {
            printf("Case %d: %d\n\n", c++, a + b);
        }
    
    }
    
    {{{OR}}}
    
    #include <iostream>
    
    using namespace std;
    
    int main() {
        int a, b, c = 1;
    
        while (cin >> a >> b) {
            cout << "Case " << c++ << ": " << a + b << endl << endl;
        }
    
        return 0;
    }
    
    //Input 
    1 2 
    3 4
    5 6
    7 8
    //Output
    Case 1: 3
    
    Case 2: 7
    
    Case 3: 11
    
    Case 4: 15
    								-> Blank line at the last of the test case 
    --------------
    ```
    
    ```cpp
    #include <iostream>
    #include <vector>
    
    using namespace std;
    
    int main() {
        int a,b,c;
         c=1;
        while (scanf("%d %d", &a, &b) != EOF)
        {
            if(c>1) cout<<"\n";
            printf("Case %d: %d\n", c++, a + b);
        }
    }
    
    {{{OR}}}
    
    #include <iostream>
    
    using namespace std;
    
    int main() {
        int a, b, c = 1;
    
        while (cin >> a >> b) {
            if (c > 1) {
                cout << endl;
            }
            cout << "Case " << c++ << ": " << a + b << endl;
        }
    
        return 0;
    }
    
    //Input 
    1 2 
    3 4
    5 6
    7 8
    //Output
    Case 1: 3
    
    Case 2: 7
    
    Case 3: 11
    
    Case 4: 15					-> NO Blank line at the last of the test case 
    --------------
    ```
    
    ```cpp
    #include <iostream>
    
    int main() {
        int k, ans, v;
    
        while (scanf("%d", &k) != EOF) {
            ans = 0;
    
            while (k--) {
                scanf("%d", &v);
                ans += v;
            }
    
            printf("%d\n", ans);
        }
    
        return 0;
    }
    
    {{{{OR}}}}
    
    #include <iostream>
    
    using namespace std;
    
    int main() {
        int k, ans, v;
    
        while (cin >> k) {
            ans = 0;
    
            while (k--) {
                cin >> v;
                ans += v;
            }
    
            cout << ans << endl;
        }
    
        return 0;
    }
    //input 
    1 1
    2 3 4 
    3 8 1 1
    4 7 2 9 3
    5 1 1 1 1 1
    //output
    1
    7
    10
    21
    5
    ```
    
    ```cpp
    #include <iostream>
    #include <sstream>
    #include <string>
    
    using namespace std;
    
    int main() {
        string line;
        
        while (getline(cin, line)) {
            istringstream iss(line);
            int ans = 0, v;
            
            while (iss >> v) {
                ans += v;
            }
            
            cout << ans << endl;
        }
        
        return 0;
    }
    //input
    1 2 
    3 4
    5 6
    7 8
    //output
    3
    7
    11
    15
    ```
    
    # Hexa decimal
    
    ```cpp
    //https://www.hackerrank.com/challenges/prettyprint/problem
    #include <bits/stdc++.h>
    using namespace std;
    
    void solve(int t) {
        double a, b, c;
        cin >> a >> b >> c;
             cout<< noshowpos << left << hex << showbase << nouppercase; // formatting
            cout<< static_cast<long long>(a) << endl;
    
        // b -> Print it to a scale of  decimal places, preceded by a  or  sign (indicating if it's positive or negative), right justified, and left-padded with underscores so that the printed result is exactly  characters wide.
        cout << fixed << showpos << setprecision(2) << right << setw(15) << setfill('_') << b << endl;
    
        // c -> Print it to a scale of exactly nine decimal places, expressed in scientific notation using upper case.
        cout << fixed <<setprecision(9)<< noshowpos << scientific << uppercase <<c <<endl;
    }
    
    int main()
    {
        int t;
        cin>>t;
        while(t--)
        {
            solve(t);
        }
    }
    ```
