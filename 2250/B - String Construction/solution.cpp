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
    int l = 2 * v + 1, r = 2 * v + 2, m = (tl + tr) / 2;
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
    int l = 2 * v + 1, r = 2 * v + 2, m = (tl + tr) / 2;
    if (p <= m) update(tl, m, l, p, val);
    else update(m + 1, tr, r, p, val);
    tree[v] = __gcd(tree[l], tree[r]);
}
 
#define MOD 998244353
#define bit_count __builtin_popcountll
#define Atiksh ios_base::sync_with_stdio(false);cin.tie(NULL);
 
void solve() {
    int n, k, c1, c0, b, b1, b0, r1, r0, p1, p0, i, j;
    cin >> n >> k;
    
    if (k == n - 1) {
        cout << "-1
";
        return;
    }
    
    c1 = (n + 1) / 2, c0 = n / 2;
    b = n - k;
    b1 = (b + 1) / 2, b0 = b / 2;
    r1 = c1 - b1, r0 = c0 - b0;
    
    for (i = 0; i < b1; i++) {
        p1 = 1 + (i == 0 ? r1 : 0);
        for (j = 0; j < p1; j++) cout << '1';
        
        if (i < b0) {
            p0 = 1 + (i == 0 ? r0 : 0);
            for (j = 0; j < p0; j++) cout << '0';
        }
    }
    cout << "
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