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
  
int A[1000];  
  
using namespace std;  
  
int main()  
{  
    int i, j, one, two, three, out, n, s=0;  
  
    one=two=three=0;  
    out=0;  
  
    freopen("sort3.in","r",stdin);  
    freopen("sort3.out","w",stdout);  
  
    scanf("%d", &n);  
  
    for(i=0; i<n; i++)  
    {  
        scanf("%d", &A[i]);  
  
        switch(A[i])  
        {  
            case 1: one++; break;  
            case 2: two++; break;  
            case 3: three++; break;  
        }  
    }  
    i=0;  
  
    for(i=one+two; i<n; i++)  
        if(A[i]!=3)  
        {  
            if(A[i]==1)  
            {  
                for(j=0; j<one; j++)  
                    if(A[j]==3)  
                    {  
                        swap(A[i],A[j]);  
                        out+=2;  
                        break;  
                    }  
            }  
            else if(A[i]==2)  
                for(j=one; j<one+two; j++)  
                    if(A[j]==3)  
                    {  
                        swap(A[i],A[j]);  
                        out+=2;  
                        break;  
                    }  
        }  
  
    for(i=one+two; i<n; i++)  
        if(A[i]!=3)  
        {  
            if(A[i]==1)  
            {  
                for(j=one; j<one+two; j++)  
                    if(A[j]==3)  
                    {  
                        swap(A[i],A[j]);  
                        out+=2;  
                        break;  
                    }  
            }  
            else if(A[i]==2)  
                for(j=0; j<one; j++)  
                    if(A[j]==3)  
                    {  
                        swap(A[i],A[j]);  
                        out+=2;  
                        break;  
                    }  
        }  
  
      
    for(i=0; i<one; i++)  
        if(A[i]!=1)  
            out++;  
  
    for(i=one; i<one+two; i++)  
        if(A[i]!=2)  
            out++;  
  
  
    printf("%d\n", out/2);  
  
    return 0;  
}  
