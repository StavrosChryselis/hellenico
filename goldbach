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
  
  
int A[1000000], B[1000000];  
  
int main()  
{  
    int i, j, n, p=2, counter=0;  
  
    freopen("goldbach.in","r",stdin);  
    freopen("goldbach.out","w",stdout);  
  
    scanf("%d", &n);  
  
    for(i=0; i<=n; i++)  
        A[i]=i;  
   
    while(p*p<=n)  
    {  
        for(i=p+p; i<=n; i=i+p)  
            A[i]=0;  
  
        p++;  
  
        while(A[p]==0)  
            p++;  
    }  
  
    for(i=2; i<n; i++)  
        if(A[i]!=0)  
        {  
            B[counter]=A[i];  
            counter++;  
        }  
  
    for(i=0; i<counter; i++)  
        for(j=i+1; j<counter; j++)  
            if((B[i]+B[j])==n)  
            {  
                printf("%d %d\n", B[i], B[j]);  
                return 0;  
            }  
      
    return 0;  
}  
