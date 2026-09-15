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
sort(a.begin(),a.end());
 
unordered_map<int,int> mp;
for(auto i:a)mp[i]++;
int sum=accumulate(a.begin(),a.end(),0);
int ans=a.back();
if(n>1)
ans=ans+a[n-2];
int num=-1,cnt=0;
for(auto [k,v]:mp)
{
   if(cnt<v)
   {
       num=k;
       cnt=v;
   }
 
 
}
int rest=sum-cnt*num;
    int mx=min(cnt,n-cnt+2);
    ans=max(ans,mx*num+rest);
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