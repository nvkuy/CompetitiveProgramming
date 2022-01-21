#include <bits/stdc++.h>

using namespace std;

int main()
{

    long long t, n, k, ai;
    long long mm;
    vector<long long> c;
    scanf("%lld", &t);
    while (t--) {
        c.clear();
        scanf("%lld %lld", &n, &k);
        for (long long i = 0; i < n; i++) {
            scanf("%lld", &ai);
            if (ai % k > 0)
                c.push_back(k - (ai % k) + 1);
        }
        if (c.size() <= 0) {
            printf("0\n");
            continue;
        }
        if (c.size() == 1) {
            printf("%lld\n", c[0]);
            continue;
        }
        sort(c.begin(), c.end());
        //for (int i = 0; i < c.size(); i++)
        //    cout << c[i] << " ";
        //cout << endl;
        long long curC = 1;
        mm = 0;
        for (long long i = 1; i < c.size(); i++) {
            if (c[i] == c[i - 1]) {
                curC++;
            } else {
                mm = max(mm, c[i - 1] + (k * (curC - 1)));
                curC = 1;
            }
            if (i == (c.size() - 1))
                mm = max(mm, c[i] + k * (curC - 1));
            //cout << curC << "|" << mm << " ";
        }
        //cout << endl;
        printf("%lld\n", mm);
    }

    return 0;
}
