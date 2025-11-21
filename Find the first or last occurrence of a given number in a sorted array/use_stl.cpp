#include <bits/stdc++.h>
using namespace std;

vector<int> findFirstAndLastPosition_stl(const vector<int>& arr, int x) {
    // Find the first occurrence (lower bound)
    auto first_it = lower_bound(arr.begin(), arr.end(), x);
    
    // Check if the element was found
    if (first_it == arr.end() || *first_it != x) {
        return {-1, -1};
    }

    // Find the last occurrence
    auto last_it = upper_bound(arr.begin(), arr.end(), x);
    
    int first_idx = distance(arr.begin(), first_it);
    int last_idx = distance(arr.begin(), last_it) - 1;
    
    return {first_idx, last_idx};
}