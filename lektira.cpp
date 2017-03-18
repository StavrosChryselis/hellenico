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

#include <algorithm>  
#include <iostream>  
#include <string>  
  
using namespace std;  
  
int main( void ) {  
   string s;  
  
   freopen("lektira.in","r",stdin);  
   freopen("lektira.out","w",stdout);  
   cin >> s;  
  
    
  
   string ret = "~";  
  
   for( int i = 1; i < s.size(); ++i ) {  
      for( int j = i+1; j < s.size(); ++j ) {  
         string a = s.substr( 0, i );  
         string b = s.substr( i, j-i );  
         string c = s.substr( j );  
  
         reverse( a.begin(), a.end() );  
         reverse( b.begin(), b.end() );  
         reverse( c.begin(), c.end() );  
  
         string t = a+b+c;  
  
         if( t < ret ) ret = t;  
      }  
   }  
  
   cout << ret << endl;  
  
   return 0;  
}  
