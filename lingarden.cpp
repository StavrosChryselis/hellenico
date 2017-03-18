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
#include <string.h>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

int N, MOD;
int memo[5][5][5][1000007];
string S;

int f(int h,  int highest, int lowest, int l)
{
	if(h>4 || h<0 || highest - lowest > 2)
		return 0;
	if(l == 0)
		return 1;
	if(memo[h][highest][lowest][l] != -1)
		return memo[h][highest][lowest][l];
	
	memo[h][highest][lowest][l] = f(h+1, max(highest, h + 1), lowest,l-1) + f(h-1, highest, min(lowest, h - 1),l-1);

	if(memo[h][highest][lowest][l] >= MOD)
		memo[h][highest][lowest][l] -= MOD;

	return memo[h][highest][lowest][l];
}

inline void init()
{
	scanf("%d", &N);
	scanf("%d", &MOD);
	cin>>S;

	memset(memo, -1, sizeof(memo));
}

int main()
{
	int sum = 0, h = 2, high = 2, low = 2;
	int i;

	freopen("lingarden.in","r",stdin);
	freopen("lingarden.out","w",stdout);

	init();
	
	for(i=0; i<S.length(); i++)
	{
		if(S[i] == 'L')
		{
			h++;
			high = max(high, h);
		}
		else
		{
			h++;
			sum += f(h, max(high, h), low,  N - i - 1);
			if(sum >= MOD)
				sum -= MOD;
			h-=2;
			low = min(low, h);
		}
	}

	printf("%d\n", sum + 1);
	return 0;
}
