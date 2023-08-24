Codestudio link : https://www.codingninjas.com/studio/problems/frog-jump_3621012
Atcoder link : https://atcoder.jp/contests/dp/tasks/dp_a
Recursion -> Memoization -> Tabulation -> Space optimiszation

Method 1: Recursion 

int recursion(int index, vector<int> &arr) 
{
    if (index == 0) return 0;

    int left = recursion(index - 1, arr) + abs(arr[index ] - arr[index - 1]);
    int right = INT_MAX;
    if(index>1) right = recursion(index - 2, arr) + abs(arr[index ] - arr[index - 2]);
    return min(left , right);

}


int frogJump(int n, vector<int> &heights)
{
   return recursion(n-1,heights);   
}

Method 2: Memoization 

#include<bits/stdc++.h>
int memoization(int index, vector<int> &arr,vector<int> &dp) 
{
    if (index == 0) return 0;

    if(dp[index]!=-1) return dp[index];
    int left = memoization(index - 1, arr,dp) + abs(arr[index ] - arr[index - 1]);
    int right = INT_MAX;
    if(index>1) right = memoization(index - 2, arr,dp) + abs(arr[index ] - arr[index - 2]);
    
    
    return dp[index] =  min(left , right);

}

int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n+1,-1);
    return memoization(n-1,heights,dp);   
}



Method 3: Tabulation

#include<bits/stdc++.h>
using namespace std;

int tabulation(int index, vector<int> &arr, vector<int> &dp) 
{
    dp[0] = 0; 

    for (int i = 1; i <= index; i++) 
    {
        int left = dp[i - 1] + abs(arr[i] - arr[i - 1]);
        int right = INT_MAX;
        if(i > 1) right = dp[i - 2] + abs(arr[i] - arr[i - 2]);
        
        dp[i] = min(left, right);
    }

    return dp[index];
}

int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n + 1, -1);
    return tabulation(n-1, heights, dp); 
}

Method 4: Space optimization

#include<bits/stdc++.h>
using namespace std;

int spaceOptimization(int index, vector<int> &arr) 
{
    int prev1 = 0;
    int prev2 = 0; 

    for (int i = 1; i <=index; i++) 
    {
        
        int left = prev1 + abs(arr[i] - arr[i - 1]);
        int right = INT_MAX;
        if(i > 1) right = prev2 + abs(arr[i] - arr[i - 2]);
        
        int curr = min(left, right);
        prev2=prev1 ;
        prev1=curr;

        
    }

    return prev1;
}

int frogJump(int n, vector<int> &heights)
{
    return spaceOptimization(n-1, heights); 
}


Atcoder submission(space optimization):
#include<bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using lld = long double;




/*----------------------CONTAINERS-------------------------*/
#define si             set <int>
#define vi             vector <int>
#define pii            pair <int, int>
#define vpi            vector <pii>
#define vpp            vector <pair<int, pii>>
#define mii            map <int, int>
#define umii           unordered_map <int, int>
#define mpi            map <pii, int>
#define spi            set <pii>
#define setinput       for (int i = 0; i < n; ++i) {int ele; cin>>ele;  s.insert(ele);}
#define mapinput       for (int i = 0; i < n; ++i) {int key; cin>>key; int val; cin>>val; mp[key] = val;}
#define unorderedmapinput  for (int i = 0; i < n; ++i) {int key; cin>>key; int val; cin>>val; ump[key] = val;}
/*--------VECTOR--------------------------------*/

#define srt(v)  sort(v.begin(),v.end()) // sort 
#define mxe(v)  *max_element(v.begin(),v.end())// find max element in vector
#define mne(v)  *min_element(v.begin(),v.end())// find min element in vector


/*----------------------MACROS-------------------------*/
#define endl           "\n"
#define sz(x)          ((int) x.size())
#define double         long double
#define que_max        priority_queue <int>
#define que_min        priority_queue <int, vi, greater<int>>
#define bug(...)       __f (#__VA_ARGS__, __VA_ARGS__)
#define print(a)       for(auto x : a) cout << x << " "; cout << endl
#define print1(a)      for(auto x : a) cout << x.F << " " << x.S << endl
#define print2(a,x,y)  for(int i = x; i < y; i++) cout<< a[i]<< " "; cout << endl
#define endl "\n"
#define pb push_back
#define ppb pop_back
#define MP make_pair
#define FOR(i,a,b) for(ll i = a ; i <= b ; ++i)
#define all(a) (a).begin(),(a).end()
#define sz(x) ((int) x.size())
#define F first
#define S second
#define ll long long int
 
/*-------------------MATH FUNCTIONS--------------------*/
ll expo(ll a,ll b,ll m) {ll res=1; while(b>0) {if(b&1) res=(res*a)%m; a=(a*a)%m; b=b>>1;} return res;}
ll mod_add(ll a,ll b,ll m) {a=(a%m); b=(b%m); return (((a%m)+(b%m))+m)%m;} 
ll mod_mul(ll a,ll b,ll m) {a=(a%m); b=(b%m); return (((a%m)*(b%m))+m)%m;}
ll mod_sub(ll a,ll b,ll m) {a=(a%m); b=(b%m); return (((a%m)-(b%m))+m)%m;}
ll ceil_div(ll a,ll b){if(a%b)return (a/b)+1; else return(a/b);}
 
/*--------------------CONSTANTS----------------------*/
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define PI 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679
 
/*---------------------------------------------------*/
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" -> "; _print(x); cerr << endl;
#else
#define debug(x)
#endif
 
/*--------------------DEBUGGING----------------------*/
void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
// void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}
 
template <class T, class V> void _print(pair <T, V> p);
template <class T, class V,class M> void _print(tuple <T, V, M> t);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}";}
template <class T, class V, class M> void _print(tuple <T, V, M> t) {cerr << "{"; _print(get<0>(t)); cerr << ","; _print(get<1>(t)); cerr << ","; _print(get<2>(t));cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(unordered_map<T, V> m) { cerr << "{ "; for (const auto& kv : m) cerr << "{" << kv.first << "," << kv.second << "}, "; cerr << "}";
}
// ================================== take ip/op like vector,pairs directly!==================================
template<typename typC,typename typD> istream &operator>>(istream &cin,pair<typC,typD> &a) { return cin>>a.first>>a.second; }
template<typename typC> istream &operator>>(istream &cin,vector<typC> &a) { for (auto &x:a) cin>>x; return cin; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const pair<typC,typD> &a) { return cout<<a.first<<' '<<a.second; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const vector<pair<typC,typD>> &a) { for (auto &x:a) cout<<x<<'\n'; return cout; }
template<typename typC> ostream &operator<<(ostream &cout,const vector<typC> &a) { int n=a.size(); if (!n) return cout; cout<<a[0]; for (int i=1; i<n; i++) cout<<' '<<a[i]; return cout; }

// -------- t test cases ---------------------------------------------------------

// void solve();
// void ttestcases(){
//     int t=1;
//     cin>>t;
//     while(t--)
//     {
//       solve();

//     }
// }

//===================================CODE==========================================



int spaceOptimization(int index, vector<int> &arr) 
{
    int prev1 = 0;
    int prev2 = 0; 

    for (int i = 1; i <=index; i++) 
    {
        
        int left = prev1 + abs(arr[i] - arr[i - 1]);
        int right = INT_MAX;
        if(i > 1) right = prev2 + abs(arr[i] - arr[i - 2]);
        
        int curr = min(left, right);
        prev2=prev1 ;
        prev1=curr;

        
    }

    return prev1;
}

int frogJump(int n, vector<int> &heights)
{
   
    return spaceOptimization(n-1, heights); 
}




     
     
/*-----------------------MAIN--------------------------*/
int main(){
    clock_t z = clock();

    ios_base::sync_with_stdio(false);cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("error.txt", "w", stderr);
    #endif

    freopen("input.txt", "r", stdin);      //Coment this
    freopen("output.txt", "w", stdout);    //Comment this
    

    // ttestcases();
    int n;cin>>n;
    vector<int> heights(n);
    for (int i = 0; i < n; ++i) cin>>heights[i];
    cout<<frogJump(n,heights);

    cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);
    
    return 0;
}

    





