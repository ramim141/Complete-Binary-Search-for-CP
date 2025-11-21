// Educational Codeforces Round 2
// B. Queries about less or equal elements
// URL: https://codeforces.com/contest/600/problem/B

#include <bits/stdc++.h>
using namespace std;

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<long long>a(n);
    vector<long long>b(m);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for(int i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    // sort(b.begin(), b.end());
    for(int i = 0; i < m; i++)
    {
        cout << upper_bound(a.begin(), a.end(), b[i]) - a.begin() << " ";
    }


    return 0;
}