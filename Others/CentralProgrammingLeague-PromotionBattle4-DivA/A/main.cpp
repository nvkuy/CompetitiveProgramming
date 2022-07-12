#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

struct Ans {
    int ai, bi, ci;
    Ans(int aa, int bb, int cc) {
        ai = aa, bi = bb, ci = cc;
    }
};

vector<Ans> ans;

bool getAns(int a, int b, int c, int k) {
    if (k >= b) {
        if (k == b) {
            if (k < a || k < c)
                return false;
            ans.push_back(Ans(0, b, 0)); //di
            ans.push_back(Ans(0, 0, 0)); //ve
            ans.push_back(Ans(a, 0, 0)); //di
            ans.push_back(Ans(0, b, 0)); //ve
            ans.push_back(Ans(0, 0, c)); //di
            ans.push_back(Ans(0, 0, 0)); //ve
            ans.push_back(Ans(0, b, 0)); //di
            ans.push_back(Ans(-1, -1, -1));
            return true;
        } else {
            for (int i = 0; i < a; i++) {
                ans.push_back(Ans(1, b, 0));
                ans.push_back(Ans(0, b, 0));
            }
            for (int i = 0; i < c; i++) {
                ans.push_back(Ans(0, b, 1));
                ans.push_back(Ans(0, b, 0));
            }
            ans.push_back(Ans(0, b, 0));
            ans.push_back(Ans(-1, -1, -1));
            return true;
        }
    }
    if (k >= a + c) {
        if (k > a + c) {
            for (int i = 0; i < b; i++) {
                ans.push_back(Ans(a, 1, c));
                ans.push_back(Ans(a, 0, c));
            }
            ans.push_back(Ans(a, 0, c));
            ans.push_back(Ans(-1, -1, -1));
            return true;
        } else {
            if (k < b)
                return false;
            ans.push_back(Ans(a, 0, c));
            ans.push_back(Ans(0, 0, 0));
            ans.push_back(Ans(0, b, 0));
            ans.push_back(Ans(-1, -1, -1));
            return true;
        }
    }
    return false;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t, a, b, c, k;
    cin >> t;
    while (t--) {
        cin >> a >> b >> c >> k;
        ans.clear();
        bool iok = getAns(a, b, c, k);
        if (!iok) {
            cout << "0" << endl;
            continue;
        }
        cout << "1" << endl;
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i].ai << ' ' << ans[i].bi << ' ' << ans[i].ci << endl;
    }

    return 0;
}
