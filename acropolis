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
#include <stdlib.h>  
#include <algorithm>  
#include <iostream>  
  
using namespace std;  
  
int A[1000], B[1000];  
  
int main()  
{  
    int i, n, counter=0;  
  
    freopen("acropolis.in","r",stdin);  
    freopen("acropolis.out","w",stdout);  
  
    scanf("%d", &n);  
  
    for(i=0; i<n; i++)  
        scanf("%d", &A[i]);  
  
    copy(A,A+n,B);  
    sort(B,B+n);  
  
    for(i=0; i<n; i++)  
    {  
        if(A[i]==1)  
            printf("1\n");  
        else  
        {  
            while(B[counter]==1)  
                counter++;  
            printf("%d\n", B[counter]);  
            counter++;  
        }  
    }  
    return 0;  
}  
