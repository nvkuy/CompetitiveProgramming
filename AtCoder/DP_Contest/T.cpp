#include <bits/stdc++.h>
using namespace std;

int main() {

    int n, mod = 1e9 + 7;
    cin >> n;
    vector<char> ex(n - 1);
    for (int i = 0; i + 1 < n; i++)
        cin >> ex[i];
    vector<vector<int>> f(n + 1, vector<int>(n + 1, 0));
    vector<int> psf(n + 1, 1);
    f[1][1] = 1, psf[0] = 0;
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            if (ex[i - 2] == '<')
                f[i][j] = (psf[n] - psf[j - 1] + mod) % mod;
            else
                f[i][j] = psf[j - 1];
        }
        fill(psf.begin(), psf.end(), 0);
        for (int j = 1; j <= n; j++)
            psf[j] = (psf[j - 1] + f[i][j]) % mod;
    }
    cout << psf[n] << endl;
    
    return 0;
}