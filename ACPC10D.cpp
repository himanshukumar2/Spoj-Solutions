#include<bits/stdc++.h>
using namespace std;
#define endl "\n"

int arr[1000009][3];


int main()
{
	int n,i=0;
	while(scanf("%d", &n) && ++i && n!=0){
		memset(arr, 0, sizeof arr);

		for(int k=0;k<n;k++){
			for(int j=0;j<3;j++){
				scanf("%d", &arr[k][j]);
			}
		}

		//Initialization
		arr[0][2] += arr[0][1];
		arr[1][0] += arr[0][1];
		arr[1][1] += min(min(arr[0][1], arr[1][0]),arr[0][2]);
		arr[1][2] += min(min(arr[0][2], arr[0][1]), arr[1][1]);


		for(int k=2;k<n;k++){
			arr[k][0] += min(arr[k-1][0], arr[k-1][1]);
			arr[k][1] += min(min(min(arr[k-1][0], arr[k-1][1]), arr[k-1][2]),
							arr[k][0]);
			arr[k][2] += min(min(arr[k-1][2], arr[k-1][1]), arr[k][1]);
		}

		// for(int k=0;k<n;k++){
		// 	for(int j=0;j<3;j++){
		// 		printf("%d ", arr[k][j]);
		// 	}
		// 	cout<<"\n";
			
		// }

		cout<<i<<". "<<arr[n-1][1]<<endl;	
		
	}
	return 0;
}
