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
#include <string.h>  
#include <iostream>  
#include <set>  
#include <string>  
  
int X, Y;  
char strings[10002][42];  
  
using namespace std;  
  
int main()  
{  
    int n, i, p=0, j;  
    char s;  
    string temp;  
    set<string> A;  
    set<string>::iterator ii;  
  
    freopen("boat.in","r",stdin);  
    freopen("boat.out","w",stdout);  
  
    scanf("%d", &n);  
  
    for(i=0; i<n; i++)  
    {  
        scanf("%d %d", &X, &Y);  
        p-=X;  
        for(j=0; j<Y-1; j++)  
        {  
            scanf("%s ", strings[p]);  
            p++;  
        }  
  
        scanf("%s\n", strings[p]);  
        p++;  
  
    }  
  
    for(i=0; i<p; i++)  
        A.insert(strings[i]);  
  
    for(ii=A.begin(); ii!=A.end(); ii++)  
    {  
        temp=*ii;  
        printf("%s\n", temp.c_str());  
    }  
    return 0;  
}  
