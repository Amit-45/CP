1. 


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


2. Sliding window in deque: max of subarray of size k : O(N) approach

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




