#include <bits/stdc++.h>

using namespace std;
bool primes[1000505];
int arr[1000000];
//0-->K

int whoW(int n){
	// int w = 0;

	// if(n==1)
	// {
	// 	arr[n] = 0;
	// 	return arr[n];
	// }

	// if(arr[n]!=-1)
	// 	return arr[n];
	
	// for(int i=1;i<n;i++)
	// 	{
	// 		if(primes[i]){
	// 			if(n%i==0){
	// 				if(arr[n-i]==-1)
	// 					{
	// 						if(whoW(n-i)==0){
	// 							return arr[n] = 1;
	// 						}
	// 						else 
	// 							continue;
	// 					}
	// 				else if(arr[n-i]==0){
	// 					return arr[n] = 1;
	// 				}
	// 				else if(arr[n-i]==1)
	// 					continue;	
	// 			}
	// 		}
	// 	}
	// return arr[n] = 0;
	if(n%2==0)
		return 1;
	
	if(primes[n]){
		return 0;
	}
}

int main(){
	int t;
	cin>>t;
	memset(arr, -1, sizeof(arr));
	memset(primes, true, sizeof(primes));

	for(int i=2;i*i<=1000500;i++){
		if(primes[i]==true){
			for(int j = i*2;j<=1000500;j+=i){
				primes[j] = false;
			}
		}
	}

	while(t--){
		int n;
		cin>>n;

		if(whoW(n)==1)
			cout<<"Thankyou Shaktiman"<<endl;
		else
			cout<<"Sorry Shaktiman"<<endl;
	}
	return 0;
}
