#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
typedef __gnu_pbds::tree<int,__gnu_pbds::null_type,less<int>,__gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update> ordered_set;
 
#define MOD 998244353
#define bit_count __builtin_popcountll
#define Atiksh ios_base::sync_with_stdio(false);cin.tie(NULL);
 
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
 
    unordered_map<int, int> mp;
    for(auto i : a) mp[i]++;
 
    vector<pair<int, int>> vec;
    for(auto [val, cnt] : mp) vec.push_back({val, cnt});
 
    sort(vec.begin(), vec.end(), greater<pair<int, int>>());
 
    int sz = vec.size();
    vector<int> ans;
 
    for(int i = 0; i < sz; i++) {
        auto [val, cnt] = vec[i];
        for(int j = 0; j < cnt; j++) ans.push_back(val);
 
        for(int j = i + 1; j < sz; j++) {
            auto [vj, cj] = vec[j];
            int take = min(cj, cnt);
            for(int k = 0; k < take; k++) {
                ans.push_back(vj);
            }
            vec[j] = {vj, cj - take};
        }
    }
 
    for(auto i : ans) cout << i << " ";
    cout << endl;
}
 
int main() {
    Atiksh
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}