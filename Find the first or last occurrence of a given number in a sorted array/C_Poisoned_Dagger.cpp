#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool check(ll k, ll h, vector<ll> &a)
{
    ll total_damage = 0;
    int n = a.size();
    for (int i = 0; i < n - 1; i++)
    {
        total_damage += min(k, a[i + 1] - a[i]);
    }
    total_damage += k; 
    return total_damage >= h;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        ll h;
        cin >> n >> h;
        vector<ll> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        ll low = 1;
        ll high = h;
        ll ans = h;

        while (low <= high)
        {
            ll mid = low + (high - low) / 2;
            if (check(mid, h, arr))
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        cout << ans << "\n";
    }

    return 0;
}