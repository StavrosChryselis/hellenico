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
#include <string>  
#include <vector>  
#include <list>  
#include <iostream>  
#include <cstdlib>  
#include <sstream>  
  
using namespace std;  
  
string strM;  
float M;  
  
struct A  
{  
    vector<bool> used;  
    string M1;  
    int next;  
};  
  
list<A> work;  
  
void init()  
{  
    int i;  
    char buff[2];  
    A temp;  
  
    cin>>strM;  
    M=atoi(strM.c_str());  
      
    temp.used.resize(10);  
  
    for(i=0; i<strM.size(); i++)  
    {  
        buff[0]=strM[i];  
        buff[1]='\0';  
        temp.used[atoi(buff)]=1;  
    }  
      
    for(i=1; i<10; i++)  
    {  
        if(temp.used[i])  
            continue;  
        temp.next=i;  
        work.push_back(temp);  
    }  
          
      
}  
  
bool is_sol(string res, vector<bool> u)  
{  
    int i;  
    char buff[2];  
  
    for(i=0; i<res.size(); i++)  
    {  
        buff[0]=res[i];  
        buff[1]='\0';  
  
        if(u[atoi(buff)]==1)  
            return 0;  
        else  
            u[atoi(buff)]=1;  
    }  
  
    for(i=1; i<=9; i++)  
        if(u[i]==0)  
            return 0;  
    return 1;  
}  
  
inline string change(int number)  
{  
    ostringstream temp;  
    temp<<number;  
    return temp.str();  
}  
  
A solve()  
{  
    int i;  
    A curr;  
    //char buff1[2];  
    char buff2;  
    string buff1;  
    //char tempresult[10];  
    float M11;  
    string result;  
    float M2;  
  
    while(1)  
    {  
        curr=work.front();  
        work.pop_front();  
  
        //itoa(curr.next,buff1,10);  
        buff1=change(curr.next);  
        buff2=buff1[0];  
        curr.M1.push_back(buff2);  
        curr.used[curr.next]=1;  
          
        M11=atoi(curr.M1.c_str());  
  
        M2=M11*M;  
  
        //itoa((int)M2, tempresult, 10);  
        result=change(M2);  
  
        if(result.size()+strM.size()+curr.M1.size()>9)  
        {  
            curr.M1="0";  
            return curr;  
        }  
  
        if(is_sol(result, curr.used))  
            return curr;  
          
        for(i=1; i<=9; i++)  
        {  
            if(curr.used[i])  
                continue;  
  
            curr.next=i;  
            work.push_back(curr);  
        }  
    }  
}  
  
int main()  
{  
    float temp;  
  
    freopen("digits.in","r",stdin);  
    freopen("digits.out","w",stdout);  
  
    init();  
    temp=atoi(solve().M1.c_str());  
  
    if(temp!=0)  
        printf("%.0f %.0f\n", temp, temp*M);  
    else  
        printf("0\n");  
  
    return 0;  
}  
