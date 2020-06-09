#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll t, n, m, a, b, q;
bool clr[1005][1005];

bool fun( int x, int y, int k, bool prevclr){
	if( ( x > 0 and clr[ x - 1 ][y] != prevclr ) or 
		( x < n - 1 and clr[ x + 1 ][y] != prevclr ) or
		( y < m - 1 and clr[x][ y + 1 ] != prevclr ) or
		( y > 0 and clr[x][ y - 1 ] != prevclr )){
		if( k % 2 )
			return 1 - prevclr;
		else
			return prevclr;
	}
	if( fun( x - 1, y, k - 1, clr[x][y]) != prevclr or
		fun( x + 1, y, k - 1, clr[x][y]) != prevclr or
		fun( x, y - 1, k - 1, clr[x][y]) != prevclr or
		fun( x, y + 1, k - 1, clr[x][y]) != prevclr )
		return 1 - prevclr;
	return prevclr;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> t;
    for( int i = 0 ; i < n ; i++ )
    	for( int j = 0 ; j < m ; j++ )
    		cin >> clr[i][j];
	while( t-- ){
		cin >> a >> b >> q;
		cout << fun( a - 1, b - 1, q, clr[a][b]) << endl;
	}
	return(0);
}