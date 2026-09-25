#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
typedef __gnu_pbds::tree<int,__gnu_pbds::null_type,less<int>,__gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update> ordered_set;
 
#define MOD 998244353
#define bit_count __builtin_popcountll
#define Atiksh ios_base::sync_with_stdio(false);cin.tie(NULL);
 
 
#define N 300001
int s[N];
void solve(){
    int n,x;
    cin>>n>>x;
    vector<int> a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    if(x==1){
        cout<<0<<endl;
        return;
    }
    vector<int> pr;
    int tmp=x;
    while(tmp>1){
        int p=s[tmp];
        pr.push_back(p);
        while(tmp%p==0)tmp/=p;
    }
    long long ans=0;
    for(int p:pr){
        long long cur=0;
        for(int i=0;i<n;i++){
            if(a[i]%p==0)cur+=a[i];
        }
        ans=max(ans,cur);
    }
    cout<<ans<<endl;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    for(int i=2;i<N;i++)s[i]=i;
    for(int i=2;i*i<N;i++){
        if(s[i]==i){
            for(int j=i*i;j<N;j+=i)if(s[j]==j)s[j]=i;
        }
    }
    int t;
    if(cin>>t)while(t--)solve();
    return 0;
}