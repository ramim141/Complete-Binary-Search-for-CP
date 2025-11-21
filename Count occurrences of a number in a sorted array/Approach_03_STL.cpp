#include <bits/stdc++.h>
using namespace std;
int countOccurrences(vector<int>&a, int n, int x)
{
    auto first = lower_bound(a.begin(), a.end(), x);
    auto last = upper_bound(a.begin(), a.end(), x);
    return static_cast<int>(last - first);
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    return 0;
}