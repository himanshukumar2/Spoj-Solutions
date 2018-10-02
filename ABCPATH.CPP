#include<bits/stdc++.h>
using namespace std;
#define endl "\n"

int dp[1000][1000];
bool vis[55][55];

int dfs(char arr[55][55], int i, int j, int a, int b){
	//cout<<"Called "<<i<<" "<<j<<endl;
	vis[i][j] = true;

	if(dp[i][j]!=-1)
		return dp[i][j];

	int max_ = INT_MIN;
	
	if(i-1>=0 && arr[i-1][j] == arr[i][j]+1){
		max_ = max(max_, 1+dfs(arr, i-1, j, a, b));
	}

	if(i+1<a && arr[i+1][j] == arr[i][j]+1){
		max_ = max(max_, 1+dfs(arr, i+1, j, a, b));
	}

	if(j-1>=0 && arr[i][j-1] == arr[i][j]+1){
		max_ = max(max_, 1+dfs(arr, i, j-1, a, b));	
	}
		
	if(j+1<b && arr[i][j+1] == arr[i][j]+1){
		max_ = max(max_, 1+dfs(arr, i, j+1, a, b));	
	}

	if(j-1>=0 && i-1>=0 && arr[i-1][j-1] == arr[i][j]+1){
		max_ = max(max_, 1+dfs(arr, i-1, j-1, a, b));	
	}
		
	if(j+1<b && i+1<a && arr[i+1][j+1] == arr[i][j]+1){
		max_ = max(max_, 1+dfs(arr, i+1, j+1, a, b));	
	}

	if(j-1>=0 && i+1<a && arr[i+1][j-1] == arr[i][j]+1){
		max_ = max(max_, 1+dfs(arr, i+1, j-1, a, b));	
	}
		
	if(j+1<b && i-1>=0 && arr[i-1][j+1] == arr[i][j]+1){
		max_ = max(max_, 1+dfs(arr, i-1, j+1, a, b));	
	}

	//cout<<"Calling "<<i<<" "<<j<<" finished! DP value "<<max(0, max_)<<endl;
	return dp[i][j] = max(0, max_);
}

int main()
{
	int a,b,i=0;
	while(cin>>a>>b && ++i && a!=0 && b!=0){
		char arr[55][55];
		

		
		memset(dp, -1, sizeof dp);
		memset(vis, false, sizeof vis);

		for(int k=0;k<a;k++){
			for(int j=0;j<b;j++){
				cin>>arr[k][j];
			}
		}

		int max_ = INT_MIN;

		for(int k=0;k<a;k++){
			for(int j=0;j<b;j++){
				if(!vis[k][j])
					dfs(arr, k,j,a,b);
			}
		}

		for(int k=0;k<a;k++){
			for(int j=0;j<b;j++){
				if(arr[k][j]=='A')
					max_ = max(max_, dp[k][j]);
			}
		}
		cout<<"Case "<<i<<": "<<((max_==INT_MIN)?0:(max_+1))<<endl;	
		
	}
	return 0;
}