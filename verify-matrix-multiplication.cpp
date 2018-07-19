#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
	Given 3 nxn square matrices A,B and D as input,
	we need to verify if indeed AB = D (Matrix Multiplication).

	For this, we shall generate a random nx1 (say x) column vector
	containing only 0 or 1.

	ABx = Dx => (AB-D)x = 0
	Bx = y;
	Ay = w;
	Dx = z;

	Test fails with at most 1/2 prob. Accuracy can be improved by 
	increasing number of trials.
*/

int main(){
	srand(time(NULL));
	ll n;
	cin>>n;
	ll A[n][n];
	ll B[n][n];
	ll D[n][n];
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin>>A[i][j];

	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin>>B[i][j];

	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin>>D[i][j];

	ll x[n],y[n],z[n],w[n];
	int trials = 100;
	while(trials--){
		for(int i=0;i<n;i++)
			x[i] = rand()%2;
		for(int i=0;i<n;i++){
			y[i] = 0;
			for(int j=0;j<n;j++)
				y[i] += B[i][j]*x[j];
		}

		for(int i=0;i<n;i++){
			w[i] = 0;
			for(int j=0;j<n;j++)
				w[i] += A[i][j]*y[j];
		}		

		for(int i=0;i<n;i++){
			z[i] = 0;
			for(int j=0;j<n;j++)
				z[i] += D[i][j]*x[j];
		}

		for(int i=0;i<n;i++)
			if(z[i]!=w[i]){
				cout<<"Matrix Multiplication is incorrect!\n";
				return 0;
			}
	}
	
	cout<<"Matrix Multiplication is perfect!\n";
}