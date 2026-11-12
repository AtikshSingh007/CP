#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
typedef __gnu_pbds::tree<int,__gnu_pbds::null_type,less<int>,__gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update> ordered_set;
 
#define MOD 998244353
#define bit_count __builtin_popcountll
#define Atiksh ios_base::sync_with_stdio(false);cin.tie(NULL);
 
void solve(){
int n,k;
cin>>n>>k;
vector<int> a(n),m(n,0);
for(int i=0;i<n;i++)cin>>a[i];
int w=0,tot=0;
for(int i=n-1;i>=0;i--)
{
    m[i]=(a[i]&1)^w;
    tot^=m[i];
    w^=m[i];
    if(i+k<n)w^=m[i+k];
}
if(tot)cout<<"Alice"<<endl;
else cout<<"Bob"<<endl;
}
 
int main(){
    Atiksh
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}