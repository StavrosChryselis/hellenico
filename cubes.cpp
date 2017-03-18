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
  
int A[100000];  
  
int main()  
{  
    int n, k, counter=2, stock, i, ok=1;  
  
    freopen("cubes.in","r",stdin);  
    freopen("cubes.out","w",stdout);  
  
    scanf("%d %d", &n, &k);  
  
    A[0]=k-1;  
    stock=n-k+1;  
  
    while(ok)  
    {  
        if(stock-counter>0)  
        {  
            for(i=0; i<counter; i++)  
            {  
                A[i]++;  
                stock--;  
            }  
        }  
        else  
        {  
            i=0;  
            while(stock>0)  
            {  
                A[i]++;  
                i++;  
                stock--;  
            }  
            ok=0;  
        }  
        if(A[counter-1]==k)  
            counter++;  
    }  
  
    printf("%d\n", A[0]);  
  
    return 0;  
}  
