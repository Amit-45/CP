1) Problem1: Student and grade 

There are N students in section A. The i-th student got Ai marks. The class teacher of section B was absent so sections A and B were merged. The students of section B did not want to humiliate themselves, so they decided to sit with students having the same marks as them. You are given the marks of students of section B in order of their entry in the class. You have to tell whether the i-th student of section B can sit with a student with the same marks as him. If there is at least 1 person in the room with the same marks, print ‘YES’ else print ‘NO’. (without the quotes)


void solve()
{
  //read n and m 
  int n, m; cin>>n>>m;

  //create a map 
  map<int,bool> mp;

  //for loop for inserting a1,a2,....an
  for(int i=0;i<n;i++) {
   int x; cin>>x; 
   mp[x]=1;             //if key not present create a new entry and if key is present return its reference 
}
  //for loop for inserting b1,b2,....bn
  for(int i=0;i<m;i++){
    int x; cin>>x;

    if(mp.count(x)){ //if key already present 
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
        mp[x]=1;      //if key not present create a new entry and if key is present return its reference 
    }
  }  
    
}


2) Problem2: Maximum in window


Array given, size of subarray given. Find the max of subarray.
4
9 3
1 2 3 1 4 5 2 3 6
  
B1 = max(1, 2, 3) = 3
B2 = max(2, 3, 1) = 3
B3 = max(3, 1, 4) = 4
B4 = max(1, 4, 5) = 5
B5 = max(4, 5, 2) = 5
B6 = max(5, 2, 3) = 5
B7 = max(2, 3, 6) = 6




Approach: Sliding window in deque: max of subarray of size k : O(N) approach

void solve()
{
  //sliding window in deque : Max of subarray 

  //  take size of array and size of window as input 
    int n; 
    int k; cin>>n;cin>>k;

  // take the input in array 
    int arr[n];

    for (int i = 0; i < n; ++i) cin>>arr[i];

  //declare a deque
    deque<int> dq;

  //add element in deque 
  for (int i = 0; i < k; ++i)  //k is the window size
  {
     //adding into the deque 
     while(!dq.empty() && dq.back()<arr[i]){
        dq.pop_back();
     }
     dq.push_back(arr[i]);

  }
  
for (int i = 0; i <= n - k; i++)  //n-k to prevent array out of bound 
{
    cout << dq.front() << " ";   // front will be te max element because we already compared while adding
    
    if (dq.front() == arr[i])  // ensures that the deque always contains the maximum element within the current window while the window slides through the array
        dq.pop_front();

    //remove from deque 
    if (i + k < n) {
        while (!dq.empty() && dq.back() < arr[i + k])
            dq.pop_back();
        dq.push_back(arr[i + k]);
    }
}


3.Problem3: Collisions


solve() {
    IOS
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m; //I read the number of objects and the available money.
        int ans = 0; // // I initialize a counter to keep track of the maximum number of objects that can be bought.
        map<int, int> m1;   // I create a map to store the products of values and frequencies for the first set of objects.

        for (int i = 0; i < n; ++i) {  // I calculate the products of these values and frequencies and store their frequencies in the map.
            int x, u;
            cin >> x >> u;
            m1[x*u]++;  
        }

      //For each object in the second set, I check if the product of its value and frequency exists in the map.
      //If it does, I increment the counter, decrease the count of that product in the map, and remove the entry if its count becomes 0.
        for (int i = 0; i < m; ++i) {
            int y, v;
            cin >> y >> v;  // Reading the values and frequencies of the second set of objects.
            if (m1.count(y*v)) { 
                ans++;
                m1[y*v]--;
                if (m1[y*v] == 0) {
                    m1.erase(y*v);
                }
            }
        }
        cout << ans << "\n";
    
}






4. 
There are N objects, and each object has some price. The price of ith object is Ai.
You have total money M, and you want to buy as many objects as possible.
Find the maximum objects that you can buy? 
  
Approach: O(n log n) sort the array -> check which is the last index where value is less than equal to money


->We read the number of objects 'n' and the available budget 'm' from the input.
->We create an array 'a' to store the prices of the objects 
->To optimize our approach, we sort the array 'a' in ascending order. This helps us process the least expensive items first, maximizing the number of objects we can buy.
-> We create an array 'prefixSum' to store the prefix sums of the sorted array 'a'. 
This array will help us determine the total cost of buying the first 'i' objects.
->We calculate the prefix sums by iterating through the sorted array 'a' and storing the cumulative sum up to that point in the 'prefixSum' array.
->Now comes the core logic of the code: we use the 'upper_bound' function to find the position of the first element in 'prefixSum' that is greater than 'm'. This effectively finds the index 'i' up to which we can buy objects within our budget.
->The difference between the iterator returned by 'upper_bound' and the beginning of 'prefixSum' gives us the count of objects we can buy while staying within budget 'm'. This count is assigned to the 'cnt' variable.

Finally, we output the 'cnt' value, which represents the maximum number of objects that can be bought with the given budget 'm'.

void solve()
{ 
        int n, m;
        cin >> n >> m;
        
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        
        sort(a, a + n);
        
        int prefixSum[n];
        prefixSum[0] = a[0];
        for (int i = 1; i < n; i++) {
            prefixSum[i] = prefixSum[i - 1] + a[i];
        }

        int cnt = upper_bound(prefixSum, prefixSum + n, m) - prefixSum;
        
        cout << cnt << "\n";
    }


5. Subset sum problem:

6. Find the sum of the minimum of all subarrays possible of array A






