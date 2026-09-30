#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
typedef __gnu_pbds::tree<int,__gnu_pbds::null_type,less<int>,__gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update> ordered_set;
 
#define MOD 998244353
#define bit_count __builtin_popcountll
#define Atiksh ios_base::sync_with_stdio(false);cin.tie(NULL);
 
void solve() {
int n,k;
cin>>n;
vector<int> a(n);
for(int i=0;i<n;i++)cin>>a[i];
long long f=1;
int mid=(n+1)/2;
 
//if(n&1 && mid!=a[n/2])f=0;
vector<int> ind;
for(int i=0;i<n;i++)
{
   if(a[i]!=(i+1))ind.push_back(i);
 
}
k=ind.size();
for(int i=0;i<k/2;i++)
{
    swap(a[ind[i]],a[ind[k-1-i]]);
}
 
for(int i=1;i<n;i++)
    if(a[i]<a[i-1])f=0;
 
if(f)cout<<"YES"<<endl;
else
    cout<<"NO"<<endl;
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