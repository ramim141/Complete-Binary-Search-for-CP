#include <bits/stdc++.h>
using namespace std;

string t, p;
vector<int> a;

bool check(int k)
{
    vector<bool> v(t.length(), false);

    for (int i = 0; i < k; ++i)
    {
        v[a[i] - 1] = true;
    }

    int p_ptr = 0;
    for (int t_ptr = 0; t_ptr < t.length() && p_ptr < p.length(); ++t_ptr)
    {
        if (!v[t_ptr] && t[t_ptr] == p[p_ptr])
        {
            p_ptr++;
        }
    }

    return p_ptr == p.length();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t >> p;

    a.resize(t.length());
    for (int i = 0; i < t.length(); ++i)
    {
        cin >> a[i];
    }

    int low = 0;
    int high = t.length() - p.length();
    int ans = 0;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (check(mid))
        {
            ans = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    cout << ans << endl;

    return 0;
}