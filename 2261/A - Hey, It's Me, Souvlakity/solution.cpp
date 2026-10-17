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
   vector<int> vec1,vec2;
   for(int i=0;i<n;i++)
   {
    if(s[i]=='1')vec1.push_back(i+1);
    else vec2.push_back(i+1);
   }
   sort(vec1.begin(),vec1.end(),greater<int> ());
   sort(vec2.begin(),vec2.end(), greater <int> ());
 
   int k=vec1.size();
   if(k==1)cout<<0<<endl;
   else if(k==2)cout<<1<<endl;
   else cout<<(vec1[0]-vec1.back())<<endl;
}
 
int main(){
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}