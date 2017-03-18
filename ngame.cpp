/*
****************************************************************
****************************************************************
-> Coded by Stavros Chryselis				   
-> Visit my github for more solved problems over multiple sites 
-> https://github.com/StavrosChryselis			  
-> Feel free to email me at stavrikios@gmail.com	
****************************************************************
****************************************************************
*/

#include <stdio.h>
#include <algorithm>

using namespace std;

int A[100];
int dp[100][100];
int N;
int sum;

int main()
{
	int i, j, L;

	freopen("ngame.in","r",stdin);
	freopen("ngame.out","w",stdout);

	scanf("%d", &N);

	scanf("%d %d", &A[0], &A[1]);
	sum+=A[0];
	sum+=A[1];
	dp[0][0]=A[0];
	dp[1][1]=A[1];
	dp[0][1]=max(A[0], A[1]);

	for(i=2; i<N; i++)
	{
		scanf("%d", &A[i]);
		sum+=A[i];
		dp[i][i]=A[i];
		dp[i-1][i]=max(A[i-1], A[i]);
		//dp[i-2][i]=max(dp[i-2][i-1]+A[i], dp[i-1][i]+A[i-2]);
	}

	for(L=3; L<=N; L++)
		for(i=0; i<=N-L; i++)
		{
			j=i+L-1;
			dp[i][j]=max(min(dp[i+1][j-1], dp[i+2][j])+A[i], min(dp[i+1][j-1], dp[i][j-2])+A[j]);
		}
	printf("%d %d\n", dp[0][N-1], sum-dp[0][N-1]);
	
	return 0;
}
