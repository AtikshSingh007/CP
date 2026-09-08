#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
typedef __gnu_pbds::tree<int,__gnu_pbds::null_type,less<int>,__gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update> ordered_set;
 
#define MOD 998244353
#define bit_count __builtin_popcountll
#define Atiksh ios_base::sync_with_stdio(false);cin.tie(NULL);
 
void solve(){
    long long x, y, k;
    cin >>x>>y>>k;
 
    long long d = y - x,
    l = x, r = x + k - 1,res = 0;
 
    long long mx1 = min(r, d);
    for (long long i = l; i <= mx1; ++i) {
        res += d % i;
    }
 
    long long mn2 = max(l, d + 1);
    if (r >= mn2) {
        res += (r - mn2 + 1) * d;
    }
 
    cout<<res<<endl;;
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