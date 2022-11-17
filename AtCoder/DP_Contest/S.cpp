#include <bits/stdc++.h>
using namespace std;

const int max_n = 1e5, mod = 1e9 + 7, max_d = 100, num_digit = 10;
int f[max_n + 1][max_d + 1][num_digit];

int main() {

    string s;
    int d, n;
    cin >> s;
    cin >> d;
    n = s.length();
    f[0][0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= d; j++) {
            for (int k = 0; k <= 9; k++) {
                
            }
        }
    }

    return 0;
}