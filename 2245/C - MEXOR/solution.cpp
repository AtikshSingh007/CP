#include <bits/stdc++.h>
using namespace std;
 
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	
	int n,k;
	cin>>n>>k;
	int y=k^n;
	int msb=log2(n-1)+1;
	if(( (1<<msb) -1 ) <y)
	{
	    cout<<"NO"<<endl;
	    continue;
	}
	vector <int> last={0},start;
	for(int i=0;i<32;i++)
	if((1<<i)&y)last.push_back((1<<i));
	int m=last.size();
	int j=m-1;
	
	for(int i=n-1;i>=0;i--)
	{
	if(j>=0 && last[j]!=i){
	start.push_back(i);
	}
	else j--;
	}
	cout<<"YES"<<endl;
	for(auto i:start)cout<<i<<" ";
	for(auto i:last)cout<<i<<" ";
	cout<<endl;
	}
 
}