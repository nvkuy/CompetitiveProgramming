#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

inline void debugLocal() {
    if (!fopen("input.txt", "r"))
        return;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}

struct TrieNode {
    TrieNode* child[26];
    int cnt;
    TrieNode() {
        for (int i=0; i<26; ++i) 
            child[i]=NULL;
        cnt=0;
    }
};

TrieNode *root;

void TrieInsert(const string &s)
{
    int n=s.length();
    TrieNode* p=root;
    for (int i=0; i<n; ++i) {
        int nxt=s[i]-'a';
        if (p->child[nxt]==NULL)
            p->child[nxt]=new TrieNode();
        p=p->child[nxt];
    }
    ++p->cnt;
}

int TrieFind(const string &s)
{
    int n=s.length();
    TrieNode* p=root;
    for (int i=0; i<n; ++i) {
        int nxt=s[i]-'a';
        if (p->child[nxt]==NULL)
            return false;
        p=p->child[nxt];
    }
    return p->cnt;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    debugLocal();

    int n;
    long long ans = 0;
    root = new TrieNode();
    cin >> n;
    vector<string> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        reverse(arr[i].begin(), arr[i].end());
        TrieInsert(arr[i]);
    }
    for (int i = 0; i < n; i++) {
        ans += (TrieFind(arr[i]) - 1);
        for (char c = 'a'; c <= 'z'; c++) {
            arr[i].push_back(c);
            ans += TrieFind(arr[i]);
            arr[i].pop_back();
        }
    }
    cout << ans / 2LL << endl;

    return 0;
}
