#include <bits/stdc++.h>

using namespace std;

struct cave {
    int bi, ki;
    cave(int b, int k) {
        bi = b;
        ki = k;
    }
};

bool cmp(cave c1, cave c2) {
    if (c1.bi == c2.bi)
        return c1.ki > c2.ki;
    return c1.bi < c2.bi;
}

int main()
{
    int t, n, k, a[100001], pna, sk;
    vector<cave> b;
    cin >> t;
    while (t--) {
        b.clear();
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> k;
            pna = 0;
            for (int j = 0; j < k; j++) {
                cin >> a[j];
                pna = max(pna, a[j] - j);
            }
            b.push_back(cave(pna, k));
        }
        sort(b.begin(), b.end(), cmp);
        pna = 0, sk = 0;
        for (int i = 0; i < n; i++) {
            //cout << b[i].bi << "|" << b[i].ki << " ";
            pna = max(pna, b[i].bi - sk);
            sk += b[i].ki;
        }
        //cout << endl;
        cout << pna + 1 << endl;
    }

    return 0;
}
