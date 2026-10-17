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
   vector<long long > a(n);
 
   for(int i=0;i<n;i++)cin>>a[i];
long long sum=accumulate(a.begin(),a.end(),0ll);
 
if(n==1){
    cout<<"Moggity"<<endl;
    return;
 
}
else if(n==2)
{
    if(sum&1)
        cout<<"Larpity"<<endl;
    else
        cout<<"Moggity"<<endl;
        return;
}
else if(n==3)
{
    int o=0;
    for(int i=0;i<n;i++)o+=a[i]&1;
    if(o==3)
        cout<<"Larpity"<<endl;
    else
        cout<<"Moggity"<<endl;
    return;
}
cout<<"Moggity"<<endl;
}
 
int main(){
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}