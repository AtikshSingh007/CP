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
 
vector<int> ans(n,0);
 
 
 
 
for(int x=1;x<=n;x++)
{
    int pos=n-x+a[x-1];
    if(pos<0||pos>=n||ans[pos])
    {
        cout<<-1<<endl;
        return ;
    }
    ans[pos]=x;
}
 
 
 
 
for(int i=0;i<n;i++)
cout<<ans[i]<<" ";
cout<<endl;
}
 
int main(){
    Atiksh
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}