#include <bits/stdc++.h>
using namespace std;

// find first occurrence
int FindFirst(int arr[], int n, int x)
{
    int low = 0;
    int high = n - 1;
    int ans = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == x)
        {
            ans = mid;
            high = mid - 1; // Move to the left half
        }
        else if (arr[mid] < x)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return ans;
}

// find last occurrence
int FindLast(int arr[], int n, int x)
{
    int low = 0, high = n - 1;
    int ans = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == x)
        {
            ans = mid;
            low = mid + 1; // Move to the right half to find the last occurrence
        }
        else if (arr[mid] < x)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return ans;
}

pair<int, int> firstOcc(int arr[], int n, int x)
{
    int first = FindFirst(arr, n, x);
    int last = FindLast(arr, n, x);
    if (first == -1 || last == -1)
    {
        return make_pair(-1, -1);
    }
    return make_pair(first, last);
}