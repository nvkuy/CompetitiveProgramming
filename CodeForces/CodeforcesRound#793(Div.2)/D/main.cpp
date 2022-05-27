#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int n;
string s;
vector<vector<int>> c;
vector<int> lastEvenPos;

int nextNode(int u, int dr) {
    int v = u + dr;
    if (v > n)
        v -= n;
    if (v < 1)
        v += n;
    return v;
}

void dfs(int u, int root) {
    if (s[u - 1] == '1')
        return;
    int preNode = nextNode(u, -1);
    if (c[preNode].size() == 0 && preNode != root) {
        c[u].push_back(preNode);
        c[preNode].push_back(u);
        dfs(preNode, root);
        return;
    }
    int nextOneNode = nextNode(u, 1), nextTwoNode = nextNode(nextOneNode, 1);
    if (c[nextTwoNode].size() == 0 && nextTwoNode != root && nextTwoNode != u && s[nextOneNode - 1] > s[nextTwoNode - 1]) {
        int v = lastEvenPos[nextTwoNode];
        c[u].push_back(v);
        c[v].push_back(u);
        dfs(v, root);
        return;
    }
    if (c[nextOneNode].size() == 0 && nextOneNode != root) {
        c[u].push_back(nextOneNode);
        c[nextOneNode].push_back(u);
        dfs(nextOneNode, root);
        return;
    }
}

void makeTree(int root) {
    c.clear();
    c.resize(n + 1);
    lastEvenPos.assign(n + 1, 0);
    int lastEven = 0;
    for (int u = nextNode(root, -1); u != root; u = nextNode(u, -1)) {
        if (s[u - 1] == '1')
            lastEven = 0;
        else {
            if (lastEven == 0)
                lastEven = u;
            lastEvenPos[u] = lastEven;
        }
    }
    //make seq 0 0 1
    bool hasOneBefore = false;
    for (int u = nextNode(root, 1); u != root; u = nextNode(u, 1)) {
        if (s[u - 1] == '1')
            hasOneBefore = true;
        if (c[u].size() != 0 || s[u - 1] == '1')
            continue;
        int ru = u;
        if (hasOneBefore)
            ru = lastEvenPos[u];
        hasOneBefore = false;
        c[root].push_back(ru);
        c[ru].push_back(root);
        dfs(ru, root);
    }
    //add remain 1
    for (int u = nextNode(root, 1); u != root; u = nextNode(u, 1)) {
        if (c[u].size() != 0)
            continue;
        c[root].push_back(u);
        c[u].push_back(root);
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
