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
  
int main()  
{  
    int times=0, timem=0, timeh=0;  
    FILE *in, *out;  
  
    in=fopen("time.in","r");  
      
    fscanf(in,"%d:%d:%d",&timeh, &timem, &times);  
  
    fclose(in);  
  
    timeh=timeh*2;  
  
    if(timem*2>=60)  
    {  
        timem=(timem*2) - 60;  
        timeh++;  
    }  
  
    else  
        timem=timem*2;  
  
    if(times*2>=60)  
    {  
        times=(times*2) - 60;  
        timem++;  
    }  
  
    else  
        times=times*2;  
  
    out=fopen("time.out","w");  
      
    fprintf(out,"%d:%02d:%02d\n", timeh, timem, times);  
    fclose(out);  
      
    return 0;  
}  
