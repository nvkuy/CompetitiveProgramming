#include <bits/stdc++.h>

using namespace std;

int t, n, k, ai, ml;
vector<int> na, po;
long long ans;

int main()
{
    scanf("%d", &t);
    while (t--) {
        na.clear(); po.clear();
        scanf("%d %d", &n, &k);
        for (int i = 0; i < n; i++) {
            scanf("%d", &ai);
            if (ai > 0)
                po.push_back(ai);
            if (ai < 0)
                na.push_back(abs(ai));
        }
        sort(po.begin(), po.end(), greater<int>());
        sort(na.begin(), na.end(), greater<int>());
        /*
        for (int i = 0; i < po.size(); i++)
            cout << po[i] << " ";
        cout << endl;
        for (int i = 0; i < na.size(); i++)
            cout << na[i] << " ";
        cout << endl;
        */
        ans = 0;
        for (int i = 0; i < po.size(); i += k)
            ans += (2 * po[i]);
        for (int i = 0; i < na.size(); i += k)
            ans += (2 * na[i]);
        ml = -1e9;
        if (po.size() > 0)
            ml = max(ml, po[0]);
        if (na.size() > 0)
            ml = max(ml, na[0]);
        if (ml < 0)
            ml = 0;
        printf("%lld\n", ans - ml);
    }

    return 0;
}
