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


#include <cstdio>  
  
#define maxn 101  
  
int n, k, grid[maxn][maxn];  
  
void load() {  
    scanf( "%d%d", &n, &k );  
    for( int i = 0; i < k; ++i ) {  
        int r, s;  
        scanf( "%d%d", &r, &s );  
        grid[r-1][s-1] = 1;  
    }     
}  
  
int sum( int l, int r, int c ) {   
    int ret = 0;  
    for( int i = l; i < r; ++i ) ret += grid[i][c];  
    return ret;  
}  
      
int solve() {  
    int ret = n*n;  
    for( int i = 0; i < n; ++i )  
        for( int j = i+1; j <= n; ++j ) {  
            if( k%(j-i) ) continue;   
            int s = k/(j-i), rsum = 0;  
              
            if( s > n ) continue;  
              
            for( int q = 0; q < s; ++q ) rsum += sum( i, j, q );  
              
              
            for( int q = s; q <= n; ++q ) {   
                if( ret > k-rsum ) ret = k-rsum;  
                  
                rsum -= sum( i, j, q-s );   
                rsum += sum( i, j, q );     
            }  
        }  
    return ret;  
}  
  
int main(void) {  
    freopen("nered.in","r",stdin);  
    freopen("nered.out","w",stdout);  
    load();  
    printf( "%d\n", solve() );  
    return 0;  
}  
