#include<bits/stdc++.h>
using namespace std;
#define endl "\n"

int main()
{
	ios_base:: sync_with_stdio(false); cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		int a,b,c,w;
		cin>>a>>b>>c>>w;
		int res = max(max(a,b),c)-w;
		int x;
		cin>>x;
		vector<int >mv(x,0);
		for(int i=0;i<x;i++)
			cin>>mv[i];
		sort(mv.rbegin(), mv.rend());

		int i=0;
		for(;i<x && res>=0 ;i++)
			{
				res-=mv[i];
			}
		cout<<i<<endl;
	}
	return 0;
}