#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
 
using namespace std;
 
const int N = 200005;
int a[N]; 
int t[4 * N]; 
 
void bld(int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = a[tl];
        return;
    }
    int tm = tl + (tr - tl) / 2;
    bld(2 * v, tl, tm);
    bld(2 * v + 1, tm + 1, tr);
    t[v] = max(t[2 * v], t[2 * v + 1]);
}
 
int qry(int v, int tl, int tr, int l, int r) {
    if (r < tl || tr < l) return 0;
    if (l <= tl && tr <= r) return t[v];
    int tm = tl + (tr - tl) / 2;
    return max(qry(2 * v, tl, tm, l, r), qry(2 * v + 1, tm + 1, tr, l, r));
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n, m;
    if (!(cin >> n >> m)) return 0;
 
    for (int i = 1; i <= m; i++) {
        cin >> a[i];
    }
 
    bld(1, 1, m);
 
    int q;
    cin >> q;
 
    while (q--) {
        int x1, y1, x2, y2, k;
        cin >> x1 >> y1 >> x2 >> y2 >> k;
 
        if (abs(x1 - x2) % k != 0 || abs(y1 - y2) % k != 0) {
            cout << "NO
";
            continue;
        }
 
        int mx = x1 + ((n - x1) / k) * k;
        int l = min(y1, y2);
        int r = max(y1, y2);
        int mo = qry(1, 1, m, l, r);
 
        if (mx > mo) {
            cout << "YES
";
        } else {
            cout << "NO
";
        }
    }
 
    return 0;
}