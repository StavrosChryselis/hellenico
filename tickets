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
  
typedef struct  
{  
    int num;  
    int dis;  
}B;  
  
int main()  
{  
    int i, n, counter=0;  
    float val=0, pos_val=0;  
    B A[5];  
  
    freopen("tickets.in","r",stdin);  
    freopen("tickets.out","w",stdout);  
  
    scanf("%d", &n);  
      
      
    for(i=1; i<=4; i++)  
    {  
        scanf("%d", &A[i].num);  
          
        if(A[i].num<n)  
            counter=i;  
    }  
    A[0].num=0;  
  
    A[0].dis=0;  
    A[1].dis=10;  
    A[2].dis=20;  
    A[3].dis=30;  
    A[4].dis=50;  
      
    val=(float)n*10-(A[counter].dis*n/10);  
  
    for(i=counter+1; i<=4; i++)  
    {  
        pos_val=(float)A[i].num*10-(A[i].dis*A[i].num/10);  
        if(pos_val<val)  
            val=pos_val;  
    }  
  
    printf("%.f\n", val);  
  
    return 0;  
  
}  
