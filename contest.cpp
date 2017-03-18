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
#include <malloc.h>  
  
typedef struct c  
{  
    int num;  
    int name;  
    struct c *above;  
}c;  
  
c *con[1000], *temp;  
  
int A[1000];  
  
int main()  
{  
    int i, n, a, b, c, sum=0, j, max=0;  
  
    freopen("contest.in","r",stdin);  
    freopen("contest.out","w",stdout);  
  
    scanf("%d", &n);  
  
    while(!feof(stdin))  
    {  
        scanf("%d %d %d", &a, &b, &b);  
        A[a]=1;  
    }  
  
    rewind(stdin);  
  
    for(i=0; i<=n; i++)  
        con[i]=(struct c *)malloc(sizeof(struct c));  
  
    scanf("%d", &n);  
  
    while(!feof(stdin))  
    {  
        scanf("%d %d %d", &a, &b, &c);  
        con[b]->above=con[a];  
        con[b]->num=c;  
    }  
  
    for(i=1; i<=n; i++)  
        con[i]->name=i;  
  
    con[1]->above=NULL;  
    con[1]->num=0;  
  
    for(i=1; i<=n; i++)  
    {  
        if(A[i]==0)  
        {  
            sum=0;  
            for(j=i; con[j]->above!=NULL; j=con[j]->above->name)  
                sum+=con[j]->num;  
            if(sum>max)  
                max=sum;  
        }  
    }  
    printf("%d\n", max);  
  
    return 0;  
}  
