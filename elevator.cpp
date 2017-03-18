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
#include <iostream>  
#include <algorithm>  
  
using namespace std;  
  
  
int A[100000];  
  
int main()  
{  
    int i, n, max1=0, max2=0, sum, tries=0, max;  
  
    freopen("elevator.in","r",stdin);  
    freopen("elevator.out","w",stdout);  
  
    scanf("%d", &n);  
  
    for(i=0; i<n; i++)  
        scanf("%d", &A[i]);  
  
    sort(A, A+n);  
      
    if(n%2==1)  
    {  
        max1=A[n-1];  
        n--;  
  
        for(i=0; i<=n/2; i++)  
        {  
            sum=A[i]+A[n-1-i];  
  
            if(sum>max2)  
                max2=sum;  
        }  
  
        if(max1>max2)  
            max=max1;  
  
        else  
            max=max2;  
          
        tries++;  
    }  
  
    else  
    {  
        for(i=0; i<=n/2; i++)  
        {  
            sum=A[i]+A[n-1-i];  
  
            if(sum>max2)  
                max2=sum;  
        }  
        max=max2;  
    }  
  
    tries+=n/2;  
  
    printf("%d %d\n", tries, max);  
  
    return 0;  
}  
