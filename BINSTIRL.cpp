#include<bits/stdc++.h>
using namespace std;
#define endl "\n"

int main()
{
	ios_base:: sync_with_stdio(false); cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		cout<<!((n-m)&((m-1)>>1))<<endl;
	}
	return 0;
}