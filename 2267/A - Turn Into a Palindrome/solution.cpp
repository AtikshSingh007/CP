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
cin>>n;
char ch;
string s;
cin>>ch>>s;
int ans=0;
for(int i=0;i<n/2;i++)
{
    if(s[i]!=s[n-1-i])
    {
        if(s[i]==ch || s[n-1-i]==ch)ans++;
            else ans+=2;
    }
}
 
cout<<ans<<endl;
}
 
int main() {
    Atiksh
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}