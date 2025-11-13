#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {

        cin >> arr[i];
    }

    while (k--)
    {
        int q;
        cin >> q;

        int l = 0;
        int r = n - 1;
        int ans = -1;

        while (l <= r)
        {
            int mid = l + (r - l) / 2;

            if (arr[mid] <= q)
            {
                ans = mid;
                l = mid + 1;
                // break;
            }
            else
            {
                r = mid - 1;
            }
        }
        //    if(ans == -1)
        //    {
        //         cout << 0 << endl;
        //    }
        //    else
        //    {
        //         cout << ans+1 << endl;
        //    }
        cout << ans + 1 << endl;
    }
}


/*
    logic: 
    1. find the upper bound of x(query element) in the array
    2. 1 -based index


*/