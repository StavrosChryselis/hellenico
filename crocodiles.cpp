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
#include <vector>  
  
using namespace std;  
  
struct croc  
{  
    long year;  
    bool alive;  
};  
  
bool sortbyyear(const croc &a, const croc &b)  
{  
    if(a.year!=b.year)  
        return a.year<b.year;  
  
    return a.alive<b.alive;  
}  
  
vector<croc> A;  
vector<croc>::iterator ii;  
  
int main()  
{  
    long n, i;  
    int counter=0;  
    long max=0;  
    croc TEMP;  
  
    freopen("crocodiles.in","r",stdin);  
    freopen("crocodiles.out","w",stdout);  
  
    scanf("%i", &n);  
  
    for(i=0; i<n; i++)  
    {  
        scanf("%i", &TEMP.year);  
        TEMP.alive=1;  
        A.push_back(TEMP);  
  
        scanf("%i", &TEMP.year);  
        TEMP.alive=0;  
        A.push_back(TEMP);  
    }  
      
    sort(A.begin(),A.end(),&sortbyyear);  
  
    for(ii=A.begin(); ii!=A.end(); ii++)  
    {  
        TEMP=*ii;  
        if(TEMP.alive==0)  
            counter--;  
        else  
        {  
            counter++;  
            if(max<counter)  
                max=counter;  
        }  
  
    }  
  
    printf("%i\n", max);  
  
    return 0;  
}  
