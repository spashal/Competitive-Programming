#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll t, n, r, z, m;
char s[11][11];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
	while( t-- ){
		cin >> n >> m;
		int y = 0;
		z = 0;
		for( int i = 0 ; i < n ; i++ )
			cin >> s[i];
		char s1[11], s2[11];
		strcpy( s1, s[0]);
		strcpy( s2, s[0]);
		for( int i = 1 ; i < n ; i++ ){
			r = 0;
			for( int j = 0 ; j < n ; j++ )
				if( s[i][j] != s1[j] ){
					r++;
				}
			int e = 0;
			if( r > 2 )
				z = 1;
			else if( r == 2 ){
				if( y == 0 ){
					for( int j = 0 ; j < n ; j++ )
						if( s[i][j] != s1[j] ){
							if( e == 0 ){
								s1[j] = s[i][j];
								e++;
							}
							else{
								s2[j] = s[i][j];
							}
						}
					y = i;
					break;
				}
			}
			else if( r == 1 ){
				strcpy( s2, s[i]); //take care here
			}
		}
		r = 0;
		int u = 0;
		for( int i = y + 1 ; i < n ; i++ ){
			r = 0;
			u = 0;
			for( int j = 0 ; j < n ; j++ ){
				if( s[i][j] != s1[j] )
					r++;
				if( s[i][j] != s2[j] )
					u++;
			}
			if( r > 1 ){
				s1[0] = 'A';
				s1[1] = 'A';
			}
			if( u > 1 ){				
				s2[0] = 'A';
				s2[1] = 'A';
			}
			if( r > 1 and u > 1 )
				z = 1;
		}
		if( z == 1 )
			cout << "-1" << endl;
		else if( s1[0] != 'A' and s1[1] != 'A' )
			cout << s1 << "*" << endl;
		else
			cout << s2 << "&" << endl;
	}
	return(0);
}