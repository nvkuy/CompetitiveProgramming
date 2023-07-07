#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<long long> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        int l = 0, r = 40, m;
        while (l < r)
        {
            m = (l + r) / 2;
            long long pre = 1e18;
            bool iok = true;
            for (int i = n - 1; i >= 0; i--)
            {
                long long cur = a[i];
                if (cur + (1LL << m) - 1 <= pre)
                    cur += (1LL << m) - 1;
                else
                    cur = max(cur, pre);
                if (cur > pre)
                {
                    iok = false;
                    break;
                }
                pre = cur;
            }
            if (iok)
                r = m;
            else
                l = m + 1;
        }
        cout << r << endl;
    }

    return 0;
}