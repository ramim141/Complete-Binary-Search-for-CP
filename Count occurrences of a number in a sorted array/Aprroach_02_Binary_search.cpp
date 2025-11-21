#include <bits/stdc++.h>
using namespace std;

int finFirst(vector<int> &a, int x)
{
    int l = 0, r = a.size() - 1;
    int first = -1;

    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (a[mid] == x)
        {
            first = mid;
            r = mid - 1;
        }
        else if (a[mid] < x)
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    return first;
}

int finLast(vector<int> &a, int x){
    int l = 0, r = a.size() - 1;
    int last = -1;

    while(l <= r)
    {
        int mid = l + (r - l) / 2;
        if(a[mid] == x)
        {
            last  = mid;
            l = mid + 1;
        }
        else if(a[mid] < x)
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    return last;
}

int countOccurrences(vector<int> &a, int x)
{
    int first = finFirst(a, x);
    if (first == -1)
    {
        return 0;
    }
    int last = finLast(a, x);
    return last - first + 1;
}

  
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}