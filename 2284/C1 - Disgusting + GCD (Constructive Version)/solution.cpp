#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
typedef __gnu_pbds::tree<int,__gnu_pbds::null_type,less<int>,__gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update> ordered_set;
 
#define MOD 998244353
#define bit_count __builtin_popcountll
#define Atiksh ios_base::sync_with_stdio(false);cin.tie(NULL);
 
int pr[200105];
int nx[200105];
 
void fill_primes(){
for(int i=2;i<200105;i++)pr[i]=1;
for(int i=2;i*i<200105;i++)
{
    if(pr[i])
    {
        for(int j=i*i;j<200105;j+=i)pr[j]=0;
    }
}
int last=-1;
for(int i=200104;i>=0;i--)
{
    if(pr[i])last=i;
    nx[i]=last;
}
}
 
void solve(){
int n;
cin>>n;
vector<int> a(n);
for(int i=0;i<n;i++)cin>>a[i];
for(int i=0;i<n;i++)cout<<nx[a[i]]<<" ";
cout<<endl;
}
 
int main(){
    Atiksh
    fill_primes();
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}