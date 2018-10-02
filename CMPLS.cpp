#include <bits/stdc++.h>
using namespace std;

bool allsame(int row, int dt[100][100], int col){
	for(int i=1;i<=col;i++){
		if(dt[row][i]==dt[row][i-1])
			continue;
		else{
			return false;
		}
	}
	return true;
}

int main(){
	int n;
	cin>>n;
	while(n--){
		int a,b;
		int dt[100][100] = {0};
		cin>>a>>b;
		for(int i=0;i<a;i++){
			cin>>dt[0][i];
		}
		int row=0,col=a-1;
		while(!allsame(row,dt,col)){
			row++;
			col--;
			for(int i=col;i>=0;i--){
				dt[row][i] = dt[row-1][i+1]-dt[row-1][i];
			}
		}

		// for(int i=0;i<=row;i++){
		// 	for(int j=0;j<a;j++)
		// 		cout<<dt[i][j]<<" ";
		// 	cout<<endl;
		// }
		// cout<<col<<endl;
		
		for(int k=a;k<a+b;k++){
			int res = 0;
			for(int i=0,j=k-1;	i<=row&&j>=col; i++,j--){
				res += dt[i][j];
			}
			dt[0][k] = res;

			for(int i=1,j=k-1;i<=row&&j>col;i++,j--){
				dt[i][j] = dt[i-1][j+1]-dt[i-1][j];
			}
		}
		
		// for(int i=0;i<=row;i++){
		// 	for(int j=0;j<a+b;j++)
		// 		cout<<dt[i][j]<<" ";
		// 	cout<<endl;
		// }

		for(int i=a;i<a+b;i++)
			cout<<dt[0][i]<<" ";
		cout<<endl;
	}
	return 0;
}