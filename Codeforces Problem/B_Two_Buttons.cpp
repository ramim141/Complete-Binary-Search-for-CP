// Codeforces Round 295 (Div. 2)
// Problem: B. Two Buttons
// URL: https://codeforces.com/contest/520/problem/B

#include <bits/stdc++.h>
using namespace std;

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    if(n >= m)
    {
        cout << n-m<< endl;
    }
    else{
        int s = 0;
        while(( m > n))
        {
            if( m% 2 ==0)
            {
                m/=2;
            }
            else{
                m++;
            }
            s++;
        }
        cout << s + (n - m) << endl;
    }

    return 0;
}