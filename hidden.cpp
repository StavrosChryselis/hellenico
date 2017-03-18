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
#include "hiddenlib.h"  
  
int main()  
{  
    float n, x, y;  
  
    n=getN();  
  
    x=0;  
    y=n;  
  
    while(compare(x,y)!=0)  
    {  
        if(compare(x,y)==1)  
            y=(x+y)/2;  
        else if(compare(x,y)==-1)  
            x=(x+y)/2;  
    }  
      
    ishidden((x+y)/2);  
  
    return 0;  
  
}  
