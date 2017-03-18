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
  
int main()  
{  
    int n, i;   
    double A, B;  
    double ans, maxsize=0, maxspeed=0;  
  
    freopen("downloads.in","r",stdin);  
    freopen("downloads.out","w",stdout);  
  
    scanf("%d", &n);  
      
    for(i=0; i<n; i++)  
    {  
        scanf("%lf %lf", &A, &B);  
        maxspeed+=A;  
        maxsize+=A*B;  
    }  
    ans=maxsize/maxspeed;  
        printf("%.0lf\n", ans);  
  
    return 0;  
}  
