
## Table of Contents

- [Vectors](#vectors)
- [Deque](#deque)
- [List](#list)
- [Set](#set)
- [Map](#map)
- [Multi Set](#multi-set)
- [Multi Map](#multi-map)
- [Unordered Set](#unordered-set)
- [Unordered Map](#unordered-map)
- [Unordered Multi Set](#unordered-multi-set)
- [Unordered Multi Map](#unordered-multi-map)
- [Stack](#stack)
- [Queue](#queue)
- [Priority Queue](#priority-queue)

## Vectors

### Code Example

```cpp



#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<int> v;

    // Push elements to the vector
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    // Access elements using iterators
    cout << "Elements in the vector: ";
    for (auto it = v.begin(); it != v.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // Access elements using reverse iterators
    cout << "Elements in reverse order: ";
    for (auto rit = v.rbegin(); rit != v.rend(); ++rit) {
        cout << *rit << " ";
    }
    cout << endl;

    // Remove the last element
    v.pop_back();

    // Insert an element at a specific position
    auto it = v.begin() + 1;
    v.insert(it, 25);

    // Erase an element at a specific position
    auto eraseIt = v.begin() + 2;
    v.erase(eraseIt);

    // Sort the vector
    sort(v.begin(), v.end());

    // Print the sorted vector
    cout << "Sorted elements: ";
    for (auto num : v) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
```

## Deque

```cpp


#include <bits/stdc++.h>

using namespace std;

int main() {
    deque<int> dq;

    // Push elements to the back of the deque
    dq.push_back(10);
    dq.push_back(20);
    dq.push_back(30);

    // Push elements to the front of the deque
    dq.push_front(5);
    dq.push_front(15);

    // Access elements using iterators
    cout << "Elements in the deque: ";
    for (auto it = dq.begin(); it != dq.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // Access elements using reverse iterators
    cout << "Elements in reverse order: ";
    for (auto rit = dq.rbegin(); rit != dq.rend(); ++rit) {
        cout << *rit << " ";
    }
    cout << endl;

    // Access the front and back elements
    cout << "Front element: " << dq.front() << endl;
    cout << "Back element: " << dq.back() << endl;

    // Remove the last element
    dq.pop_back();

    // Remove the first element
    dq.pop_front();

    // Insert an element at a specific position
    auto it = dq.begin() + 1;
    dq.insert(it, 25);

    // Erase an element at a specific position
    auto eraseIt = dq.begin() + 2;
    dq.erase(eraseIt);

    // Sort the deque
    sort(dq.begin(), dq.end());

    // Print the sorted deque
    cout << "Sorted elements: ";
    for (int num : dq) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
```
## List

```cpp


#include <bits/stdc++.h>

using namespace std;

int main() {
    list<int> li;

    // Push elements to the back of the list
    li.push_back(10);
    li.push_back(20);
    li.push_back(30);

    // Push elements to the front of the list
    li.push_front(5);
    li.push_front(15);

    // Access elements using iterators
    cout << "Elements in the list: ";
    for (auto it = li.begin(); it != li.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // Access elements using reverse iterators
    cout << "Elements in reverse order: ";
    for (auto rit = li.rbegin(); rit != li.rend(); ++rit) {
        cout << *rit << " ";
    }
    cout << endl;

    // Access the front and back elements
    cout << "Front element: " << li.front() << endl;
    cout << "Back element: " << li.back() << endl;

    // Remove the first element
    li.pop_front();

    // Remove the last element
    li.pop_back();

    // Insert an element at a specific position
    auto it = li.begin();
    ++it;
    li.insert(it, 25);

    // Erase an element at a specific position
    auto eraseIt = li.begin();
    ++eraseIt;
    li.erase(eraseIt);

    // Sort the list
    li.sort();

    // Reverse the list
    li.reverse();

    // Print the list
    cout << "Sorted and reversed list: ";
    for (int num : li) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
```
## SET
```cpp


#include <bits/stdc++.h>

using namespace std;

int main() {
    set<int> s = {1, 2, 3, 4, 4};

    // Access elements using iterators
    cout << "Elements in the set: ";
    for (auto it = s.begin(); it != s.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // Access elements using reverse iterators
    cout << "Elements in reverse order: ";
    for (auto rit = s.rbegin(); rit != s.rend(); ++rit) {
        cout << *rit << " ";
    }
    cout << endl;

    // Insert an element into the set
    s.insert(5);

    // Erase an element using an iterator
    auto eraseIt = s.find(2);  // Find the iterator pointing to the element 2
    if (eraseIt != s.end()) {
        s.erase(eraseIt);
    }

    // Count occurrences of an element in the set
    int countOfThree = s.count(3);

    // Print the set
    cout << "Set elements after insert and erase: ";
    for (int num : s) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Count of '3' in the set: " << countOfThree << endl;

    return 0;
}
```
## MAP:
```cpp



#include <bits/stdc++.h>
using namespace std;

int main() {
    map<int, int> m;

    // Insert elements into the map
    m.insert(make_pair(1, 10));
    m.insert(make_pair(2, 20));
    m.insert(make_pair(3, 30));

    // Access elements using iterators
    cout << "Elements in the map: ";
    for (auto it = m.begin(); it != m.end(); ++it) {
        cout << "(" << it->first << "," << it->second << ") ";
    }
    cout << endl;

    // Access elements using reverse iterators
    cout << "Elements in reverse order: ";
    for (auto rit = m.rbegin(); rit != m.rend(); ++rit) {
        cout << "(" << rit->first << "," << rit->second << ") ";
    }
    cout << endl;

    // Check if the map is empty
    cout << "Is the map empty? " << (m.empty() ? "Yes" : "No") << endl;

    // Get the size of the map
    cout << "Size of the map: " << m.size() << endl;

    // Access the first key using iterators
    cout << "First key: " << m.begin()->first << endl;

    // Erase an element by key
    m.erase(2);

    // Clear all elements from the map
    m.clear();

    // Insert elements into the map again
    m.insert(make_pair(4, 40));
    m.insert(make_pair(5, 50));

    // Find an element in the map
    auto findIt = m.find(4);
    if (findIt != m.end()) {
        cout << "Element found: (" << findIt->first << "," << findIt->second << ")" << endl;
    } else {
        cout << "Element not found." << endl;
    }

    // Count occurrences of an element in the map
    int countOfFive = m.count(5);
    cout << "Count of '5' in the map: " << countOfFive << endl;

    // Access element using key
    cout << "Value at key '5': " << m[5] << endl;

    return 0;
}
```
## MULTI SET:
```cpp


#include <bits/stdc++.h>
using namespace std;

int main() {
    multiset<int> ms;

    // Insert elements into the multiset
    ms.insert(10);
    ms.insert(20);
    ms.insert(30);
    ms.insert(20);  // Duplicate element

    // Access elements using iterators
    cout << "Elements in the multiset: ";
    for (auto it = ms.begin(); it != ms.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // Access elements using reverse iterators
    cout << "Elements in reverse order: ";
    for (auto rit = ms.rbegin(); rit != ms.rend(); ++rit) {
        cout << *rit << " ";
    }
    cout << endl;

    // Insert an element into the multiset
    ms.insert(15);

    // Erase an element using an iterator
    auto eraseIt = ms.find(20);  // Find the iterator pointing to the element 20
    if (eraseIt != ms.end()) {
        ms.erase(eraseIt);
    }

    // Count occurrences of an element in the multiset
    int countOfTwenty = ms.count(20);
    cout << "Count of '20' in the multiset: " << countOfTwenty << endl;

    return 0;
}
```
## MULTI MAP:
```cpp


#include <bits/stdc++.h>
using namespace std;

int main() {
    multimap<int, int> mm;

    // Insert elements into the multimap
    mm.insert(make_pair(1, 10));
    mm.insert(make_pair(2, 20));
    mm.insert(make_pair(2, 25));  // Duplicate key
    mm.insert(make_pair(3, 30));

    // Access elements using iterators
    cout << "Elements in the multimap: ";
    for (auto it = mm.begin(); it != mm.end(); ++it) {
        cout << "(" << it->first << "," << it->second << ") ";
    }
    cout << endl;

    // Access elements using reverse iterators
    cout << "Elements in reverse order: ";
    for (auto rit = mm.rbegin(); rit != mm.rend(); ++rit) {
        cout << "(" << rit->first << "," << rit->second << ") ";
    }
    cout << endl;

    // Check if the multimap is empty
    cout << "Is the multimap empty? " << (mm.empty() ? "Yes" : "No") << endl;

    // Get the size of the multimap
    cout << "Size of the multimap: " << mm.size() << endl;

    // Erase elements with a specific key
    mm.erase(2);

    // Clear all elements from the multimap
    mm.clear();

    // Insert elements into the multimap again
    mm.insert(make_pair(4, 40));
    mm.insert(make_pair(5, 50));

    // Find elements with a specific key
    auto findRange = mm.equal_range(4);
    for (auto it = findRange.first; it != findRange.second; ++it) {
        cout << "Element found: (" << it->first << "," << it->second << ")" << endl;
    }

    // Count occurrences of an element with a specific key in the multimap
    int countOfFour = mm.count(4);
    cout << "Count of '4' in the multimap: " << countOfFour << endl;

    return 0;
}
```
## UNORDERED SET:
```cpp


#include <bits/stdc++.h>
using namespace std;

int main() {
    unordered_set<int> us;

    // Insert elements into the unordered_set
    us.insert(10);
    us.insert(20);
    us.insert(30);

    // Access elements using iterators
    cout << "Elements in the unordered_set: ";
    for (auto it = us.begin(); it != us.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // Insert an element into the unordered_set
    us.insert(15);

    // Erase an element using an iterator
    auto eraseIt = us.find(20);  // Find the iterator pointing to the element 20
    if (eraseIt != us.end()) {
        us.erase(eraseIt);
    }

    // Count occurrences of an element in the unordered_set
    int countOfFifteen = us.count(15);
    cout << "Count of '15' in the unordered_set: " << countOfFifteen << endl;

    return 0;
}
```
## UNORDERED MAP
```cpp


#include <bits/stdc++.h>
using namespace std;

int main() {
    unordered_map<int, int> um;

    // Insert elements into the unordered_map
    um.insert(make_pair(1, 10));
    um.insert(make_pair(2, 20));
    um.insert(make_pair(3, 30));

    // Access elements using iterators
    cout << "Elements in the unordered_map: ";
    for (auto it = um.begin(); it != um.end(); ++it) {
        cout << "(" << it->first << "," << it->second << ") ";
    }
    cout << endl;

    // Check if the unordered_map is empty
    cout << "Is the unordered_map empty? " << (um.empty() ? "Yes" : "No") << endl;

    // Get the size of the unordered_map
    cout << "Size of the unordered_map: " << um.size() << endl;

    // Erase an element by key
    um.erase(2);

    // Clear all elements from the unordered_map
    um.clear();

    // Insert elements into the unordered_map again
    um.insert(make_pair(4, 40));
    um.insert(make_pair(5, 50));

    // Find an element in the unordered_map
    auto findIt = um.find(4);
    if (findIt != um.end()) {
        cout << "Element found: (" << findIt->first << "," << findIt->second << ")" << endl;
    } else {
        cout << "Element not found." << endl;
    }

    // Count occurrences of an element in the unordered_map
    int countOfFive = um.count(5);
    cout << "Count of '5' in the unordered_map: " << countOfFive << endl;

    // Access element using key (note: this syntax is also available for unordered_map)
    um[4] = 44;
    cout << "Value at key '4': " << um[4] << endl;

    return 0;
}
```
## UNORDERED MULTI SET:
```cpp
UNORDERED MULTI SET:

#include <bits/stdc++.h>
using namespace std;

int main() {
    unordered_multiset<int> uoms;

    // Insert elements into the unordered_multiset
    uoms.insert(10);
    uoms.insert(20);
    uoms.insert(30);
    uoms.insert(20);  // Duplicate element

    // Access elements using iterators
    cout << "Elements in the unordered_multiset: ";
    for (auto it = uoms.begin(); it != uoms.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // Erase an element using an iterator
    auto eraseIt = uoms.find(20);  // Find the iterator pointing to the element 20
    if (eraseIt != uoms.end()) {
        uoms.erase(eraseIt);
    }

    // Count occurrences of an element in the unordered_multiset
    int countOfTwenty = uoms.count(20);
    cout << "Count of '20' in the unordered_multiset: " << countOfTwenty << endl;

    return 0;
}
```
## UNORDERED MULTI MAP

```cpp


#include <bits/stdc++.h>
using namespace std;

int main() {
    unordered_multimap<int, int> uommp;

    // Insert elements into the unordered_multimap
    uommp.insert(make_pair(1, 10));
    uommp.insert(make_pair(2, 20));
    uommp.insert(make_pair(2, 25));  // Duplicate key
    uommp.insert(make_pair(3, 30));

    // Access elements using iterators
    cout << "Elements in the unordered_multimap: ";
    for (auto it = uommp.begin(); it != uommp.end(); ++it) {
        cout << "(" << it->first << "," << it->second << ") ";
    }
    cout << endl;

    // Check if the unordered_multimap is empty
    cout << "Is the unordered_multimap empty? " << (uommp.empty() ? "Yes" : "No") << endl;

    // Get the size of the unordered_multimap
    cout << "Size of the unordered_multimap: " << uommp.size() << endl;

    // Erase elements with a specific key
    uommp.erase(2);

    // Clear all elements from the unordered_multimap
    uommp.clear();

    // Insert elements into the unordered_multimap again
    uommp.insert(make_pair(4, 40));
    uommp.insert(make_pair(5, 50));

    // Find elements with a specific key
    auto findRange = uommp.equal_range(4);
    for (auto it = findRange.first; it != findRange.second; ++it) {
        cout << "Element found: (" << it->first << "," << it->second << ")" << endl;
    }

    // Count occurrences of an element with a specific key in the unordered_multimap
    int countOfFour = uommp.count(4);
    cout << "Count of '4' in the unordered_multimap: " << countOfFour << endl;

    // Access element using key (note: this syntax is also available for unordered_multimap)
    uommp.insert(make_pair(4, 44));  // Insert a new pair
    uommp[4] = 444;  // Modify the value associated with key '4'
    cout << "Value at key '4': " << uommp[4] << endl;

    return 0;
}
```
## STACK:
```cpp


#include <bits/stdc++.h>
using namespace std;

int main() {
    stack<int> s;

    // Push elements onto the stack
    s.push(10);
    s.push(20);
    s.push(30);

    // Get the size of the stack
    cout << "Size of the stack: " << s.size() << endl;

    // Check if the stack is empty
    cout << "Is the stack empty? " << (s.empty() ? "Yes" : "No") << endl;

    // Access the top element
    cout << "Top element of the stack: " << s.top() << endl;

    // Pop elements from the stack
    s.pop();

    // Access the new top element
    cout << "Top element of the stack after pop: " << s.top() << endl;

    return 0;
}
```
## QUEUE

```cpp


#include <bits/stdc++.h>
using namespace std;

int main() {
    queue<int> q;

    // Push elements into the queue
    q.push(10);
    q.push(20);
    q.push(30);

    // Get the size of the queue
    cout << "Size of the queue: " << q.size() << endl;

    // Check if the queue is empty
    cout << "Is the queue empty? " << (q.empty() ? "Yes" : "No") << endl;

    // Access the front and back elements
    cout << "Front element of the queue: " << q.front() << endl;
    cout << "Back element of the queue: " << q.back() << endl;

    // Pop elements from the queue
    q.pop();

    // Access the new front element
    cout << "Front element of the queue after pop: " << q.front() << endl;

    return 0;
}
```
## PRIORIRY QUEUE
```cpp


#include <bits/stdc++.h>
using namespace std;

int main() {
    priority_queue<int> pq;

    // Push elements into the priority queue
    pq.push(30);
    pq.push(10);
    pq.push(20);

    // Get the size of the priority queue
    cout << "Size of the priority queue: " << pq.size() << endl;

    // Check if the priority queue is empty
    cout << "Is the priority queue empty? " << (pq.empty() ? "Yes" : "No") << endl;

    // Access the top element
    cout << "Top element of the priority queue: " << pq.top() << endl;

    // Pop elements from the priority queue
    pq.pop();

    // Access the new top element
    cout << "Top element of the priority queue after pop: " << pq.top() << endl;

    return 0;
}
```
