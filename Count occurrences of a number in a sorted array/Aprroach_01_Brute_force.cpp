// Time Complexity: O(n)
// Space Complexity: O(1)



#include <bits/stdc++.h>
using namespace std;

int countOccurrences(const vector<int>& arr, int target) {
    int count = 0;
    for (int num : arr) {
        if (num == target) {
            count++;
        }
    }
    return count;
}