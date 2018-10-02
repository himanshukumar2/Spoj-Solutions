#include<bits/stdc++.h>
using namespace std;
#define endl "\n"

int dp[550][550];

int KS(int bdg, vector<int> fee, vector<int> fun, int n){
	if(dp[bdg][n]!=-1){
		//cout<<"dp["<<bdg<<"]["<<n<<"]"<<"\t"<<dp[bdg][n]<<endl;	
		return dp[bdg][n];
	}

	if(n==0||bdg==0){
		dp[bdg][n] = 0;
		//cout<<"dp["<<bdg<<"]["<<n<<"]"<<"\t"<<dp[bdg][n]<<endl;
		return dp[bdg][n];
	}

	if(fee[n-1]>bdg){
		dp[bdg][n] = KS(bdg, fee, fun, n-1);
		//cout<<"dp["<<bdg<<"]["<<n<<"]"<<"\t"<<dp[bdg][n]<<endl;
		return dp[bdg][n];
	}

	dp[bdg][n] = max(KS(bdg, fee, fun, n-1), fun[n-1] + KS(bdg-fee[n-1], fee, fun, n-1));
	//cout<<"dp["<<bdg<<"]["<<n<<"]"<<"\t"<<dp[bdg][n]<<endl;
	return dp[bdg][n];
}


int main()
{
	ios_base:: sync_with_stdio(false); cin.tie(0);
	int t;
	int bdg, n;
	while((cin>>bdg>>n) && bdg!=0 && n!=0){
		memset(dp, -1 , sizeof dp);
		vector<int > fun(n,0),fee(n,0);

		for(int i=0;i<n;i++){
			cin>>fee[i]>>fun[i];
		}

		//cout<<KS(W, wt, cs, n)<<endl;

		for(int i=1;i<=bdg;i++)
			KS(i, fee, fun, n); //find the maxiumum fun

		int price = 0;

		int cost = (dp[bdg][n]==-1)?0:dp[bdg][n];

		
		bool found = false;;

		for(int i=1;i<=bdg;i++){
			for(int j=1;j<=n;j++)
			if(dp[i][j]==cost){
				price = i;
				found = true;
				break;		
			}
			if(found)
				break;
		}

		cout<<price<<" "<<cost<<endl;
		
		// for(int i=0;i<=n;i++){
		// 	for(int j=0;j<=W;j++)
		// 		if(dp[i][j]==cost){
		// 			weight = j;
		// 			break;
		// 		}
		// }

	}
	return 0;
}