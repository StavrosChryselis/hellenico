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
  
int often[4];  
char str[1000];  
char per[1000];  
int n, k;  
char tab[5];  
  
void destroy_often()  
{  
    int i;  
    for(i=0; i<4; i++)  
        often[i]=0;  
}  
  
  
void destroy_per()  
{  
    int i;  
    for(i=0; i<k; i++)  
        per[i]=0;  
}  
  
  
int get_max()  
{  
    int max;  
    int i;  
    int pos;  
  
  
    max=often[0];  
    pos=0;  
  
        for(i=0; i<4; i++)  
            if(often[i]>max)  
            {  
                max=often[i];  
                pos=i;  
            }  
    return pos;  
}  
  
  
int main()  
{  
    int p, pmax;  
    int i, pos, j, k;  
    int min=99999;  
    int counter=0;  
      
      
      
    tab[0]='A';  
    tab[1]='G';  
    tab[2]='C';  
    tab[3]='T';  
    tab[4]='\0';  
  
    freopen("dna.in","r",stdin);  
    freopen("dna.out","w",stdout);  
  
  
    scanf("%d %d", &n, &k);  
    scanf("%s", str);  
  
  
    p=k;  
    pmax=p;  
  
    while(p>1)  
    {  
        for(j=0; j<p; j++)  
        {  
            for(i=j; i<n; i+=p)  
            {  
                if(str[i]=='A')  
                    often[0]++;  
                      
                else if(str[i]=='G')  
                    often[1]++;  
                      
                else if(str[i]=='C')  
                    often[2]++;  
                      
                else  
                    often[3]++;  
            }  
              
            pos=get_max();  
              
            for(i=j; i<n; i+=p)  
                if(str[i]!=tab[pos])  
                    counter++;  
  
            destroy_often();  
              
        }  
        p--;  
        if(counter<min)  
            min=counter;  
        counter=0;  
    }  
    if(pmax==1)  
    {  
        for(i=0; i<n; i++)  
        {  
            if(str[i]=='A')  
                often[0]++;  
                      
            else if(str[i]=='G')  
                often[1]++;  
                      
            else if(str[i]=='C')  
                often[2]++;  
                      
            else  
                often[3]++;  
        }  
        pos=get_max();  
        for(i=0; i<n; i++)  
            if(str[i]!=tab[pos])  
                    counter++;  
        min=counter;  
    }  
  
    printf("%d\n", min);  
    return 0;  
}  
