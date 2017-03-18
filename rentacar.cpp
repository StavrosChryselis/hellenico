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
#include <vector>
#include <algorithm>

using namespace std;

typedef struct
{
	int name;
	float arxi;
	float telos;
}p;

vector<p> pelates;
int N;
int counter;

void init()
{
	int i;
	p temp;

	scanf("%d", &N);

	for(i=0; i<N; i++)
	{
		scanf("%d %f %f", &temp.name, &temp.arxi, &temp.telos);
		pelates.push_back(temp);
	}
}

bool sortbyend(const p &a, const p &b)
{
	if(a.telos!=b.telos)
			return a.telos<b.telos;
	else
		return a.arxi>b.arxi;
}

void solve()
{
	int i;
	float time=0;

	for(i=0; i<pelates.size(); i++)
	{
		if(pelates[i].arxi>=time)
		{
			counter++;
			time=pelates[i].telos;
		}
	}
}

int main()
{
	freopen("rentacar.in","r",stdin);
	freopen("rentacar.out","w",stdout);

	init();
	sort(pelates.begin(), pelates.end(), sortbyend);
	solve();
	
	printf("%d\n", counter);

	return 0;
}
