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
    double mass;  
    double volume;  
    double value;  
}r;  
  
bool sortbyvalue(const r &a, const r &b)  
{  
        return a.value>b.value;  
}  
  
vector<r> rocks;  
double N, Z;  
double curr_volume, max_mass;  
  
inline bool exec(r temp)  
{  
    if(temp.volume+curr_volume<=Z)  
    {  
        max_mass+=temp.mass;  
        curr_volume+=temp.volume;  
        return 1;  
    }  
  
    else  
    {  
        max_mass+=temp.value*(Z-curr_volume);  
        return 0;  
    }  
  
    return 0;  
}  
  
int main()  
{  
    int i;  
  
  
  
    freopen("stones.in","r",stdin);  
    freopen("stones.out","w",stdout);  
  
    scanf("%lf %lf", &N, &Z);  
    rocks.resize(N);  
  
    for(i=0; i<N; i++)  
    {  
        scanf("%lf %lf", &rocks[i].volume, &rocks[i].mass);  
        rocks[i].value=rocks[i].mass/rocks[i].volume;  
    }  
  
    sort(rocks.begin(), rocks.end(), sortbyvalue);  
    i=0;  
  
    while(i<N && exec(rocks[i]))  
        i++;  
      
    printf("%.3lf\n", max_mass);  
  
    return 0;  
}  
