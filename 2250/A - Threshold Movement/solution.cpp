#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
typedef __gnu_pbds::tree<int,__gnu_pbds::null_type,less<int>,__gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update> ordered_set;
 
vector<long long> tree;
 
void build(auto &a, long long v, long long tl, long long tr) {
    if (tl == tr) {
        tree[v] = a[tl];
        return;
    }
    int l = 2 * v + 1;
    int r = 2 * v + 2;
    int m = (tl + tr) / 2;
    build(a, l, tl, m);
    build(a, r, m + 1, tr);
    tree[v] = __gcd(tree[l], tree[r]);
}
 
long long query(int v, int tl, int tr, int ql, int qr) {
    if (ql <= tl && qr >= tr) return tree[v];
    if (tl > qr || tr < ql) return 0;
    int m = (tl + tr) / 2;
    return __gcd(query(2 * v + 1, tl, m, ql, qr), query(2 * v + 2, m + 1, tr, ql, qr));
}
 
void update(int tl, int tr, int v, int p, int val) {
    if (tl == tr) {
        tree[v] = val;
        return;
    }
    int l = 2 * v + 1;
    int r = 2 * v + 2;
    int m = (tl + tr) / 2;
    if (p <= m) update(tl, m, l, p, val);
    else update(m + 1, tr, r, p, val);
    tree[v] = __gcd(tree[l], tree[r]);
}
 
#define MOD 998244353
#define bit_count __builtin_popcountll
#define Atiksh ios_base::sync_with_stdio(false);cin.tie(NULL);
 
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
 
    if (n % 2 != 0) {
        cout << "NO
";
        return;
    }
 
    int mo = 2e9, me = -1;
 
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) mo = min(mo, a[i]);
        else me = max(me, a[i]);
    }
 
    if (me < mo - 1) cout << "YES
";
    else cout << "NO
";
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