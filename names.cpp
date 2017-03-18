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
  
using namespace std;  
  
char strings[1000][20], strings2[1000][20];  
  
string temp;  
set<string> A;  
set<string>::iterator ii;  
  
char *get(char *lexi)  
{  
    int len, i;  
    char buff[20], c;  
  
    len=strlen(lexi);  
  
    for(i=0; i<len; i++)  
    {  
        c=lexi[len-1];  
        memmove(lexi+1,lexi,len-1);  
        lexi[0]=c;  
  
        A.insert(lexi);  
    }  
    ii=A.begin();  
    temp=*ii;  
    strcpy(buff,temp.c_str());  
    return buff;  
}  
  
int main()  
{  
    int n, i=0, counter=0;  
    char buff[20];  
  
    freopen("names.in","r",stdin);  
    freopen("names.out","w",stdout);  
  
    scanf("%d", &n);  
  
    for(i=0; i<n; i++)  
    {  
        scanf("%s", strings[i]);  
        strcpy(buff,strings[i]);  
        strcpy(strings2[i],get(buff));  
    }  
  
    strcpy(buff,strings2[0]);  
    counter=0;  
    for(i=1; i<n; i++)  
        if(strcmp(strings2[i],buff)<0)  
        {  
            strcpy(buff,strings2[i]);  
            counter=i;  
        }  
  
    printf("%s\n", strings[counter]);  
  
    return 0;  
}  
