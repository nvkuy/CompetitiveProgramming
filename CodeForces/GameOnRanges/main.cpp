#include <bits/stdc++.h>

using namespace std;

struct rg {
    int li, ri, d;
    rg(int l, int r) {
        li = l;
        ri = r;
        d = r - l;
    }
};

bool cmp(rg r1, rg r2) {
    return r1.d < r2.d;
}

vector<rg> rgs;
bool dd[1001];

int main()
{
    int t, n, li, ri;
    cin >> t;
    while (t--) {
        rgs.clear();
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> li >> ri;
            rgs.push_back(rg(li, ri));
        }
        sort(rgs.begin(), rgs.end(), cmp);
        memset(dd, false, sizeof(dd));
        for (int i = 0; i < rgs.size(); i++) {
            for (int j = rgs[i].li; j <= rgs[i].ri; j++) {
                if (!dd[j]) {
                    cout << rgs[i].li << " " << rgs[i].ri << " " << j << endl;
                    dd[j] = true;
                    break;
                }
            }
        }
    }

    return 0;
}
