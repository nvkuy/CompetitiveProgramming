#include <bits/stdc++.h>

using namespace std;

int query(int a, int b, int c) {
    cout << "? " << a << ' ' << b << ' ' << c << endl;
    cout.flush();
    int rp;
    cin >> rp;
    return rp;
}

int main()
{
    int t, n;
    map<int, int> dd;
    map<int, int>::iterator it;
    cin >> t;
    while (t--) {
        cin >> n;
        int im = -1, mq = -1, rp, a, b;
        a = query(1, 3, 4); b = query(1, 2, 3);
        if (a < b) {
            a = 3;
            b = 4;
        } else {
            a = 1;
            b = 2;
        }
        for (int i = 1; i <= n; i++) {
            if (a == i || b == i)
                continue;
            rp = query(a, b, i);
            if (rp == -1)
                return 0;
            if (rp > mq) {
                mq = rp;
                im = i;
            }
        }
        a = im, b = im + 1;
        if (b > n)
            b = im - 1;
        im = -1, mq = -1;
        dd.clear();
        for (int i = 1; i <= n; i++) {
            if (i == a || i == b)
                continue;
            rp = query(a, b, i);
            if (rp == -1)
                return 0;
            if (rp > mq) {
                mq = rp;
                im = i;
            }
            it = dd.find(rp);
            if (it == dd.end())
                dd.insert(make_pair(rp, 1));
            else
                (it->second)++;
        }
        for (it = dd.begin(); it != dd.end(); it++) {
            if ((*it).second == n - 2) {
                im = b;
                break;
            }
        }
        b = im;
        cout << "! " << a << ' ' << b << endl;
        cout.flush();
    }

    return 0;
}
