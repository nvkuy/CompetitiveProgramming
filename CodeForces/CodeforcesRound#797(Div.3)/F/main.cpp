#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

string s;
vector<int> trans, cycle_mark;

void mark_cyc(int u, int cyc_num) {
    if (cycle_mark[u] != 0)
        return;
    cycle_mark[u] = cyc_num;
    mark_cyc(trans[u], cyc_num);
}

void nextMove(string &s1, vector<int> &cycle) {
    string s2 = s1;
    for (int i = 0; i < cycle.size(); i++)
        s2[trans[cycle[i]] - 1] = s1[cycle[i] - 1];
    s1 = s2;
}

int getNumMoveNeeded(vector<int> &cycle) {
    string s1 = s;
    for (int i = 1; i <= cycle.size(); i++) {
        nextMove(s1, cycle);
        if (s1 == s)
            return i;
    }
    return 0;
}

long long gcd(long long a, long long b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

long long lcm(long long a, long long b) {
    return a * (b / gcd(a, b));
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t, n, pi;
    cin >> t;
    while (t--) {
        cin >> n;
        trans.resize(n + 1);
        cycle_mark.assign(n + 1, 0);
        cin.ignore();
        getline(cin, s);
        for (int i = 1; i <= n; i++) {
            cin >> pi;
            trans[pi] = i;
        }
        int cyc_num = 0;
        vector<long long> ti;
        for (int i = 1; i <= n; i++) {
            if (cycle_mark[i] != 0)
                continue;
            vector<int> cycle;
            cyc_num++;
            mark_cyc(i, cyc_num);
            for (int j = 1; j <= n; j++)
                if (cycle_mark[j] == cyc_num)
                    cycle.push_back(j);
            //cout << "cycle size: " << cycle.size() << endl;
            ti.push_back(getNumMoveNeeded(cycle));
        }
        long long ans = 1;
        for (int i = 0; i < ti.size(); i++)
            ans = lcm(ans, ti[i]);
        cout << ans << endl;
    }

    return 0;
}
