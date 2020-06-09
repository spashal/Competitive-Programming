#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll t, n;
bool a[55][55], b[55][55];

void fun( int i, int j){
	// cout << i << " * " << j << endl;
	if( b[i][j] )
		return;
	b[i][j] = true;
	if( ( i - 1 ) >= 0 and a[i-1][j] )
		fun(i-1,j);
	// if( ( i + 1 ) < n - 1 and a[i+1][j] )
	// 	fun(i+1,j);
	if( (j-1) >= 0 and a[i][j-1] )
		fun(i,j-1);
	// if( (j+1) < n - 1 and a[i][j+1] )
	// 	fun(i,j+1);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
	while( t-- ){
		cin >> n;
		char s[55];
		int z = 0;
		for( int i = 0 ; i < n ; i++ ){
			cin >> s;
			for( int j = 0 ; j < n ; j++ ){
				if( s[j] == '0' )
					a[i][j] = false;
				else
					a[i][j] = true;
				// cin >> a[i][j];
				// cout << a[i][j] << "*";
				b[i][j] = false;
			}
		}
		for( int i = 0 ; i < n ; i++ ){
			if( a[n-1][i] )
				fun(n-1,i);
			if( a[i][n-1] )
				fun(i,n-1);
		}
		for( int i = 0 ; i < ( n - 1) ; i++ )
			for( int j = 0 ; j < (n-1) ; j++ )
				if( a[i][j] and !b[i][j] ){
					z = 1;
					// cout << i << " " << j << " " << a[i][j] << " " << b[i][j] << endl;
				}
		if( z == 1 )
			cout << "NO" << endl;
		else
			cout << "YES" << endl;
	}
	return(0);
}