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

#include "stdio.h"  
  
void towers(int,char,char,char);  
  
void towers(int n,char frompeg,char topeg,char auxpeg)  
    {   
      if(n==1)  
        { printf("%c %c\n",frompeg,topeg);  
          return;  
        }  
        
      towers(n-1,frompeg,auxpeg,topeg);  
      
      printf("%c %c\n",frompeg,topeg);  
        
      towers(n-1,auxpeg,topeg,frompeg);  
    }  
int main()  
    { int n;  
      
        freopen("qubits.in","r",stdin);  
        freopen("qubits.out","w",stdout);  
          
        scanf("%d",&n);  
  
      towers(n,'A','C','B');  
      return 0;  
    }  
