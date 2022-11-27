#include <bits/stdc++.h>
using namespace std;

const int base = 311, maxN = 1e6 + 5;
const long long m1 = 1e9 + 7, m2 = 1e9 + 9;
long long pow_base1[maxN], pow_base2[maxN];

void buildPow(int n) {
    pow_base1[0] = pow_base2[0] = 1;
    for (int i = 1; i <= n; i++) {
        pow_base1[i] = (pow_base1[i - 1] * base) % m1;
        pow_base2[i] = (pow_base2[i - 1] * base) % m2;
    }
}

void buildHash(const string &s, vector<long long> &pf_hash1, vector<long long> &pf_hash2) {
    pf_hash1.resize(s.length() + 1);
    pf_hash2.resize(s.length() + 1);
    pf_hash1[0] = pf_hash2[0] = 0;
    for (int i = 1; i <= s.length(); i++) {
        pf_hash1[i] = (pf_hash1[i - 1] * base + s[i - 1]) % m1;
        pf_hash2[i] = (pf_hash2[i - 1] * base + s[i - 1]) % m2;
    }
}

//index from 1
pair<long long, long long> getHash(int l, int r, vector<long long> &pf_hash1, vector<long long> &pf_hash2) {
    pair<long long, long long> ans;
    ans.first = (pf_hash1[r] - pf_hash1[l - 1] * pow_base1[r - l + 1] + m1 * m1) % m1;
    ans.second = (pf_hash2[r] - pf_hash2[l - 1] * pow_base2[r - l + 1] + m2 * m2) % m2;
    return ans;
}

int find(int len, int n, vector<long long> &pf_hash1, vector<long long> &pf_hash2) {
    map<pair<long long, long long>, int> cnt;
    for (int i = 1; i + len - 1 <= n; i++) {
        int r = i + len - 1;
        cnt[getHash(i, r, pf_hash1, pf_hash2)]++;
    }
    int ans = 0;
    for (int i = 1; i + len - 1 <= n; i++) {
        int r = i + len - 1;
        if (cnt[getHash(i, r, pf_hash1, pf_hash2)] == 1) {
            ans = i;
            break;
        }
    }
    return ans - 1;
}

int main() {

    string s;
    vector<long long> pf_hash1, pf_hash2;
    cin >> s;
    int n = s.length();
    buildPow(n + 1);
    buildHash(s, pf_hash1, pf_hash2);
    int l = 1, r = n, m;
    while (l < r) {
        m = (l + r) / 2;
        if (find(m, n, pf_hash1, pf_hash2) != -1)
            r = m;
        else
            l = m + 1;
    }
    cout << s.substr(find(r, n, pf_hash1, pf_hash2), r) << endl;

    return 0;
}