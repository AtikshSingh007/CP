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
    vector<int>nums(n);
    for(int i=0;i<n;i++)cin>>nums[i];
    vector<int > a,b,c;
    map<int,vector<int>> mp;
 
    for(int i=0;i<n;i++)mp[nums[i]].push_back(i);
 
    int M = 0;
    while(mp.count(M) && mp[M].size() >= 2) M++;
 
    for(auto& [k,vec]:mp)
    {
        if (k < M) {
            a.push_back(vec.back());
            vec.pop_back();
 
            b.push_back(vec.back());
            vec.pop_back();
 
            while(vec.size()) {
                a.push_back(vec.back());
                vec.pop_back();
            }
        } else {
            while(vec.size()) {
                c.push_back(vec.back());
                vec.pop_back();
            }
        }
    }
 
    int amex=-1,bmex=-1,cmex=-1;
    for(auto i:a)if(nums[i]==(amex+1))amex++;
    for(auto i:b)if(nums[i]==(bmex+1))bmex++;
    for(auto i:c)if(nums[i]==(cmex+1))cmex++;
    string ans(n,'_');
    for(auto i:a)ans[i]='A';
    for(auto i:c)ans[i]='C';
    for(auto i:b)ans[i]='B';
    amex++;
    bmex++;
    cmex++;
    vector <int> re={amex,bmex,cmex};
    sort(re.begin(),re.end());
    amex=re.back();
    bmex=re[1];
    cmex=re[0];
 
    if(amex<=(bmex+cmex))
    {
        cout<<"YES"<<endl;
        for(auto i:ans)cout<<i;
        cout<<endl;
    }
    else
        cout<<"NO"<<endl;
 
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