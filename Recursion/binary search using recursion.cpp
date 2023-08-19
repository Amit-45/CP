#include <iostream>

bool binarySearchUsingRecursion(int low, int high, int key, int arr[])
{
    // base case
    if (low <= high)
    {
        int mid = low + (high - low) / 2; // Calculate the middle index

        if (arr[mid] == key)
        {
            return true; // Key found at middle index
        }
        else if (arr[mid] < key)
        {
            return binarySearchUsingRecursion(mid + 1, high, key, arr); // Search in the right half
        }
        else
        {
            return binarySearchUsingRecursion(low, mid - 1, key, arr); // Search in the left half
        }
    }

    return false; // Key not found
}

int main()
{
    int arr[] = {1, 3, 4, 5, 6, 7, 8, 9, 10}; //array must be sorted
    int n = sizeof(arr) / sizeof(int);
    int key = 200; // Key to search for

    bool found = binarySearchUsingRecursion(0, n - 1, key, arr);

    if (found)
    {
        std::cout << "Key found!" << std::endl;
    }
    else
    {
        std::cout << "Key not found." << std::endl;
    }

    return 0;
}
