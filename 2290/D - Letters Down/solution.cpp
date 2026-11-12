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
string s;
cin>>s;
int need[26]={0};
for(int i=0;i<n/2;i++)
{
    int u=s[i]-'a',v=s[n-1-i]-'a';
    if(u>v)swap(u,v);
    for(int x=u+1;x<=v;x++)need[x]=1;
}
int ans=0;
for(int x=1;x<26;x++)ans+=need[x];
cout<<ans<<endl;
}
 
int main(){
    Atiksh
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}