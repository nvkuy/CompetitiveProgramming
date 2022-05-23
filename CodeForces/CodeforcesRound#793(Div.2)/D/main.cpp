#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int n;
string s;
vector<vector<int>> c;


int nextNode(int u, int dr) {
    int v = u + dr;
    if (v > n)
        v -= n;
    if (v < 1)
        v += n;
    return v;
}

void dfs(int u, int dr) {
    if (s[u - 1] == '1')
        return;
    int v = nextNode(u, dr);
    if (c[v].size() != 0)
        return;
    c[u].push_back(v);
    c[v].push_back(u);
    dfs(v, dr);
}

void makeTree(int root) {
    c.clear();
    c.resize(n + 1);
    bool hasOddPre = false;
    for (int u = nextNode(root, 1); u != root; u = nextNode(u, 1)) {
        if (c[u].size() != 0)
            continue;
        if (s[u - 1] == '1')
            hasOddPre = true;
        int dr = 1, v = nextNode(u, dr);
        if (v != root && s[v - 1] == '2' && hasOddPre)
            continue;
        if (hasOddPre)
            dr = -1;
        hasOddPre = false;
        c[root].push_back(u);
        c[u].push_back(root);
        dfs(u, dr);
    }
}

int checkAndFindRoot() {
    int oddNodeCnt = 0, root = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i - 1] == '1') {
            root = i;
            oddNodeCnt++;
        }
    }
    if (oddNodeCnt % 2)
        root = 0;
    return root;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        cin.ignore();
        getline(cin, s);
        int root = checkAndFindRoot();
        if (root == 0) {
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
        makeTree(root);
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < c[i].size(); j++) {
                if (c[i][j] > i)
                    cout << i << ' ' << c[i][j] << endl;
            }
        }
    }

    return 0;
}
