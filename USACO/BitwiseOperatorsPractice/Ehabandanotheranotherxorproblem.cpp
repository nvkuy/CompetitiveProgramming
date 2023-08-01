#include <bits/stdc++.h>
using namespace std;

int query(int c, int d) {
    cout << "? " << c << ' ' << d << endl;
    cout.flush();
    int rp;
    cin >> rp;
    return rp;
}

int main() {

    int curA = 0, curB = 0, isANotLess = 1;
    if (query(0, 0) == -1)
        isANotLess = 0;
    for (int i = 29; i >= 0; i--) {
        int q1 = query(curA ^ (1 << i), curB);
        int q2 = query(curA, curB ^ (1 << i));
        if (q1 != q2) {
            // same bit
            if (isANotLess) {
                if (q1 == -1) {
                    curA ^= (1 << i);
                    curB ^= (1 << i);
                }
            } else {
                if (q2 == 1) {
                    curA ^= (1 << i);
                    curB ^= (1 << i);
                }
            }
        } else {
            // diff bit
            if (isANotLess) {
                curA ^= (1 << i);
                if (q1 == -1)
                    isANotLess = 0;
            } else {
                curB ^= (1 << i);
                if (q2 == 1)
                    isANotLess = 1;
            }
        }
    }

    cout << "! " << curA << ' ' << curB << endl;
    cout.flush();

    return 0;
}