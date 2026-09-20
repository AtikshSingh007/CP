#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
typedef __gnu_pbds::tree<int,__gnu_pbds::null_type,less<int>,__gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update> ordered_set;
 
 
 
#define MOD 998244353
#define bit_count __builtin_popcountll
#define Atiksh ios_base::sync_with_stdio(false);cin.tie(NULL);
 
long long calc(vector <int> &a,vector<int> &b,int x,int y)
{
    long long score=0;
    unordered_map <int,int > mp;
 
    int n=a.size(),m=b.size();
    int i=n-1,j=m-1;
//cout<<x<<" x "<<y<<" y ";
    while(x>0 && i>=0)
    {
        mp[a[i]]++;
        score+=a[i];
        i--;
        x--;
    }
    while(y>0 && j>=0)
    {
        mp[b[j]]++;
        score+=b[j];
        j--;
        y--;
    }
   // cout<<" score "<<score<<endl;
 
 
 
   int common=0;
    set<int> left;
 
    while(i>=0){
        left.insert(a[i]);
        i--;
        }
    while(j>=0){
        left.insert(b[j]);
        j--;
    }
 
    for(auto [k ,freq]:mp)
    {
        if(freq>1){
                common++;
        score-=k;
        }
    }
    vector<int> lef;
    for(auto i:left)lef.push_back(i);
   // cout<<"common "<<common<<endl;
    //sort(left.begin(),left.end());
 
    int sz=lef.size();
    for(int k=sz-1;k>=0 && common>0;k--)
    {
        if(mp.count(lef[k]))continue;
        score+=lef[k];
        common--;
    }
//cout<<"final score"<<score<<endl;
 
    return score ;
 
}
 
 
void solve() {
 
int n,m,x,y;
cin>>n>>m>>x>>y;
vector <int> a(x),b(y);
for(int i=0;i<x;i++)cin>>a[i];
for(int j=0;j<y;j++)cin>>b[j];
cout<<max(  calc(a,b,n-1,m) ,    calc(a,b,n,m-1)   )<<endl;
 
}
 
int main() {
    Atiksh
 
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
 
    return 0;
}