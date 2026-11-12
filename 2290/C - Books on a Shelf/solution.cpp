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
vector<int> a(n);
for(int i=0;i<n;i++)cin>>a[i];
deque <int> dq;
sort(a.begin(),a.end(),greater<int> ());
for(int i=0;i<n;i++)
{
    if(i&1)dq.push_back(a[i]);
    else dq.push_front(a[i]);
}
vector<bool> vis(n,false);
int mx=0;
for(int i=0;i<n;i++)
    if(dq[i]>mx){vis[i]=true;mx=dq[i];}
mx=0;
for(int i=n-1;i>=0;i--)
    if(dq[i]>mx){vis[i]=true;mx=dq[i];}
long long ans=0;
for(int i=0;i<n;i++)
    if(vis[i])ans++;
cout<<ans<<endl;
for(int i=0;i<n;i++)
    cout<<dq[i]<<" ";
cout<<endl;
}
 
int main(){
    Atiksh
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}