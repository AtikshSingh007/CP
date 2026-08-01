#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
typedef __gnu_pbds::tree<int,__gnu_pbds::null_type,less<int>,__gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update> ordered_set;
 
#define MOD 998244353
#define bit_count __builtin_popcountll
#define Atiksh ios_base::sync_with_stdio(false);cin.tie(NULL);
 
void solve(){
    long long n;
    cin >> n;
    
    vector<long long> a(2 * n + 1), f(n + 1, 0), d(2 * n + 1, 0);
    
    for (int i = 1; i <= 2 * n; ++i) {
        cin >> a[i];
        if (!f[a[i]]) f[a[i]] = i; 
    }
 
    for (int i = 1; i <= 2 * n; ++i) {
        d[i] = d[i - 1];
        if (f[a[i]] != i) {
            long long l = f[a[i]];
            long long len = i - l + 1;
            d[i] = max(d[i], d[l - 1] + len * len - len);
        }
    }
 
    cout << d[2 * n] + 2 * n << "
";
}
 
int main() {
    Atiksh
    int t;
    t=1;
    cin>>t;
    while (t--) {
        solve();
    }
    return 0;
}