#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
typedef __gnu_pbds::tree<int,__gnu_pbds::null_type,less<int>,__gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update> ordered_set;
 
vector<long long> tree;
void build(auto &a, long long  v, long long  tl, long long  tr) {
    if (tl == tr) {
        tree[v] = a[tl];
        return;
    }
    int left = 2 * v + 1;
    int right = 2 * v + 2;
    int tm = (tl + tr) / 2;
    build(a, left, tl, tm);
    build(a, right, tm + 1, tr);
    tree[v] = __gcd(tree[left], tree[right]);
}
 
long long query(int v, int tl, int tr, int l, int r) {
    if (l <= tl && r >= tr) return tree[v];
    if (tl > r || tr < l) return 0;
    int tm = (tl + tr) / 2;
    long long res_left = query(2 * v + 1, tl, tm, l, r);
    long long res_right = query(2 * v + 2, tm + 1, tr, l, r);
    return __gcd(res_left, res_right);
}
 
void update(int tl, int tr, int v, int pos, int val) {
    if (tl == tr) {
        tree[v] = val;
        return;
    }
    int left = 2 * v + 1;
    int right = 2 * v + 2;
    int tm = (tl + tr) / 2;
    if (pos <= tm) {
        update(tl, tm, left, pos, val);
    } else {
        update(tm + 1, tr, right, pos, val);
    }
    tree[v] = __gcd(tree[left], tree[right]);
}
 
#define MOD 998244353
#define bit_count __builtin_popcountll
#define Atiksh ios_base::sync_with_stdio(false);cin.tie(NULL);
 
vector<int> vis;
vector<int> ans;
vector<vector<int>> adj;
vector<int> d;
 
int dfs(int node) {
    vis[node] = 1;
    vector<int> active_children;
 
    for (auto nbr : adj[node]) {
        if (!vis[nbr]) {
            if (dfs(nbr)) {
                active_children.push_back(nbr);
            }
        }
    }
 
    if (d[node]) {
        for (auto child : active_children) {
            ans.push_back(child + 1);
        }
    } else {
        if (active_children.size() >= 2) {
            for (int i = 0; i < (int)active_children.size() - 1; i++) {
                ans.push_back(active_children[i] + 1);
            }
        }
    }
 
    return d[node] || (!active_children.empty());
}
 
void solve() {
    ans.clear();
 
    int n;
    cin >> n;
    adj.assign(n, vector<int>());
    vis.assign(n, 0);
 
    for (int i = 1; i < n; i++) {
        int p;
        cin >> p;
        adj[p - 1].push_back(i);
        adj[i].push_back(p - 1);
    }
 
    int m;
    cin >> m;
    d.assign(n, 0);
 
    for (int i = 0; i < m; i++) {
        int temp;
        cin >> temp;
        d[temp - 1] = 1;
    }
 
    dfs(0);
 
    cout << ans.size();
    for (auto i : ans) {
        cout << " " << i;
    }
    cout <<endl;
}
 
int main() {
    Atiksh
 
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
 
    return 0;
}