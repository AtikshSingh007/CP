#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
typedef __gnu_pbds::tree<int,__gnu_pbds::null_type,less<int>,__gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update> ordered_set;
 
#define MOD 998244353
#define bit_count __builtin_popcountll
#define Atiksh ios_base::sync_with_stdio(false);cin.tie(NULL);
 
void solve(){
    string s;
    cin >> s;
    int n = s.size();
 
    int i1 = -1;
    for(int i=0;i<n-1;i++)
        if(s[i]=='0' && s[i+1]=='1'){ i1=i; break; }
    if(i1==-1)
        for(int i=n-1;i>=0;i--)
            if(s[i]=='0'){ i1=i; break; }
    s.erase(s.begin()+i1);
 
    int m = s.size();
    int i2 = -1;
    for(int i=0;i<m-1;i++)
        if(s[i]=='1' && s[i+1]=='0'){ i2=i; break; }
    if(i2==-1)
        for(int i=m-1;i>=0;i--)
            if(s[i]=='1'){ i2=i; break; }
    s.erase(s.begin()+i2);
 
    cout << s << "
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