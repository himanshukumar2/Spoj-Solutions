#include<bits/stdc++.h>
using namespace std;
#define endl "\n"

int dp[3][1009][1009];

int my_func(int curr_pos, int h, int a){
	if(dp[curr_pos][h][a]!=-1)
		return dp[curr_pos][h][a];

	if(h<=0 || a<=0)
		return dp[curr_pos][0][0] = 0;

	if(curr_pos==0)
		return dp[curr_pos][h][a] = 1+max(my_func(1, h-5, a-10), my_func(2, h-20, a+5));
	else if(curr_pos==1)
		return dp[curr_pos][h][a] = 1+max(my_func(0, h+3, a+2), my_func(2, h-20, a+5));
	
	return dp[curr_pos][h][a] = 1+max(my_func(0, h+3, a+2), my_func(1,h-5, a-10));
}

int main()
{
	ios_base:: sync_with_stdio(false); cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		int h, a;
		cin>>h>>a;
		//0--> Air
		//1--> Water
		//2--> Fire

		memset(dp, -1, sizeof dp);
		
		int max_t = max(max(my_func(0, h,a), my_func(1, h, a)), my_func(2, h,a));
		cout<<max_t-1<<endl;
	}
	return 0;
}