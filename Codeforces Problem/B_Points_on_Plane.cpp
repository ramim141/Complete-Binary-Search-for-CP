// Problem: B. Points on Plane
// Contest: Educational Codeforces Round 145 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1809/problem/B


#include <bits/stdc++.h>
using namespace std;

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        long long chips = sqrtl(n);
        if (chips * chips >= n)
        {
            cout << chips - 1 << endl;
        }
        else
        {
            cout << chips << endl;
        }
    }

    return 0;
}