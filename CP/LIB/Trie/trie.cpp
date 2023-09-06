#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
#define endl '\n'
#define bit_cnt(x) __builtin_popcountll(x)

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

const int MAX_VAL = 2, LOW_VAL = '0';

struct TrieNode
{
    TrieNode *child[MAX_VAL];
    int cnt;
    TrieNode()
    {
        for (int i = 0; i < MAX_VAL; i++)
            child[i] = NULL;
        cnt = 0;
    }
};

TrieNode *root;

void TrieInsert(const string &s)
{
    int n = s.length();
    TrieNode *p = root;
    for (int i = 0; i < n; ++i)
    {
        int nxt = s[i] - LOW_VAL;
        if (p->child[nxt] == NULL)
            p->child[nxt] = new TrieNode();
        p = p->child[nxt];
        ++p->cnt;
    }
}

long long TrieCount(const string &s)
{
    int n = s.length();
    TrieNode *p = root;
    for (int i = 0; i < n; ++i)
    {
        int nxt = s[i] - LOW_VAL;
        if (p->child[nxt] == NULL)
            return false;
        p = p->child[nxt];
    }
    return p->cnt;
}

void trieGo(TrieNode *&cur, char c) {
    int id = c - LOW_VAL;
    cur = cur->child[id];
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    root = new TrieNode();
    // code..

    return 0;
}