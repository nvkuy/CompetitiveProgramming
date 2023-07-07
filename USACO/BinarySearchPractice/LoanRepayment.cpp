#include <bits/stdc++.h>
using namespace std;

int main() {

    if (fopen("loan.in", "r")) {
        freopen("loan.in", "r", stdin);
        freopen("loan.out", "w", stdout);
    }

    long long n, k, m;
    cin >> n >> k >> m;
    long long ll = 1, rr = 1e12 + 7, mm;
    while (ll < rr) {
        mm = (ll + rr + 1) / 2;
        long long rm_milk = n, rm_day = k;
        while (true) {
            long long est_pay = rm_milk / mm;
            if (est_pay < m) {
                rm_milk -= (m * rm_day);
                break;
            }
            if (rm_day <= 0) break;
            if (rm_milk <= 0) break;
            long long still_pay_same = est_pay * mm;
            long long rm = rm_milk - still_pay_same + 1;
            long long day_still_pay_same = min(rm / est_pay + ((rm % est_pay) > 0), rm_day);
            rm_day -= day_still_pay_same;
            rm_milk -= (est_pay * day_still_pay_same);
        }
        if (rm_milk <= 0)
            ll = mm;
        else
            rr = mm - 1;
    }
    cout << ll << endl;

    return 0;
}