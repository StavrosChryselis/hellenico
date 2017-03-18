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

#include <string>  
#include <stdio.h>  
#include <vector>  
#include <set>  
  
using namespace std;  
  
const char *perms[]={"0000","0001", "0010", "0100", "1000", "0011", "0101", "1001", "0110", "1010","1100","0111", "1011", "1101", "1110","1111"};  
vector<string> permutatio(perms, perms+16);  
set<string> answer;  
vector<int> ON, OFF;  
int N, C;  
  
void init()  
{  
    int temp;  
  
    scanf("%d", &N);  
    scanf("%d", &C);  
  
    if(C==1)  
    {  
        permutatio.erase(permutatio.begin()+5, permutatio.begin()+16);  
        permutatio.erase(permutatio.begin());  
    }  
  
    else if(C==2)  
    {  
        permutatio.erase(permutatio.begin()+11, permutatio.begin()+15);  
        permutatio.erase(permutatio.begin()+1, permutatio.begin()+5);  
        permutatio.erase(permutatio.begin()+15);  
    }  
  
    else if(C%2==1)  
    {  
        permutatio.erase(permutatio.begin()+15);  
        permutatio.erase(permutatio.begin()+5, permutatio.begin()+11);  
        permutatio.erase(permutatio.begin());  
    }  
    else if(C%2==0)  
    {  
        permutatio.erase(permutatio.begin()+11, permutatio.begin()+15);  
        permutatio.erase(permutatio.begin()+1, permutatio.begin()+5);  
    }  
  
    scanf("%d", &temp);  
    if(temp!=-1)  
        do  
        {  
            ON.push_back(temp);  
            scanf("%d", &temp);  
        }while(temp!=-1);  
  
    scanf("%d", &temp);  
    if(temp!=-1)  
        do  
        {  
            OFF.push_back(temp);  
            scanf("%d", &temp);  
        }while(temp!=-1);  
}  
bool correct(string A)  
{  
    int i;  
  
    for(i=0; i<ON.size(); i++)  
        if(A[ON[i]-1]!='1')  
            return 0;  
  
    for(i=0; i<OFF.size(); i++)  
        if(A[OFF[i]-1]!='0')  
            return 0;  
    return 1;  
}  
string d1(string A)  
{  
    int i;  
      
    for(i=0; i<N; i++)  
    {  
        if(A[i]=='0')  
            A[i]='1';  
        else if(A[i]=='1')  
            A[i]='0';  
    }  
  
    return A;  
}  
  
string d2(string A)  
{  
    int i;  
      
    for(i=1; i<N; i+=2)  
    {  
        if(A[i]=='0')  
            A[i]='1';  
        else if(A[i]=='1')  
            A[i]='0';  
    }  
  
    return A;  
}  
  
string d3(string A)  
{  
    int i;  
      
    for(i=0; i<N; i+=2)  
    {  
        if(A[i]=='0')  
            A[i]='1';  
        else if(A[i]=='1')  
            A[i]='0';  
    }  
  
    return A;  
}  
  
string d4(string A)  
{  
    int i;  
      
    for(i=0; i<N; i+=3)  
    {  
        if(A[i]=='0')  
            A[i]='1';  
        else if(A[i]=='1')  
            A[i]='0';  
    }  
  
    return A;  
}  
  
string proc(string diak, string A)  
{  
    if(diak[0]=='1')  
        A=d1(A);  
    if(diak[1]=='1')  
        A=d2(A);  
    if(diak[2]=='1')  
        A=d3(A);  
    if(diak[3]=='1')  
        A=d4(A);  
  
    return A;  
}  
  
int main()  
{  
    string arxiki, teliki;  
    int i;  
  
    freopen("lamps.in","r",stdin);  
    freopen("lamps.out","w",stdout);  
    init();  
    for(i=0; i<N; i++)  
        arxiki.push_back('1');  
    for(vector<string>::iterator ii=permutatio.begin(); ii!=permutatio.end(); ii++)  
    {  
        teliki=proc(*ii, arxiki);  
        if(correct(teliki))  
            answer.insert(teliki);  
    }  
  
    for(set<string>::iterator ii=answer.begin(); ii!=answer.end(); ii++)  
        printf("%s\n", (*ii).c_str());  
  
    return 0;  
}  
