#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
typedef __gnu_pbds::tree<int,__gnu_pbds::null_type,less<int>,__gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update> ordered_set;
 
#define MOD 998244353
#define bit_count __builtin_popcountll
#define Atiksh ios_base::sync_with_stdio(false);cin.tie(NULL);
 
void solve(){
int n;
cin>>n;
vector<int> a(n),pref(n,0);
for(int i=0;i<n;i++)cin>>a[i];
for(int i=0;i<n;i++)
{
    if(a[i]==-1 || a[i]==0)continue;
    int l=i-a[i]+1,r=i+a[i];
    pref[max(l,0)]++;
 
    if(r<=(n-1))pref[r]--;
 
}
string ans(n,'0');
for(int i=1;i<n;i++)pref[i]+=pref[i-1];
 
 
 
//for(int i=0;i<n;i++)cout<<pref[i]<<" ";
//cout<<endl;
for(int i=0;i<n;i++)
    if(pref[i]==0)
        ans[i]='1';
int f=1;
for(int i=0;i<n;i++)if( a[i]!=-1 && ( (i-a[i])<0 || ans[i-a[i]]!='1' ) && ( (i+a[i])>=n || ans[i+a[i]]!='1')  )f=0;
if(f==0)
{
    cout<<-1<<endl;
    return;
}
 
    cout<<ans<<endl;
 
 
}
 
int main() {
    Atiksh
    int t;
    cin>>t;
    while (t--) {
        solve();
    }
 
    return 0;
}